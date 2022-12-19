### 解题思路
统计p中每个字母出现的次数，然后在s中维护一个长度和p一样的滑动窗口，然后统计滑动窗口中字母出现的次数，比较两者的统计数目是否相等即可

### 代码

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        char m1[26] = {0};
        char m2[26] = {0};
        vector<int> res;
        if(s.size() < p.size()) return {};
        int left = 0,right = left + p.size()-1;
        for(char c:p)
            ++m1[c-'a'];
        for(int i = left;i <= right;++i)
            ++m2[s[i]-'a'];
        while(right < s.size()){
            if(check(m1,m2)){
                res.push_back(left);
            }
            --m2[s[left]-'a'];
            ++left;
            ++right;
            if(right == s.size()) break;
            ++m2[s[right]-'a'];
        }
        return res;
    }
    
    bool check(char m1[],char m2[]){
        for(int i = 0;i < 26;++i){
            if(m1[i] != m2[i])
                return false;
        }
        return true;
    }
};
```