### 解题思路
荷兰国旗包含三种颜色：红、白、蓝。
有三种颜色的球，算法的目标是将这三种球按颜色顺序正确地排列。它其实是三向切分快速排序的一种变种，在三向切分快速排序中，每次切分都将数组分成三个区间：小于切分元素、等于切分元素、大于切分元素，而该算法是将数组分成三个区间：等于红色、等于白色、等于蓝色。

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        int i=-1,j=nums.length,pivot=0;
        while(pivot<j){
            if(nums[pivot]==0){
                swap(nums,++i,pivot++);
            }else if(nums[pivot]==2){
                swap(nums,--j,pivot);
            }else{
                pivot++;
            }
        }

    }
    public void swap(int[] nums,int i,int j){
        int t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }
}
```