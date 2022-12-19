### 解题思路
因为题目限定了递增数组，故下一位元素小于当前元素时即移位发生的位置

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        if(numbers.length==1)
            {
                return numbers[0];
            }
        for(int j=1;j<numbers.length;j++)
        {
            if(numbers[j]<numbers[j-1]){
                return numbers[j];
            }
        }
        return numbers[0];
    }
}
```