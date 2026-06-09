### 解题思路
首先算出N所位于的数字是几位数，然后算出z所在的这个数字（商）以及第N个数所在的位置（求余数）

### 代码

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        if(n<10)
        return n;
        int t=1;
        while(n>9*pow(10,t-1)*t){
            n-=9*pow(10,t-1)*t;
            t++;
        }
        int ans=pow(10,t-1)+n/t;
        int mm=n%t;
        if(mm==0)
        {ans--;mm=t;}
        return to_string(ans)[mm-1]-'0';
    }
};
```