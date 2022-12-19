### 解题思路
此处撰写解题思路
1、多数元素的个数>数组长度的一般
2、将数组排序，从左到右遍历
### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        if (nums.length < 1) return -1;
        if (nums.length == 1) return nums[0];
        int mid = nums.length / 2;
        Arrays.sort(nums);
        for(int i = 0;i<=mid;i++){
            for(int count = 1,j=i+1;j<nums.length;j++){
                if (nums[j]==nums[j-1]){
                    count++;
                }else{
                    break;
                }
                if(count > mid)
                    return nums[i];
            }
        }
        return -1;
    }
}
```