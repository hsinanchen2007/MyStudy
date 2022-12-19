### 解题思路
由题可知，每两个元素为一组，先求出解压后的列表相对应的数组空间大小。一组元素中，前一个元素是后一个元素的重复次数，此时使用for循环和while循环嵌套，将后一个元素值赋给解压后的数组同时将重复数目减一索引数目加一。

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int count = 0;
        for(int i = 0; i < nums.length; i += 2){
            count += nums[i];
        }
        int[] res = new int[count];
        int index = 0;
        for(int i = 0; i < nums.length; i += 2){
            while(nums[i] > 0){
                res[index] = nums[i+1];
                index++;
                nums[i]--;
            }
        }
        return res;
    }
}
```