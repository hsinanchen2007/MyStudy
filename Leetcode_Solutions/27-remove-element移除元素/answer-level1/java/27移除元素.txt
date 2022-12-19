### 解题思路
定义两个指针i，j,i表示删除等于val的数组下标，j表示原数组下标，如果nums[j] != val  ---> num[i++] = nums[j];否认j增加。

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if(nums == null || nums.length == 0) return 0;
        int i = 0;
        for(int j = 0; j < nums.length; j++){
            if( nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
}
```