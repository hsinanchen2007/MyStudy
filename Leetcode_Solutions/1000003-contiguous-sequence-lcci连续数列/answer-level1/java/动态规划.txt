### 解题思路
没有思路，干就完了。

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
int b=nums[0];
int sum=nums[0];
for(int i=1;i<nums.length;i++){
    if(b<0){
        b=nums[i];
    }else{
        b+=nums[i];
    }
    if(b>sum) sum=b;
}


return sum;
    }
}
```