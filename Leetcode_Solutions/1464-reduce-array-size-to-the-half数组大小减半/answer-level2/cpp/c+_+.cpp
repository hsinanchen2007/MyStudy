### 解题思路
执行用时 :236 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :41.5 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
struct cmp{
    bool operator() (const pair<int, int>& p1, const pair<int, int>& p2){
        return p1.second > p2.second;
    }
};
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> map;
        for(auto m : arr) ++map[m];
        vector<pair<int, int> > kv;
        for(auto t : map)kv.push_back(t);
        sort(kv.begin(), kv.end(), cmp());
        int sum = 0;
        int ans = 0;
        for(auto t : kv){
            if(sum < arr.size() / 2){
                sum += t.second;
                ++ans;
            }else break;
        }
        return ans;
    }
};
```