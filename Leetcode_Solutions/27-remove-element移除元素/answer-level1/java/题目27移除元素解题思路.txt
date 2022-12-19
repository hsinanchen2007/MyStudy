### 解题思路
此处撰写解题思路
发现与目标值相等的值，则把数组后面的值均向前移动一位，然后再重新从这个位置进行查找
### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int flag=0;
        for(int i=0;i<nums.length-flag;i++){
            if(nums[i]==val){
                for(int j=i;j<nums.length-flag-1;j++){
                    nums[j]=nums[j+1];

                }
                ++flag;
                i--;
            }
        }
        return nums.length-flag;
    }
}
```