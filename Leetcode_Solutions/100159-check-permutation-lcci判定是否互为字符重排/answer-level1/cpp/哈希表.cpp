### 解题思路
哈希表

### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        unordered_map<char,int> hash;
        for(auto K:s1){
            if(hash.find(K) == hash.end())  hash[K] = 1;
            else hash[K]++;
        }
        for(auto K:s2){
            if(hash.find(K) == hash.end() || hash[K] == 0)  return false;
            else hash[K]--;
        }
        return true;
    }
};
```
###执行结果
执行用时 : 4 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 : 8.5 MB, 在所有 C++ 提交中击败了100.00%的用户