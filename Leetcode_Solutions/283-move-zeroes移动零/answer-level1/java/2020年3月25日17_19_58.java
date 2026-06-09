### 解题思路
通过两个指针进行，i进行循环遍历，遇到不是0的元素就添加到以j为下标的数组中，遇到不是0的元素，对j进行叠加。
然后i循环一遍之后就只剩下全是0的元素了，然后对j下标以后的空间进行添加0操作

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        if(nums == null){
            return;
        }
        /**
            先进行遍历，遇到不是0的数组元素 就依次累计的放前面
        **/
        int j = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] != 0){
                nums[j++] = nums[i];
            }
        }
        
        for(int i = j; i < nums.length; i++){
            nums[i] = 0;
        }

    }
}
```