### 解题思路
找到数组中不满足增序的元素，返回它。如果不存在就返回第一个元素。

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        if(numbers.length == 0)
            return 0;

        if(numbers.length == 1)
            return numbers[0];

        for(int i = 0; i < numbers.length - 1; i++){
            if(numbers[i] <= numbers[i+1]){
                continue;
            }
            else{
                return numbers[i+1];
            }
        }
        return numbers[0];
    }
}
```