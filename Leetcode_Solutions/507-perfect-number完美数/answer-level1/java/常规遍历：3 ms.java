### 解题思路
先判断0和1，不属于完美数，然后递归，从1到根号num

### 代码

```java
class Solution {
    public boolean checkPerfectNumber(int num) {
        if(num < 2){
            return false;
        }
        int sum = 0;
        for(int i = 1;i<=(int)Math.sqrt(num);i++){
            if(i * (num/i) == num){
                sum += i + num/i;
            }
        }
        if(sum == 2*num){
            return true;
        }
        return false;
    }
}
```