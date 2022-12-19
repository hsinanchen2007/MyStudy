### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int start = 0;
        int end = numbers.length - 1;
        while(start < end){
            while(numbers[start] + numbers[end] > target){
                end--;
            }
            if(numbers[start] + numbers[end] == target){
                return new int[]{start+1, end+1};
            }
            else{
                start++;
            }
        }

        return null;
        
        


        
    }
}
```