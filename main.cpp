#include <cstddef>
#include <iostream>

template< class T >
struct BiList {
  T val;
  BiList<T> * next;
  BiList<T> * prev;
};

template< class T >
BiList<T> * create(const T& val)
{
  BiList<T> * node = new BiList<T>{val, nullptr, nullptr};
  node->next = node;
  node->prev = node;
  return node;
}

template< class T >
BiList<T> * add(BiList<T> * node, const T& val)
{
  if (!node)
  {
    return nullptr;
  }
  BiList<T> * newNode = new BiList<T>{val, node, node->prev};
  node->prev->next = newNode;
  node->prev = newNode;
  return newNode;
}

template< class T >
BiList<T> * insert(BiList<T> * node, const T& val)
{
  if (!node)
  {
    return nullptr;
  }
  BiList<T> * newNode = new BiList<T>{val, node->next, node};
  node->next->prev = newNode;
  node->next = newNode;
  return newNode;
}

template< class T >
BiList<T> * cut(BiList<T> * head) noexcept
{
  if (!head)
  {
    return nullptr;
  }
  if (head->next == head)
  {
    delete head;
    return nullptr;
  }
  BiList<T> * newHead = head->next;
  head->prev->next = newHead;
  newHead->prev = head->prev;
  delete head;
  return newHead;
}

template< class T >
BiList<T> * erase(BiList<T> * node) noexcept
{
  if (!node || node->next == node)
  {
    return nullptr;
  }
  BiList<T> * after = node->next;
  node->next = after->next;
  after->next->prev = node;
  delete after;
  return node->next;
}

template< class T >
BiList<T> * clear(BiList<T> * head) noexcept
{
  if (!head)
  {
    return nullptr;
  }
  if (head->next == head)
  {
    delete head;
    return nullptr;
  }
  headf->prev->next = nullptr;
  BiList<T> * current = head;
  while (current)
  {
    BiList<T> * next = current->next;
    delete current;
    current = next;
  }
  return nullptr;
}

template< class T, class F >
F traverse(F f, BiList<T> * begin, BiList<T> * end)
{
  if (!begin)
  {
    return f;
  }
  BiList<T> * current = begin;
  f(current->val);
  current = current->next;
  while (current != end)
  {
    f(current->val);
    current = current->next;
  }
  return f;
}

template< class T >
BiList<T> * convert(const T* arr, size_t size)
{
  if (size == 0)
  {
    return nullptr;
  }
  BiList<T> * head = create(arr[0]);
  BiList<T> * current = head;
  for (size_t i = 1; i < size; ++i)
  {
    current = insert(current, arr[i]);
  }
  return head;
}

template< class T>
BiList< T > * find(BiList<T> * head, const T& val)
{
  if (!head)
  {
    return nullptr;
  }
  BiList<T> * current = head;
  if (current->val == val)
  {
    return current;
  }
  current = current->next;
  while (true)
  {
    if (current->val == val)
    {
      return current;
    }
    current = current->next;
    if (current == head)
    {
      break;
    }
  }
  return nullptr;
}

template< class T >
void printList(BiList<T> * head)
{
  if (!head)
  {
    return;
  }
  std::cout << head->val << " ";
  BiList<T> * current = head->next;
  while (current != head)
  {
    std::cout << current->val << " ";
    current = current->next;
  }
  std::cout << "\n";
}

int main()
{
  int arr[] = {1, 20, 53, 47, 18};
  size_t size = sizeof(arr) / sizeof(arr[0]);
  for (size_t i = 0; i < size; ++i)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";

  BiList< int > * head = convert(arr, size);
  printList(head);

  head = add(head, 5);
  printList(head);

  BiList<int> * num = find(head, 53);
  if (num)
  {
    insert(num, 10);
    printList(head);
  }

  head = cut(head);
  printList(head);

  num = find(head, 47);
  if (num)
  {
    erase(num);
    printList(head);
  }

  head = clear(head);
  return 0;
}
