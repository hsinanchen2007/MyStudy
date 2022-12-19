### 代码

#### 错误写法
该写法无法解决 3 * 3 * 3 * 3 这种情况
```java
class Solution1 {
    public int sumFourDivisors(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            int count = 0;
            int lower = 0;
            for (int j = 2; j * j < nums[i]; j ++) {
                if (nums[i] % j == 0) {
                    count ++;
                    lower = j;
                }
                if (count > 1) break;
            }
            if (count == 1) res = res + 1 + nums[i] + lower + nums[i] / lower;
        }
        return res;
    }
}
```
#### 正确写法

```java
class Solution {
    public int sumFourDivisors(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            int last = 0;
            for (int j = 2; j * j <= nums[i]; j ++) {
                if (nums[i] % j == 0) {
                    if (last == 0) {
                        last = j;
                    } else {
                        last = 0;
                        break;
                    }
                }
                
            }
            if (last > 0 && last * last != nums[i])
                res = res + 1 + nums[i] + last + nums[i] / last;
        }
        return res;
    }
}
```

