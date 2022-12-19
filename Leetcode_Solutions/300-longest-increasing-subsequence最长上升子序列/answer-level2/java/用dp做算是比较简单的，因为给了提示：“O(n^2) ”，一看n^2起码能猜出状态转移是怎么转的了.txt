### 解题思路
![QQ截图20200322180032.png](https://pic.leetcode-cn.com/a993751bb9b902739951e4a470d871cf588fcf7efa72a1588cb5f3e9e1d83f84-QQ%E6%88%AA%E5%9B%BE20200322180032.png)

没有优化代码，时间复杂度就是O(n^2)

第一反应是和53.“最大子段和”问题很像，当然没那么简单，不过我借用了最大子段和问题的思路：最大子段和问题里，用b[j]表示“以元素nums[j]结尾的子段所能达到的最大长度”，它的状态转移方程b[j]=max{b[j-1]+nums[j],nums[j]},当b[j-1]>0时取前者，否则取后者，最长子段和=最大的一个b元素

在这个问题里，我设置dp_max[j]表示"**以元素nums[j]结尾的上升子序列的最大长度**"，即nums[0]...nums[j]的最长上升子序列必须以nums[j]结尾”，状态转移方程dp_max[j]=max{
if(nums[j]>nums[i]):dp_max[i]+1;//先保证加上nums[j]还是升序，才能+1
else:1//因为我初始化dp就是1，所以肯定不会是它更大，我就直接省了
}，其中0<=i<=j-1

最长上升子序列的长度=最大的那一个dp_max数组元素

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
      if(nums.length==0) return 0;
        if(nums.length==1) return 1;

        int [] dp_max=new int[nums.length];//dp_max[i]表示以元素nums[i]结尾的最长上升子序列的长度，即nums[0]...nums[i]的最长上升子序列必须以nums[i]结尾
        for (int i=0;i<dp_max.length;i++
             ) {
            dp_max[i]=1;
        }
        int target_length=dp_max[0];

        for(int j=1;j<nums.length;j++){


            int temp=1;
            for(int i=0;i<j;i++){

               if(nums[i]<nums[j]){
                   temp=dp_max[i]+1;
               }
               if(temp>dp_max[j]){
                   dp_max[j]=temp;
               }
            }
        }

        for(int i=0;i<nums.length;i++){
            if(dp_max[i]>target_length){
                target_length=dp_max[i];
            }
        }
        return target_length;




    }
}
```