### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int reverse(int x) {
       signed long long int y = 0;
        for(;x/10 != 0;x = x/10){
            y = y*10 + x%10 ;
        }
        y = y*10 + x%10;
        //return  long(long(1<<31)-1);
        //return y < (signed long long int)(0-(signed long long int)(1<<31));
        signed long long int z = y;
        if (z < 0) {
            z = 0-z;
        }
        if (z >  (signed long long int)(~(1<<31))){
            return 0;
        }
        return int(y);
    }
};
```