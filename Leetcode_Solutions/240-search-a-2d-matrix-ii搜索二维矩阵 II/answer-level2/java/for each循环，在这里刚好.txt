### 解题思路
因为看到是需要将数组中的元素拿出来与给定的结果比较，我就会想到需要将结果与数组中的每一个元素都做比较，直到与目标元素相等，然后输出true，如果遍历完一遍后都没有该目标元素存在，那么返回false。所以我第一想到的就是用遍历的方法，因为没有对数组下表进行操作，所以我选用的是for each循环

### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for(int[] arrs:matrix){
            for(int arr:arrs){
                if(arr==target)
                return true;
            }
        }
        return false;
    }
}
```