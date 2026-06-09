### 解题思路
对于类似的投票问题，是否都应该进行检验
如果给定[1,1,2,2,3],此时for循环结束后，temp的值等于3，但它并不是其中最大的，必须有相应的条件进行检验判定。

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {/*投票算法*/
        int temp=nums[0];
        int count=1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]==temp)
            count++;
            if(nums[i]!=temp)
            count--;
            if(count==0){
                temp=nums[i];
                count=1;//[1,1,2,2,3]
            }
        }
        int c=nums.length/2;
        count=1;
        for(int num:nums){
        if(temp==num)count++;
        if(count>c)
        return temp;
        }
        return -1;
    }
}
```