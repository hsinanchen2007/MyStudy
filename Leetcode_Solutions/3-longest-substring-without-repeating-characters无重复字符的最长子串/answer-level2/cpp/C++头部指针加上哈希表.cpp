### 解题思路
头部指针加上哈希表

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if (n==0 || n==1) return n;
        int res=0;
        int front=-1;
        unordered_map<char,int> recorder;
        for (int i=0;i<n;i++){
            if (recorder.find(s[i])!=recorder.end() && front<recorder[s[i]]){
                front=recorder[s[i]];
            }
            recorder[s[i]]=i;
            res = max(res,i-front);
        }
        return res;
    }
};
```