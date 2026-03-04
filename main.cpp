#include "BiList.h"

int main()
{
  int arr[] = {1, 20, 53, 47, 18};
  size_t size = sizeof(arr) / sizeof(arr[0]);
  std::cout << "Исходный массив:" << "\n";
  for (size_t i = 0; i < size; ++i)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";

  BiList< int > * head = convert(arr, size);
  std::cout << "Список:" << "\n";
  printList(head);

  head = add(head, 5);
  std::cout << "Добавление 5 в начало:" << "\n";
  printList(head);

  BiList<int> * num = find(head, 53);
  if (num)
  {
    insert(num, 10);
    std::cout << "Добавление 10 после 53:" << "\n";
    printList(head);
  }

  head = cut(head);
  std::cout << "Удаление начала:" << "\n";
  printList(head);

  num = find(head, 47);
  if (num)
  {
    erase(num);
    std::cout << "Удаление после 47:" << "\n";
    printList(head);
  }

  head = clear(head);
  return 0;
}
