### 解题思路
因为数组已经是有序的，所以只需要将前后进行比较是否会出现重复，重复则使用temp变量将其覆盖。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int temp=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=nums[temp]){
                temp++;
                nums[temp]=nums[i];
            }
        }
        temp+=1;
        return temp;
    }
}
```