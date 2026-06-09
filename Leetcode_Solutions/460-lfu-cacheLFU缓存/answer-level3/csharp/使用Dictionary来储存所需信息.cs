### 解题思路
将所有的值存入一个名为cache的Dictionary中，key为string (因为C#的Dictionary不像Java的HashMap，可以直接用int作key)，Tuple<int, int, DateTime> 为值。

Tuple<int, int, DateTime> 的三个值分别为：
1. Value
2. Reference count
3. Last used timestamp

此外，将构造函数中传入的capacity也作为一个variable存起来。


需要注意的是，test case 中会挖坑，故意给你将capacity设为0，然后往里面put东西。这一点需要在Put里额外注意。

### 代码

```csharp
public class LFUCache {
    /// 执行用时: 772 ms, 在所有 C# 提交中击败了 20.00% 的用户
    /// 内存消耗: 50.4 MB, 在所有 C# 提交中击败了 100.00% 的用户

    // Tuple: <value, reference count, last used time>
    private Dictionary<string, Tuple<int, int, DateTime>> cache;
    private int capacity;

    public LFUCache(int capacity) {
        this.cache = new Dictionary<string, Tuple<int, int, DateTime>>();
        this.capacity = capacity;
    }
    
    public int Get(int key) {
        if (!this.cache.ContainsKey(key.ToString())) { return -1; }

        string keyString = key.ToString();
        this.UpdateKeyReferenceDetails(keyString);

        return this.cache[keyString].Item1;
    }
    
    public void Put(int key, int value) {
        string keyString = key.ToString();

        if (this.capacity != 0) {
            if (!this.cache.ContainsKey(keyString)) {
                // Console.WriteLine($"this.cache.Count = {this.cache.Count}");
                // Check cache capacity first.
                if (this.cache.Count >= this.capacity) {
                    int leastUsedCount = this.cache.Min(record => record.Value.Item2);

                    string leastRecentlyUsedKey = this.cache.Where(record => record.Value.Item2.Equals(leastUsedCount))
                                                            .OrderBy(record => record.Value.Item3)
                                                            .Select(record => record.Key)
                                                            .First();

                    this.cache.Remove(leastRecentlyUsedKey);
                }
                this.cache[keyString] = new Tuple<int, int, DateTime>(value, 1, DateTime.Now);
            } else {
                this.UpdateKeyReferenceDetails(keyString, value);
            }
        }

    }

    private void UpdateKeyReferenceDetails(string keyString, int newValue = -1) {
        Tuple<int, int, DateTime> currentRecord = this.cache[keyString];
        Tuple<int, int, DateTime> newRecord;
        if (newValue == -1) {
            newRecord = new Tuple<int, int, DateTime>(currentRecord.Item1, currentRecord.Item2 + 1, DateTime.Now);
        } else {
            newRecord = new Tuple<int, int, DateTime>(newValue, currentRecord.Item2 + 1, DateTime.Now);
        }
        this.cache[keyString] = newRecord;
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */
```


## 更新
在看了[这个答案](https://leetcode-cn.com/problems/lfu-cache/solution/mei-you-ren-he-hua-li-hu-shao-zhi-lai-zhi-qu-de-si/)之后，我意识到C# 的dictionary是可以用int作为key的，所以我更改了一下代码，速度和储存都略有提升。

```csharp
public class LFUCacheIntAsKey {
    /// 执行用时: 676 ms, 在所有 C# 提交中击败了 20.00% 的用户
    /// 内存消耗: 50.3 MB, 在所有 C# 提交中击败了 100.00% 的用户


    // Tuple: <value, reference count, last used time>
    private Dictionary<int, Tuple<int, int, DateTime>> cache;
    private int capacity;

    public LFUCache(int capacity) {
        this.cache = new Dictionary<int, Tuple<int, int, DateTime>>();
        this.capacity = capacity;
    }
    
    public int Get(int key) {
        if (!this.cache.ContainsKey(key)) { return -1; }

        this.UpdateKeyReferenceDetails(key);

        return this.cache[key].Item1;
    }
    
    public void Put(int key, int value) {
        // Check cache capacity first.
        if (this.capacity != 0) {
            if (!this.cache.ContainsKey(key)) {
                if (this.cache.Count >= this.capacity) {
                    int leastUsedCount = this.cache.Min(record => record.Value.Item2);

                    int leastRecentlyUsedKey = this.cache.Where(record => record.Value.Item2.Equals(leastUsedCount))
                                                            .OrderBy(record => record.Value.Item3)
                                                            .Select(record => record.Key)
                                                            .First();
                    this.cache.Remove(leastRecentlyUsedKey);
                }
                this.cache[key] = new Tuple<int, int, DateTime>(value, 1, DateTime.Now);
            } else {
                this.UpdateKeyReferenceDetails(key, value);
            }
        }

    }

    private void UpdateKeyReferenceDetails(int key, int newValue = -1) {
        Tuple<int, int, DateTime> currentRecord = this.cache[key];
        Tuple<int, int, DateTime> newRecord;
        if (newValue == -1) {
            newRecord = new Tuple<int, int, DateTime>(currentRecord.Item1, currentRecord.Item2 + 1, DateTime.Now);
        } else {
            newRecord = new Tuple<int, int, DateTime>(newValue, currentRecord.Item2 + 1, DateTime.Now);
        }
        this.cache[key] = newRecord;
    }
}
```