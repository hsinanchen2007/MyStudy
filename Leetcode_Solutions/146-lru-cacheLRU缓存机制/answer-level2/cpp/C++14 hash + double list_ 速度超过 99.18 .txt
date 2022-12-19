其实思路大家都说得差不多了。使用 C++14 STL 实现时，可以用下面的一些小技巧进一步优化：
1. 在 hash 时，除了存 `value`，还可以顺带把 LRU 队列中对应节点的 `iterator` 使用 `tuple` 一并存了。这样可以使访问 LRU 队列达到$O(1)$;
2. LRU 队列直接使用 `list` 实现，非常鲁棒，判断元素是否为最近使用，只需将其 `iterator` 与 `begin()` 比较即可;

```C++
class LRUCache {
public:
  LRUCache(int capacity) : max_c(capacity), c(0) {}
  
  int get(int key) {
    if (reg.find(key) != reg.end()) {
      auto valReg = reg[key];
      auto val = std::get<0>(valReg);
      auto valP = std::get<1>(valReg);
      if (valP != lru_queue.begin()) {
        lru_queue.erase(valP);
        lru_queue.emplace_front(key);
        auto newValReg = make_tuple(val, lru_queue.begin());
        reg[key] = newValReg;
      }
      return val;
    } else {
      return -1;
    }
  }
  
  void put(int key, int value) {
    if (reg.find(key) != reg.end()) {
      auto valReg = reg[key];
      auto valP = std::get<1>(valReg);
      if (valP != lru_queue.begin()) {
        lru_queue.erase(valP);
        lru_queue.emplace_front(key);
      }
      auto newValReg = make_tuple(value, lru_queue.begin());
      reg[key] = newValReg;
    } else {
      lru_queue.emplace_front(key);
      auto newValReg = make_tuple(value, lru_queue.begin());
      reg[key] = newValReg;
      for (++c; c > max_c; --c) {
        auto finalK = lru_queue.back();
        reg.erase(finalK);
        lru_queue.pop_back();
      }
    }
  }

private:
  using key_type = int;
  using value_type = int;
  using it_type = list<key_type>::iterator;
  using reg_type = tuple<value_type, it_type>;

  unordered_map<key_type, reg_type> reg;
  list<key_type> lru_queue;
  int c, max_c;
};
```