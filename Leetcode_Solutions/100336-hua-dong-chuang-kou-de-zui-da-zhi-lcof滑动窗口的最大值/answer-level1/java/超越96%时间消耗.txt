```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length == 0)return new int[0];
        int start = 0;
        int end = k - 1;
        int[] res = new int[nums.length - k + 1];
        int max_v = findMax(nums, start, end);
        res[start] = max_v;
        start++;
        end++;
        while(end < nums.length){
            if(nums[end] >= max_v){
                res[start] = nums[end];
            }else{
                if(nums[start - 1] != max_v){
                    res[start] = max_v;
                }else{
                    res[start] = findMax(nums, start, end);
                }
            }
            max_v = res[start];
            start++;
            end++;
        }
        return res;
    }
    int findMax(int[] nums, int begin, int end){
        int max = nums[begin];
        while(begin <= end){
            max = nums[begin] > max?nums[begin]:max;
            begin++;
        }
        return max;
    }
}
```