### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/13a30a515ced0f2395c926ba031149aa9fd032020922b5c75085870a5e6208ac-image.png)

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int res =0;
        int n = s.size();
        if(n==0) return 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='M') res+=1000;
            else if(s[i]=='D') res+=500;
            else if(s[i]=='C'){
                if(i!=n-1 && s[i+1]=='D'){res+=400;i++;}
                else if(i!=n-1 && s[i+1]=='M'){res+=900;i++;}
                else res+=100;
            }
            else if(s[i]=='L') res+=50;
            else if(s[i]=='X'){
                if(i!=n-1 && s[i+1]=='L'){res+=40;i++;}
                else if(i!=n-1 && s[i+1]=='C'){res+=90;i++;}
                else res+=10;
            } 
            else if(s[i]=='V') res+=5;
            else if(s[i]=='I'){
                if(i!=n-1 && s[i+1]=='V'){res+=4;i++;}
                else if(i!=n-1 && s[i+1]=='X'){res+=9;i++;}
                else res+=1;
            }
        }
        return res;
    }
};
```