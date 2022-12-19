### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string toHex(int num) {
        string ss;
        if(num==0){
            return "0";
        }
        long int t;
        if(num<0)t=pow(2,32)+num;
        else{
            t=num;
        }
        while(t){
            if(t%16<10){
                ss+=t%16+'0';
            }
            else{
                ss+=t%16-10+'a';
            }
            t/=16;
        }
        reverse(ss.begin(),ss.end());
        return ss;
    }
};
```