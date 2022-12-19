### 解题思路
此处撰写解题思路
我的思路:
    把一维数组进行排序，然后通过相邻的两个数的和进行比较大小，
用后面的减去前面的值，然后就是找最大值的意思！
最后返回这个最大的值；
### 代码

```java
class Solution {
    public int maximumGap(int[] nums) {
        if(nums.length<=1){
            return 0;
        }
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                if(nums[i]>nums[j]){
                    int t=nums[i];
                    nums[i]=nums[j];
                    nums[j]=t;
                }
            }
        }
       int max=-10000000;
        for(int i=0;i<nums.length-1;i++){
            int sum=nums[i+1]-nums[i];
     
            if(sum>max){
                max=sum;
            }
        }
        return max;
    }
}
```