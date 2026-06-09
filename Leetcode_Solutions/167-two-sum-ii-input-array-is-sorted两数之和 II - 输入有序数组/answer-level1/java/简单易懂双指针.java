```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        if(numbers.length==0)
            return null;
        int left = 0; 
        int right = numbers.length-1;
        while(left<right){
            if(numbers[left]+numbers[right] == target){
                int[] res = {left+1,right+1};
                return res;
            }
            if(numbers[left]+numbers[right] < target)
                left++;//变大
            else
                right--;//变下
        }
        return null;
    }
}
```