### 解题思路
此处撰写解题思路
根据26个字母创建数组判断字母计数统计
### 代码

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        if(n==0) return -1;
        int a[26];
        for(int i=0;i<26;i++){
            a[i] = 0;
        }
        for(int i=0;i<n;i++){
            a[s[i]-'a'] += 1;
        }
        for(int i=0;i<n;i++){
            if(a[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};
```