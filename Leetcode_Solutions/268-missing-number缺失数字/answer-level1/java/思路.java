### 解题思路
此处撰写解题思路
我的思路:
    先将数组都从小到大排序好，再通过遍历数组，判断元素和下标是否相同，不相同就直接返回当前下标
数组都相同的话就直接返回数组的长度;
### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        for(int g=nums.length/2;g>=1;g/=2){
            for(int i=g;i<nums.length;i++){
                int j=i;
                int temp=nums[j];
                while(j-g>=0 && temp<nums[j-g]){
                    nums[j]=nums[j-g];
                    j-=g;
                }
                nums[j]=temp;
            }
        }
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return nums.length;
    }
}
```