## 思路
非负数x的平方根不会大于(x / 2 + 1)。
### 代码
```c++
class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x / 2 + 1;
        while (low <= high) {
            long int mid = low + (high - low) / 2;//必须是long
            long int t = mid * mid;
            if (t == x) {
                return mid;
            } else if (t < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } 
        return high;
    }
};
```
#### 另一种写法（击败100%）
用除法避免溢出。
```
class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int t = x / mid;
            if (t == mid) {
                return mid;
            } else if (t > mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } 
        return high;
    }
};
```

