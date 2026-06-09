### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    int[] mem ;
    public boolean canJump(int[] nums) {
        mem=new int[nums.length];
        return  dfs(0,nums);
    }
    public boolean  dfs(int index,int[] nums){
        if(index>=nums.length-1) return true;
        if(mem[index]!=0) return mem[index]==1?true:false;
        for(int i=index;i<index+nums[index];i++){
            // 不能在原地跳
            if(dfs(i+1,nums)) {
                mem[i+1] = 1;
                return true;
            }
        }
        mem[index] = 2;
        return false;
    }
}
```