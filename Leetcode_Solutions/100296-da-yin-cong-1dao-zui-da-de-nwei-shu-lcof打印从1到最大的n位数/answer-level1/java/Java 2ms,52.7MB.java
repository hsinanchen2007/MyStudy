### 解题思路
每位数最大值为9,先得出数组长度,再从后面往前填充可以不用另外定义变量

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int sum = 9;
        while(n > 1){
            sum = sum * 10 + 9;
            n--;
        }
        int[] arr = new int[sum];
        for(; sum > 0;){
            arr[sum - 1] = sum--;
        }
        return arr;
    }
}
```