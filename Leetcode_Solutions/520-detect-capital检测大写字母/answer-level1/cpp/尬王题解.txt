### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/42c29a5f81e6c344dba170cb52f5145dd8dbb8558ed94ba2497e87bf6ab0ec1b-image.png)
四个变量

### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        int flagfd = 0;int flagfx = 0;int flagxx = 0;int flagdx = 0;
        for(int i= 0;i<word.size();i++)
        {
            if(word[0]>='A'&&word[0]<='Z'&&flagfd!=1)
            {
                flagfd = 1;
                continue;
            }
            if(word[0]>='a'&&word[0]<='z'&&flagfx!=1)
            {
                flagfx = 1;
                continue;
            }
            if(word[i]>='a'&&word[i]<='z')
            {
                flagxx = 1;
            }
            if(word[i]>='A'&&word[i]<='Z')
            {
                flagdx =1;
            }

            
        }
            if(flagfd==1&&flagxx==0)
            {

                return true;
            }
            if(flagfx==1&&flagdx==0)
            {

                return true;
            }
            if(flagfd ==1 &&flagdx==0)
            {

                return true;
            }
        return false;
    }
};
```