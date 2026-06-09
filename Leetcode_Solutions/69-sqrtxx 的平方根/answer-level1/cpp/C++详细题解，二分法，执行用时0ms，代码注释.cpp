### 思路
- 使用二分法，通过对x和mid的商的比较，得到答案
- 注意：不能通过mid*mid来与x进行比较，会溢出
```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)    return x;
        int l = 0;
        int r = x;
        while(l <= r){
            int mid = l + (r - l) /2;
            int s = x / mid; //用来判断mid大于目标还是小于目标，或等于目标
            int ss = x / (mid + 1);
            if(x / s == s)  return s; //刚好是他的算术平方根
            if(s > mid && ss < mid + 1) return mid; //例如6 在2的平方以及 3的平方之间  答案为2
            if(s > mid) l = mid + 1; //调整边界
            if(s < mid) r = mid - 1;
        }
        return 0;
    }
};
```
