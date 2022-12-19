### 解题思路
方法一：替换法
### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string t;
        for(int i=0;i<s.size();i++){
            
            if(s[i]==' ')
            {
                t+='%';
                t+='2';
                t+='0';

            }
            else{
                t+=s[i];
            }

        }
        return t;
    }
};
```