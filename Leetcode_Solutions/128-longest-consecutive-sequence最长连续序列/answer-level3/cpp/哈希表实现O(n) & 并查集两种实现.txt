### 方法一： 哈希表
1. 找到一个可以作为起点的数字（没有比它小的数），计算以它开头的最长连续子序列，如比当前记录的都长，则更新当前最长记录

### 代码一

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int n: nums) st.insert(n);
        int ans = 0;
        for(int i: st){
            // 假如一个数在哈希表中存在比他小的，那么它不是可以作为开头的数字
            if(i != INT_MIN && st.count(i-1)){
                continue;
            }
            int cnt = 1;
            while(i!=INT_MAX && st.count(i+1)){
                cnt ++;
                i++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```

### 方法二： 并查集
1. 将连续的数字作为一个集合
2. 那么扫描到一个数字，只要将它和它的下一个数字（假如存在）merge在一个集合即可。同时更新这个集合的元素个数
3. 如果当前经过merge的集合的元素个数比当前记录的最长序列的长度都长，则更新当前最长记录


### 代码二

```
class Solution {
public:
    // cnt用于记录当前集合的元素个数
    unordered_map<int,int> uf, cnt;

    int find(int i){
        return i == uf[i] ? i: uf[i] = find(uf[i]);
    }

    int merge(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return cnt[x];
        uf[y] = x;
        //更新合并之后的连通分量的元素个数
        cnt[x] += cnt[y];
        return cnt[x];
    }

    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        for(int i: nums) uf[i] = i, cnt[i] = 1;
        int ans = 1;
        for(int i: nums){
            if(i != INT_MAX && uf.count(i+1)) ans = max(ans, merge(i, i+1));
        }
        return ans;
    }
};
```
