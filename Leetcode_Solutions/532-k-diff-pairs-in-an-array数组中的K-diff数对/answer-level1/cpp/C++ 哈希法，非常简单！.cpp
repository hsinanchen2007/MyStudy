# 利用unordered_map实现哈希表，思路简单。

不过我这里针对k==0的情况专门搞了个set来处理，大家有没有什么优化方法？

```c++ []
int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;
    int ans = 0;
    set<int>set;
    unordered_map<int, int>map;
    for (int i = 0; i < nums.size(); i++) {
        int n = nums[i];
        if (map[n]) { set.insert(n); continue; }//已经存在于map
        map[n] = i + 1;
        if (map[n + k]) ans++;
        if (map[n - k]) ans++;			
    }
    return k?ans:set.size();
}
```

