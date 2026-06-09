指针i用于从后往前遍历。指针k用来指示末尾空格的长度，在指示到第一个非空格字符时暂停。
```
class Solution {
public:
    int lengthOfLastWord(string s) {
    if(s.size() == 0) return 0;
    
    int re = 0;
    int k = s.size() -1;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if(s[k] == ' '){
            k--;
        }else{
            if(s[i] != ' ')
            {
                re++;
            }
            else
            {
                break;
            }
        }
    }
    return re;
    }

};
```

