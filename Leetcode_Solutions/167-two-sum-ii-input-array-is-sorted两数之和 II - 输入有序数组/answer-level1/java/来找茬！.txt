```
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] result = new int[2] ;
        int left = 0 ;
        int right = numbers.length-1 ;
        //这种双指针的方法没什么好说的
        while(left<right){
            int sum = numbers[left]+numbers[right] ;
            if(sum==target){
                result[0] = left+1 ;
                result[1] = right+1 ;
                //为什么我这里不返回会超时？跳出循环返回不行嘛？
                //题目中是只有一组解，但是要是有多组解呢？不能说找到一组解就返回吧。
                return result ;
            }else if(sum>target){
                right-- ;
            }else{
                left++ ;
            }
        }
        return result ;
    }
}
```
其实双指针的思路没啥好说的，思路也简单。
