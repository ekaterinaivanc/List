template< class T >
struct BiList {
  T val;
  BiList<T> * next;
  BiList<T> * prev;
};

template< class T>
BiList<T> * create(const T& val)
{
  BiList<T> * node = new BiList<T>{val, nullptr, nullptr};
  node->next = node;
  node->prev = node;
  return node;
}

template< class T>
BiList<T> * add (BiList<T> * node, const T& val)
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

template< class T>
BiList<T> * insert (BiList<T> * node, const T& val)
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
