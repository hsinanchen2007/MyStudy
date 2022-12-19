### 解题思路
二分+夹逼

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x==1)return 1;
        double left=0,right=x;
        while(right>=left){
            double mid=left+double(right-left)/2;
            if(mid*mid>=x&&mid*mid-x<1) return mid;
            if(mid*mid>x) right=mid;
            if(mid*mid<x) left=mid;
        }
        return -1;
    }
};
```
![fdfdsfdsfdsfdsfdsfsdfsdfsdfsdfs.PNG](https://pic.leetcode-cn.com/cade08499d47bec267ef38c3993d038852f75a3e762726db8fe091710166b8fd-fdfdsfdsfdsfdsfdsfsdfsdfsdfsdfs.PNG)
