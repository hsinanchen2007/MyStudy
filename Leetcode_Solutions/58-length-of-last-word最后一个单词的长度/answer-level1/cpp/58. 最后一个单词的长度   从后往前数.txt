### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                len++;
            }
            else{
                if(len!=0)
                break;
            }
        }
        return len;
    }
};
```