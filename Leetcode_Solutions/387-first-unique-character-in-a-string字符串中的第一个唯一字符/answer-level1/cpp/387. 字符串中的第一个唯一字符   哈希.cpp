### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>res(26,0);//26个小写字母
        for(auto c:s) res[int(c-'a')]++;//字母转数字
        for(int i=0;i<s.size();++i)if(res[s[i]-'a']==1)return i;
        return -1;

    }
};
```