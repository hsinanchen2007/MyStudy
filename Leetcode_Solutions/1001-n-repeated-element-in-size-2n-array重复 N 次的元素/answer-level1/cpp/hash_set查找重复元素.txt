
## 解题思路
根据题意，2N的数组中与N+1个元素，一个元素重复了N次，也就是说，其他N个元素都只出现了一次。只要直到重复元素，那么这个元素就是出现N次的那个元素。


## 代码实现
```
int repeatedNTimes(vector<int>& A) {
    unordered_set<int> s;
    for (auto i : A) {
        if (s.find(i) != s.end()) {
            return i;
        } else {
            s.insert(i);
        }
    }
    
    return 0;
}
```

## 复杂度分析

- 时间复杂度：`O(n)`， 需要遍历数组，unordered_set的查找和插入操作都是`O(1)`, 所以整个时间复杂度为`O(n)`
- 空间复杂度： `O(n/2+1)`， set存不同元素n+1个。