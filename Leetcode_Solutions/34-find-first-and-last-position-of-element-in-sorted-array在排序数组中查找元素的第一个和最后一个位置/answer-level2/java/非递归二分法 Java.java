### 解题思路

通过二分法，确定左右边界，即最左边与 target 相同的元素的位置和最右边与 target 相同元素的位置。

参考二分法模板：https://www.liwei.party/2019/06/19/leetcode-solution-new/search-insert-position/

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        // 非递归写法：left, right 指针，采用 2 分思想，获取最左和最右边界
        int left = 0;
        int right = nums.length;// 表示全部数组元素都小于 target
        int[] res = new int[]{-1,-1};
  
        while(left<right){
            // 左中位数
            int mid = left + (right-left)/2;
            // 先写排除中位数的条件
            if(nums[mid]<target){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        //退出循环肯定 left==right,此时做后处理；
        // 判断 left 是否合法
        if(left==nums.length||nums[left]!=target){
            return res;
        }
        res[0]=left;
        // 此时，可以确定有大于 target 的元素存在，因此 right 最大可能取值为 len-1
        right = nums.length - 1;
        while(left<right){
             // 右中位数
            int mid = left +(1+right-left)/2;
            // 先写排除中位数的条件
            if(nums[mid]>target){
                right = mid-1;
            }else{
                left = mid;
            }
        }
        res[1]=left;
    return res;
    }
}
```