```java
class Solution {
    public int minArray(int[] numbers) {
        int max = numbers[0];
        for(int i = 0; i < numbers.length; i++){
            if(numbers[i] >= max){
                max = numbers[i];
            }else{
                return numbers[i];
            }
        }
        return numbers[0];
    }
}
```
