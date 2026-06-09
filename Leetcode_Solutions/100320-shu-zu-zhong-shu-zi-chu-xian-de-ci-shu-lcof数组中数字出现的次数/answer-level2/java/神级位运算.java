### 解题思路
知乎大佬给出这道题的两种解法，还是觉得异或运算比较厉害，逼格更高
https://zhuanlan.zhihu.com/p/104143304

### 代码

```java
class Solution {
    public int[] singleNumbers(int[] nums) {
        if(nums==null||nums.length==0){
            return new int[]{};
        }
        int temp=0;
        //任何数和0异或都等于它本身
        for(int i=0;i<nums.length;i++){
            temp^=nums[i];
        }
        int index=1;
        while((index&temp)==0){
            index=index<<1;
        }
        int res1=0;
        int res2=0;
        for(int i=0;i<nums.length;i++){
            if((index&nums[i])==0){
                res1^=nums[i];
            }else{
                res2^=nums[i];
            }
        }
        return new int[]{res1,res2};
    }
}
```