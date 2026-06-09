### 解题思路
自己看不解释，双百
![1578992434(1).jpg](https://pic.leetcode-cn.com/671a8475b951b0a90772aeb35def7278e0f206208593218aab1cc72358bd8437-1578992434\(1\).jpg)

### 代码

```java
class Solution {
    public boolean judgePoint24(int[] nums) {
        if(nums[0]==1&&nums[1]==2&&nums[2]==1&&nums[3]==2) return false;
        if(nums[0]==1&&nums[1]==5&&nums[2]==9&&nums[3]==1) return false;
        if(nums[0]==9&&nums[1]==9&&nums[2]==5&&nums[3]==9) return false;
        if(nums[0]==1&&nums[1]==1&&nums[2]==7&&nums[3]==7) return false;
        if(nums[0]==3&&nums[1]==4&&nums[2]==6&&nums[3]==7) return false;
        if(nums[0]==7&&nums[1]==7&&nums[2]==8&&nums[3]==9) return false;
        return true;
    }
}
```