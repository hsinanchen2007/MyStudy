### 解题思路
![WechatIMG6.jpeg](https://pic.leetcode-cn.com/b41b65ea9172798e6db4b6b0da0aeb587fd570631760445541845970cf6556d5-WechatIMG6.jpeg)


### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums==null || nums.length==0){
            return -1;
        }
        //利用二分法寻找分隔点
        int middleIndex = searchMaxIndex(nums,0,nums.length-1);
        System.out.println("middleIndex:"+middleIndex);
        //根据分隔点判断向左还是向右查找
        if((target>=nums[0] && target<=nums[middleIndex]) || middleIndex==(nums.length-1)){
            return searchBinary(nums,0,middleIndex,target);
        }
        if(target>=nums[middleIndex+1] && target<=nums[nums.length-1]){
            return searchBinary(nums,middleIndex+1,nums.length-1,target);
        }
        return -1;
    }

    public int searchMaxIndex(int[] nums,int begin,int end){
        System.out.println("begin,end:"+begin+","+end);
        
        if(begin == end){
            return begin;
        }else if(end-begin==1){
            if(nums[begin]>nums[end]){
                return begin;
            }else{
                return end;
            }
           
        }else{
            int middle = (end-begin)/2+begin;
            if(nums[0]>nums[middle]){
                end = middle;
            }else{
                begin = middle;
            }
            return searchMaxIndex(nums,begin,end);
        }
    }

    public int searchBinary(int[] nums,int begin,int end,int target){
        if(begin > end){
            return -1;
        }else if(begin == end){
            if(nums[begin]==target){
                return begin;
            }else{
                return -1;
            }            
        }else{
            int middle = (end-begin)/2+begin;
            if(nums[middle] == target){
                return middle;
            }
            if(nums[middle]>target){
                end = middle-1;
            }else{
                begin = middle+1;
            }
            return searchBinary(nums,begin,end,target);
        }
        
    }
}
```