### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int a=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=i){
                a=i;
                break;
            }
            else{
                a=nums[nums.length-1]+1;
            }
        }
        return a;
    }
}
```