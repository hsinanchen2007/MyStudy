
## 解题步骤：

- 利用hashmap统计元素出现的频次，建立元素与频次之间的映射
- 创建元素个数为k的小顶堆优先队列
- 遍历hashmap, 当优先队列中元素个数小于k时，直接加入优先队列
- 如果优先队列中元素个数等于k时，新元素的频次与堆顶元素频次比较，如果比堆顶元素频次高，pop出堆顶元素，然后再push新的元素，如果比堆顶元素频次还要低，则不处理
- 最后使用数组保存频次前k的元素

## 时间复杂度

- 统计频率，需要遍历一遍数组，所需要的时间复杂度为`O(n)`, hashmap的插入、查找的时间复杂度为`O(1)`, 所以统计频率过程时间复杂度为O(n).
- 遍历hashmap的时间复杂度时间复杂度`O(n)`，维护元素个数为k的小顶堆时间复杂度为`O(logk)`， 这个过程时间复杂度为`O(nlogk)`.
- 把优先队列转换为数组时间复杂度为`O(k)`.

综上所述，整体时间复杂度为 `O(nlogk)`.


## 空间复杂度

- 创建hashmap，最坏情况，当没有相同元素时，复杂度为`O(n)`
- 小顶堆空间复杂度为`O(k)`
- 保存频率前k的元素数组，复杂度`O(k)`

综上，空间复杂度为`O(n)`


## cpp代码实现


```
typedef pair<int, int> IIPair;

struct cmp {
    bool operator()(const IIPair &left, const IIPair &right) const
    {
        return left.second > right.second;
    }
};


vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (auto i : nums) {
        mp[i]++;
    }
    
    priority_queue<IIPair, vector<IIPair>, cmp> q; // 创建一个小顶堆
    
    for (auto item : mp) {
        if (q.size() < k) {
            q.push(item);
        } else if (item.second > q.top().second) {
            q.pop();
            q.push(item);
        }
        // 新的元素频次小于堆顶元素频次的元素不处理。
    }
    
    vector<int> ret(q.size(), 0);
    
    while (!q.empty()) {
        ret[q.size()-1] = q.top().first;
        q.pop();
    }
    
    return ret;
}


```
