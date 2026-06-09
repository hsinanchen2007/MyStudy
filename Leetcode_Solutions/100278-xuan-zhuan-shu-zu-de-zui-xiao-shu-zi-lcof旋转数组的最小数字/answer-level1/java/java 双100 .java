找第一个小于前面的数
```
class Solution {
    public int minArray(int[] numbers) {
        for(int i=0;i<numbers.length-1;i++){
            if(numbers[i+1]<numbers[i])
                return numbers[i+1];
        }
        return numbers[0];
    }
}

```
