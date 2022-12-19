哈希表存key到链表节点的映射
十字链表，横向存值，纵向存key
1. 当一个key的值增加1的时候，将其从当前纵向列表移除，加入到下一个链表之中（可能需要插入新的纵向链表）；若为新建key，则在横向链表头插入新的纵向链表；更新哈希表。
2. 当一个key的值减少1的时候，将其从当前纵向列表移除；若值非0，则将其并加入到前一个链表之中（可能需要插入新的纵向链表）；更新哈希表。

详细代码如下：
```
class AllOne {
  typedef string key_t;
  typedef int val_t;
  typedef list<key_t> keylist_t;
  typedef list<pair<val_t, keylist_t>> vallist_t;
  typedef keylist_t::iterator keyiter_t;
  typedef vallist_t::iterator valiter_t;
 protected:
  vallist_t vallist;
  std::unordered_map<key_t, pair<valiter_t, keyiter_t>> keymap;
 public:
  AllOne() { }

  void inc(string key) {
    auto it = keymap.find(key);
    valiter_t vit;
    keyiter_t eit;
    if (it == keymap.end()) {
      if (vallist.empty() || vallist.front().first != 1)
        vit = vallist.insert(vallist.begin(), make_pair(1, keylist_t()));
      else
        vit = vallist.begin();
      eit = vit->second.insert(vit->second.begin(), key);
      keymap[key] = make_pair(vit, eit);
    } else {
      vit = it->second.first;
      eit = it->second.second;
      auto val = vit->first + 1;
      auto nvit = next(vit);
      if (nvit == vallist.end() || nvit->first != val)
        nvit = vallist.insert(nvit, make_pair(val, keylist_t()));
      auto neit = nvit->second.insert(nvit->second.begin(), *eit);
      vit->second.erase(eit);
      if (vit->second.empty())
        vallist.erase(vit);
      it->second = make_pair(nvit, neit);
    }
  }

  void dec(string key) {
    valiter_t vit, pvit;
    keyiter_t eit, peit;
    auto it = keymap.find(key);
    if (it == keymap.end()) return;
    vit = it->second.first;
    eit = it->second.second;
    auto val = vit->first - 1;
    if (val) {
      if (vit == vallist.begin() || prev(vit)->first != val)
        pvit = vallist.insert(vit, make_pair(val, keylist_t()));
      else
        pvit = prev(vit);
      peit = pvit->second.insert(pvit->second.begin(), *eit);
      it->second = make_pair(pvit, peit);
    } else
      keymap.erase(it);
    vit->second.erase(eit);
    if (vit->second.empty())
      vallist.erase(vit);
  }

  string getMaxKey() {
    return vallist.empty() ? "" : vallist.back().second.front();
  }

  string getMinKey() {
    return vallist.empty() ? "" : vallist.front().second.front();
  }
};
```
