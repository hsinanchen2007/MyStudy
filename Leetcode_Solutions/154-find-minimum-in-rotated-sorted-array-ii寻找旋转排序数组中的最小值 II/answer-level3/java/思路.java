### 解题思路
此处撰写解题思路
我的思路:
    为了防止会出现负数的情况下才使用的是-100000000，然后通过遍历数组的
里的元素，判断数组中的元素是否小于这个min，如果小于的话则赋值，
最后返回这个最小的值;
### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        int min=100000000;
        for(int i=0;i<nums.length;i++){
            if(nums[i]<min){
                min=nums[i];
            }
        }
        return min;
    }
}
```