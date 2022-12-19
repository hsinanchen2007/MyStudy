```csharp
public class RandomizedSet
    {
        private Dictionary<int, int> _dictionary;
        private List<int>            _list;
        private Random               _random = new Random();

        /** Initialize your data structure here. */
        public RandomizedSet()
        {
            _dictionary = new Dictionary<int, int>();
            _list       = new List<int>();
        }

        // 添加元素到动态数组。
        // 在哈希表中添加值到索引的映射
        public bool Insert(int val)
        {
            if (_dictionary.ContainsKey(val))
            {
                return false;
            }

            // 字典存储值对应的 数组下标映射
            _dictionary[val] = _list.Count;
            _list.Insert(_list.Count, val);
            return true;
        }

        // 在哈希表中查找要删除元素的索引。
        // 将要删除元素与最后一个元素交换。
        // 删除最后一个元素。
        // 更新哈希表中的对应关系。
        public bool Remove(int val)
        {
            if (!_dictionary.ContainsKey(val))
            {
                return false;
            }

            // 最后一个元素值
            int lastElement = _list[_list.Count - 1];
            // 要删除的值的索引
            int idx = _dictionary[val];
            // 删除位置的值替换成最后一个元素值
            _list[idx]               = lastElement;
            // 更新字典里的索引
            _dictionary[lastElement] = idx;
            // 移除掉最后一个元素
            _list.RemoveAt(_list.Count - 1);
            // 字典里也移除
            _dictionary.Remove(val);
            
            return true;
        }

        /** Get a random element from the set. */
        public int GetRandom()
        {
            return _list[_random.Next(_list.Count)];
        }
    }
```
