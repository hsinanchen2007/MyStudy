### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())  return 0;
        int p1 = s.size()-1;
        int num = 0;
        //注意q要去掉首尾的空格
        while(s[p1]==' ')
        {
            p1--;
        }
        while(s[p1]!=' '&& p1>=0)
        {
            num++;
            p1--;
        }
        return num;
    
    }
};
```