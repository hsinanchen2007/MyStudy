### 解题思路
双指针
### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        for(int j =0;j<nums.length;j++){
            if(nums[j]!=val){
                //将保留元素赋值，然后移除的会根据j来跳过
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
}
```