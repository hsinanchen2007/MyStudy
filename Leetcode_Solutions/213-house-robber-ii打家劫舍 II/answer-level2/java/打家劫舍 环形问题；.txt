### 解题思路
"细心的你肯定发现" ? 这是什么虎狼之词，不过确实是非常好的一个实例，再遇到收尾不相容的情况，终于有了解决办法；

### 代码

```java
class Solution {
     public int rob(int[] nums) {

        if(nums== null || nums.length ==0){
            return  0;
        }
        if(nums.length==1){
            return nums[0];
        }
        
        return Math.max(rob(nums,1,nums.length),rob(nums,0,nums.length-1));
    }

    public int rob(int[] nums1 , int startIndex , int endIndex){
        int [] nums = Arrays.copyOfRange(nums1,startIndex,endIndex);

        if(nums== null || nums.length ==0){
            return  0;
        }
        int a = 0 , b= 0,temp =0;

        for(int i = 0 ; i < nums.length ; i ++ ){
            temp = Math.max(a + nums[i] , b);
            a = b;
            b = temp;
        }

        return  temp;
    }
}
```