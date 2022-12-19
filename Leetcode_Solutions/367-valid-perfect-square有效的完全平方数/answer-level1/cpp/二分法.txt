### 解题思路
用二分法进行查找，
1. 设 left, mid, right 三个指针，目标为num
2. mid^2 == num，则停止；mid^2 < num，则right=mid, mid=(left+right)/2; mid^2 > num, 则left=mid, mid=(left+right)/2；
3. 循环条件为 left < mid && right > mid

为了不溢出，判断 mid^2 时不能直接相乘，而是用 num 除以 mid 看看商和余数的大小来进行比较。

### 代码

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2)     // num==0 or num==1
            return num;
        
        int left=1;
        int right=num;
        int mid=num/2;
    
        while(left < mid && right > mid) {          // 循环条件
            if (mid == num/mid  && num%mid == 0) {  // mid^2 == num
                break;
            } else if (mid > num/mid || (mid == num/mid  && num%mid > 0)) {// mid^2 > num
                right = mid;
                mid = (left + right) / 2;
            } else { // mid^2 < num
                left = mid;
                mid = (left + right) / 2;
            }
        }

        return mid*mid == num;
    }
};
```