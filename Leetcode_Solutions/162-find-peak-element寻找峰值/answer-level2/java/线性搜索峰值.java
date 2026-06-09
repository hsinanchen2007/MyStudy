### 解题思路
线性搜索，循环判断第i个元素的左右是否都比自己小，如果比自己小就返回
针对特殊长度的数组进行特殊处理

### 代码

```java
class Solution {
    public int findPeakElement(int[] nums) {
        if (nums.length == 1 || nums == null){
            return 0;
        } else if (nums.length == 2 ){
            if (nums[0] > nums[1]){
                return 0;
            } else{
                return 1;
            }
        }
       for (int i = 1; i < nums.length - 1; i++){
            if ( nums[i] > nums[i+1] && nums[i] > nums[i-1]){
                return i;
            }
            if ( nums.length == i +2){
                if (nums[i+1] > nums[i]){
                    return i+1;

                }
            }
        }
        return 0;
    }

    // public int findPeakElement(int[] nums) {
    //     for (int i = 0; i < nums.length - 1; i++) {
    //         //峰值的特性就是走下坡路，对应的就是i+1的值小于i的值
    //         if (nums[i] > nums[i + 1])
    //             return i;
    //     }
    //     return nums.length - 1;
    // }
}
```