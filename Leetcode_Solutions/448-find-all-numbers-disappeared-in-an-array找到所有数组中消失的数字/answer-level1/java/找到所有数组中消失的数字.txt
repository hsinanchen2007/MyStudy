### 解题思路
数据范围是1到n，对应下标为0到n-1，故正确放置位置的数据应该满足nums[i] == i + 1
根据该条件对数据进行位置交换，如果发现重复数据则停止交换，最后遍历时将不满足的（下标+1）取出

### 代码

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        for (int i = 0; i < nums.length; i ++) {
            while (nums[i] != i + 1) {
                int temp = nums[i];
                if (nums[temp-1] == temp) {
                    break;
                }
                
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }
        }
        
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < nums.length; i ++) {
            if (nums[i] != i + 1) {
                result.add(i + 1);
            }
        }
        
        return result;
    }
}
```