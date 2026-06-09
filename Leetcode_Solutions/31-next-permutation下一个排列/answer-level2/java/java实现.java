### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        int j=-1;
        for(int i=nums.length-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                 j=i;
                 //定义j是为了找到比nums[i-1]大的元素
                while(j<=nums.length-1&&(nums[j]>nums[i-1])){
                    j++;
                }
                j=j-1;
                //交换i,j
                int temp=nums[i-1];
                nums[i-1]=nums[j];
                nums[j]=temp;
                Arrays.sort(nums,i,nums.length);
                break;
            }
        }
        //不存在下一个更大的排列
        if(j==-1) Arrays.sort(nums);
    }
}
```