### 解题思路
此处撰写解题思路
我的思路:
    首先遍历数组中的元素，判断数组中的元素是否和target相等
如果相等就直接返回当前的下标，如果不想等的话就直接返回-1;
### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        for(int i=0;i<nums.length;i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
}
```