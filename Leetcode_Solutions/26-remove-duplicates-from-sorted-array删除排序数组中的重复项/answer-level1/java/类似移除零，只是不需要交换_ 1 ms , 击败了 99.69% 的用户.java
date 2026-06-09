### 解题思路
两个指针，i用来遍历，j用来记录要赋值的角标位置，同时也是返回值
由于是排好序的数组，只对比当前数是否等于下一位数即可

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int j=0;
        for(int i=0;i<nums.length;i++){
            while(i<nums.length-1&&nums[i]==nums[i+1]){
                i++;
            }
            nums[j] = nums[i];
            j++;
        }
        return j;
    }
}
```