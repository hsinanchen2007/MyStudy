### 解题思路
处理好末尾字母之前的空格即可。

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0;
        bool flag = false;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i] != ' '){
                res++;
                flag = true;
            }
            else{
                if(!flag)
                    continue;
                else
                    break;
            }
        }
        return res;
    }
};
```