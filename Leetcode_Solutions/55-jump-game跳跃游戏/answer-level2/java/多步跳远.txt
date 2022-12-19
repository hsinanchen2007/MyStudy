### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        int farest=0;//最远的位置下标
        int len=nums.length;
        for(int i=0;i<len-1;i++){
            farest=Math.max(farest,i+nums[i]);
            if(farest<i+1){//如果没达到，说明前面的都无法达到这个位置，卡住了，跳不过去
                return false;
            }
        }
        return farest>=len-1;
    }
}
```