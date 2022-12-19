### 解题思路
此处撰写解题思路
写逻辑判断式的先后顺序很重要，容易被忽略，两个掉坑里了
### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string str;
        int p1 = 0;
        int p2 = s.size()-1;
        //去掉首尾空格
        while(s[p1]==' ')
        {
            p1++;
        }
            
        while(s[p2]==' ')
        {
            p2--;
        }
        int n = 0;  
        for(int i = p2;i>=p1;i--)
        {  
           if(s[i]!=' ')
           {
              n++;

              if(i>p1&&s[i-1]==' ')
              {
                  str.append(s,i,n);
                  str+=' ';
                  n=0;
              }
              if(i==p1)
              {
                  str.append(s,i,n);
              }
           }
        }
        return str;
    }
};
```