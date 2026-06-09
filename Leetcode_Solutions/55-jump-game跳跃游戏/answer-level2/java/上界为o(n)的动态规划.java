### 解题思路
最笨，看代码吧
，尴尬
### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        int j=0;
        if(nums.length==1)
            return true;
        for(int i=nums.length-2;i>=0;i--){
            if(nums[i]!=0){
                nums[i]=-1;
                continue;
            }
            for(j=i-1;j>=0;j--){
                if(nums[j]>i-j){
                    nums[j]=-1;
                    break;
                }
            }
            i=j;
            if(i<0)
                break;
        }
        if(nums[0]==-1)
            return true;
        return false;
    }
}
```