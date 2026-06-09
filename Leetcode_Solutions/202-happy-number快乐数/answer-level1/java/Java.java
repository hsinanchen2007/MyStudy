### 解题思路
使用HashSet存储过往记录，如果有重复数字，代表进入了无限循环。

### 代码

```java
class Solution {
    public boolean isHappy(int n) {
        // 使用HashSet存储过往记录，如果有重复数字，代表进入了无限循环
        HashSet<Integer> set = new HashSet<>();
        while (n != 1){
            if (set.contains(n)){
                return false;
            }
            set.add(n);
            n = digitSquareSum(n);
        }
        return true;
    }

    // return digit sum of square of given int n
    public int digitSquareSum(int n){
        int sum = 0;
        while (n > 0){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
}
```