### 解题思路
此处撰写解题思路
设置ij，前后同时开始搜索，注意未旋转数组

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        int i = 0;
        int j = numbers.length-1;
        for(;;){
            if(i == numbers.length-1)
                return numbers[0];
            if(numbers[i] <= numbers[i+1]) i++;
            else return numbers[i+1];
            if(numbers[j] >= numbers[j-1]) j--;
            else return numbers[j];
        }
    }
}
```