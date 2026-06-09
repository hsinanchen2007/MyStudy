### 解题思路
遍历数值n里的各个位数即可
### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        
        int multiplication = 1;
        int plus = 0;

        while(n > 0){
            multiplication *= n % 10;
            plus += n % 10;
            n /= 10;
        }
        return multiplication - plus;
    }
}
```