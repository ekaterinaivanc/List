#include <cstddef>

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
  if (head->next == head)
  {
    delete head;
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
