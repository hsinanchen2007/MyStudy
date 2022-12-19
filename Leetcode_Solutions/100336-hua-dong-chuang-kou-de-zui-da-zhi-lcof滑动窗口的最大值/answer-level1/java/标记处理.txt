![微信图片_20200225143542.png](https://pic.leetcode-cn.com/9e274f389eca3d9fe897697f1ee138a4d4578ee8c7b7baae18676bb1004268ba-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200225143542.png)
先找出第一个窗口的最大值，然后滑到下一个窗口的时候，先判断下一个值是否大于上一个的最大值，如果是则直接赋值，否则判断上一个最大值的位置是否还在窗口中，如果是则也可赋值，否则进行遍历。可以提高执行时间，我的从暴力破解的33ms提升到了2ms。
```java []
console.log('Hello world!')
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length==0){return nums;}
        int[] mmax=new int[nums.length-k+1];
        int max=nums[0],maxlo=0;
        for(int j=1;j<=k-1;j++){
            if(max<=nums[j]){
                maxlo=j;
                max=nums[j];
            }
         //max=max>nums[j]?max:nums[j];
        }
        mmax[0]=max;
        for(int i=1;i<mmax.length;i++){
            if(nums[i+k-1]>=mmax[i-1]){
                mmax[i]=nums[i+k-1];
                maxlo=i+k-1;   
            }
            else{
                if(maxlo>=i){
                    mmax[i]=mmax[i-1];
                }
                else{
                    max=nums[i];
                    maxlo=i;
                    for(int j0=i+1;j0<=i+k-1;j0++){
                        if(max<=nums[j0]){
                            maxlo=j0;
                            max=nums[j0];
                        }
                    }
                    mmax[i]=max;
                }
            }
        }
        
        return mmax;
    }
}
```
