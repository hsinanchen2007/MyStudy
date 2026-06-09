```
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        if(numbers.length<1||numbers[0]>target)
        {
            return new int[0];
        }
       
        int firstIndex=0;
        int secondIndex=numbers.length-1;
        while(firstIndex<secondIndex){
           
            int sum = numbers[firstIndex]+numbers[secondIndex];
            if(sum==target){
                return new int[]{firstIndex+1,secondIndex+1};
            }
            if(sum<target){
                firstIndex++;
            }else{
                secondIndex--;
            }
        }
        
        return new int[0];
    }
}
```
