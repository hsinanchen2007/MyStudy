### 解题思路

循环呀快活呀

### 代码

```cpp
class Solution {
public:
    string encode(int num) {
        if(num==0)return "";
        int i=1;
        while((i<<1)<num){
            i<<=1;
            num-=i;
        }
        num--;
        string ret;
        for(int j=1;j<=i;j<<=1){
            if(num&1)ret="1"+ret;
            else ret="0"+ret;
            num>>=1;
        }
        return ret;
    }
};
```