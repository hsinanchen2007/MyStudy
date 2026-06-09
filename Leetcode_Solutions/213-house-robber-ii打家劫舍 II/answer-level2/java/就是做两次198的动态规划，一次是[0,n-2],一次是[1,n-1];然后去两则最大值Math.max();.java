### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length==1) return nums[0];
       return Math.max(helper1(nums),helper2(nums));
}
public int helper1(int[] nums){
        int a=0,b=0;
        for (int i = 0;i<nums.length-1;i++){
                int c = Math.max(b,a+nums[i]); //此处为在接收a预约还是b预约取价值最大者
                a=b;
                b=c;
        }
        return b;
}
public int helper2(int[] nums){
        int a=0,b=0;
        for (int i = 1;i<nums.length;i++){
                int c = Math.max(b,a+nums[i]); //此处为在接收a预约还是b预约取价值最大者
                a=b;
                b=c;
        }
        return b;
}


}
```