```
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        for(int index1=0;index1<numbers.length;index1++){
            for(int index2=index1+1; index2<numbers.length; index2++){
                if(numbers[index1]+numbers[ index2]==target){
                    return new int[]{index1+1, index2+1};
                }
            }
        }
         throw new IllegalArgumentException("No two sum solution");
}

```    }

