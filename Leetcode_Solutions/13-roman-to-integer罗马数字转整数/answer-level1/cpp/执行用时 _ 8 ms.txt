### 解题思路
switch case暴力解题

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        int num = 0;
        for(int i = 0; i < len; i++){
            switch(s[i]){
                case 'M':if(i>0&& s[i-1] == 'C') break;else num+=1000; break;
                case 'D':if(i>0&& s[i-1] == 'C') break;else num+=500; break;
                case 'C':if(i>0&& s[i-1] == 'X') break;else if(i<len-1&&s[i+1] == 'M') num+=900;else if(i<len-1&&s[i+1] == 'D') num+=400;else num+=100; break;
                case 'L':if(i>0&& s[i-1] == 'X') break;else num+=50; break;
                case 'X':if(i>0&& s[i-1] == 'I') break;else if(i<len-1&&s[i+1] == 'C') num+=90;else if(i<len-1&&s[i+1] == 'L') num+=40;else num+=10; break;
                case 'V':if(i>0&& s[i-1] == 'I') break;else num+=5; break;
                case 'I':if(i<len-1&&s[i+1] == 'X') num+=9;else if(i<len-1&&s[i+1] == 'V') num+=4;else num+=1; break;
            }
        }
        return num;
    }
};
```