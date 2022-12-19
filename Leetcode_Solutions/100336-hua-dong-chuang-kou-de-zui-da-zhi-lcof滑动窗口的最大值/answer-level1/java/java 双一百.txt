记录下上一次最大值的索引，当该索引还在窗口内时，只要比较其与新加进来的数(最后一个数)即可，当索引到了窗口外时，遍历一遍窗口内的元素，找最大值
```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int len = nums.length;
        if(len==0) return new int[0];
        int maxIndex = -1;
        int start =0;
        int end = start+k-1;
        int ret[] =new int[len-k+1];
        while(end<len){
            if(maxIndex<start){
                int temp = nums[start];
                maxIndex =start;
                for(int i=start+1;i<=end;i++){
                    if(temp<=nums[i]){
                        temp = nums[i];
                        maxIndex = i;
                    }
                }
                ret[start] = temp;
            }
            else if(nums[end]>=ret[start-1]){
                    maxIndex = end;
                    ret[start]=nums[end];
                }
            else {
                 ret[start]=ret[start-1];
            }
            start++;
            end++;
        }
        return ret;
    }
}
```
