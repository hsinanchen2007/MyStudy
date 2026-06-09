！在所有 Java 提交中击败了100.00%的用户
天呐
没想到我也有高光的那一天！
emmm（为啥都是击败了100%用户）
- **解题思路**
没啥好讲的，就一次遍历，初始化`len`为0
- 如果数组当前值和val相同，那就不理他
- 如果数组当前值和val不相同，那就`nums[len++] = num[i];`
实在没什么好说的，那我就默写一遍代码吧

```java
class Solution{
    public int removeElement(int[] nums, int val){
        int len = 0;
        for(int i=0; i<nums.length; i++){
            if(nums[i] != val){
                nums[len++] = nums[i];
            }
        }
        return len;
    }   
}
```

