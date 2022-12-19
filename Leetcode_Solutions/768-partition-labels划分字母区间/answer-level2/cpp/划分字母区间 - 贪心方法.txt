### 解题思路
1. 如给出输入`S = "ababcbacadefegdehijhklij"`
2. 使用`i`遍历`S`，找到和`S[i]`相同的且满足在`S`中下标最大的那个字符的下标`cur`
3. 遍历区间`[i+1, cur]`，遍历同时更新`cur`，看是否要扩大这个区间（**贪心思想，如果cur能更新就更新**）
4. 将`[i, cur]`这个区间的长度加入到结果集`ans`。同时更新`i = cur + 1` 
5. 重复`1-4`，直到`i`遍历完整个`S`，`ans`即结果

### 代码

```cpp
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            mp[S[i] - 'a'] = i;
        }
        int i = 0;
        while(i < n){
            int cur = mp[S[i] - 'a'];
            for(int j = i + 1; j < cur; ++j){
                cur = max(cur, mp[S[j] - 'a']);
            }
            ans.push_back(cur - i + 1);
            i = cur + 1;
        }
        return ans;
    }
};
```