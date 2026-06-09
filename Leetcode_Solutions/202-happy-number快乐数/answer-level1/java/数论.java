### 解题思路
思路很清晰，往set里面添加元素，如果出现之前出现过的，那么肯定是死循环。不然就继续计算添加知道满足条件。

### 代码

```java
class Solution {
    public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<>();

        while(true){
            int x = 0;
            int sum = 0;

            while(n != 0){
                x = n % 10;
                n = n / 10;
                sum += x * x;
            }
            if(sum == 1)
                return true;
            if(!set.add(sum))
                return false;
            n = sum;
        }
    }
}
```