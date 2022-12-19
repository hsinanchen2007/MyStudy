### 解题思路
有问题欢迎留言

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        int count = len,index = 0;
        for(int i=0;i<len;i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }else {
                count--;
            }
        }
        return count;
    }
}
```