### 解题思路
1ms解法
此题的根本是抓住旋转过程中的不变量。以下设f(0)=base。设数组所有数自然加和为sum。
观察发现，每次旋转时，数组的0至n-2位置，均向右移动一位，n-1位置移动到0的位置. 根据旋转公式的算法，旋转后的公式求和f(1)相当于在f(0)的基础上，数组的0至n-2位置的值均被叠加了一次，而n-1位置的值旋转后，需要减去(n-1)*A[n-1]，
即f(1)=f(0) + sum-(A[n-1]) - (n-1)*A[n-1], 化简后得：
f(1)=f(0) + sum - n*A[n-1]
f(2)=f(1) + sum - n*A[n-2]
...
f(x)=f(x-1) + sum - n*A[n-x]
遍历求最大即可

### 代码

```java
class Solution {
    public int maxRotateFunction(int[] A) {
        if (A==null || A.length ==0) {
            return 0;
        }
        int n = A.length;
        int sum = 0;
        int base = 0;
        for (int i=0; i<n; ++i) {
            sum += A[i];
            base += i*A[i];
        }
        int max = base;
        for (int i=1; i<n;++i) {
            base =  base + sum - n*A[n-i];
            if (max < base) {
                max = base;
            }
        }
        return max;
    }
}
```