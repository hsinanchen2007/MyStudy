### 解题思路
此处撰写解题思路
利用双指针，直接在数组上赋值。

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int len=nums.length;
        int j=0;
        for(int i=0;i<len;i++){
            if(nums[i]!=val){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;

    }
}
```