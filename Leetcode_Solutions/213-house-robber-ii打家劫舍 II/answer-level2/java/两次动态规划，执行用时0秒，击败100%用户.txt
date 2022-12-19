### 解题思路
先判断数组长度=0和=1的情况，之后为了避免首尾同时取值，把数组进行两次初始化，一个是从0到nums.lenth-1，另一个是1到nums.length，这样把问题化解为简单的隔项打劫，返回两者最大值

### 代码

```java
class Solution {
    public int rob(int[] nums) {
    int a=0,b=0,d=0,e=0;
    if(nums.length==0)
    return 0;
    if(nums.length==1)
    return nums[0];
    for(int i=0;i<nums.length-1;i++){
        int c=Math.max(b,a+nums[i]);
        a=b;
        b=c;
    }
    for(int i=1;i<nums.length;i++){
      int f=Math.max(e,d+nums[i]);
       d=e;
       e=f;
    }
    return b>e?b:e;
    }
}
```