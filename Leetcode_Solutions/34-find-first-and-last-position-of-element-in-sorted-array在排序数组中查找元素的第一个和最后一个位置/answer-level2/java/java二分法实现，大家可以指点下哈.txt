### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :42.5 MB, 在所有 Java 提交中击败了43.94%的用户

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = {-1, -1};
        int length = nums.length;

        if(length == 0 || nums == null)
            return res;

        int start = 0, end = length, middle = 0;
        while (true) {
            middle = (start + end) / 2;
            if(start > end || middle > length - 1) {
                middle = length;
                break;
            }
            if(target == nums[middle])
                break;
            else {
                if(target > nums[middle])
                    start = middle + 1;
                else
                    end = middle - 1;
            }
        }

        if(middle == length) {
            return res;
        }else  {
            int i, j;
            //往前遍历
            for(i = middle; i > -1; i--) {
                if(nums[i] != target)
                    break;
            }
            //往后遍历
            for( j = middle; j < length; j++){
                if(nums[j] != target)
                    break;
            }
            res[0] = i + 1;
            res[1] = j - 1;
            return res;
        }
    }
}
```