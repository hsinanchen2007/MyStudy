## 思路一：二分
右边界一定小于num / 2 + 1。
### 代码
时间复杂度：O(logn)
```c++
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num / 2 + 1;
        while (left <= right) {
            long int mid = left + (right - left) / 2;
            long int t = mid * mid;
            if (t == num) {
                return true;
            } else if (t > num) {
                right = mid - 1;
            } else {
                left = mid + 1;                
            }
        }
        return false;
    }
};
```

## 思路二：数学定理（最优）
任何一个平方数可以表示为一个计数数列和。
`1 + 3 + 5 + 7 + 9 + ... = n^2`
### 代码
时间复杂度：O(sprt(n))
```c++
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
```

