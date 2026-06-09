### 解题思路
递归
执行用时 :2 ms, 在所有 Java 提交中击败了54.05%的用户
内存消耗 :37.9 MB, 在所有 Java 提交中击败了84.66%的用户
### 代码

```java
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            List<Integer> list = new ArrayList<>();
            result.add(list);
            return result;
        }
        if (nums.length == 1) {
            List<Integer> list = new ArrayList<>();
            list.add(nums[0]);
            result.add(list);
            return result;
        }
        int length = nums.length;
        for (int i = 0; i < length; i++) {
            int num = nums[i];
            // int[] newNums = ArrayUtils.remove(nums,i);
            int[] newNums = new int[length - 1];
            System.arraycopy(nums, 0, newNums, 0, i);
            if (i < length - 1) {
                System.arraycopy(nums, i + 1, newNums, i, length - i - 1);
            }
            List<List<Integer>> wtf = permute(newNums);
            for (List<Integer> l : wtf) {
                l.add(num);
                result.add(l);
            }
        }
        return result;
    }
}
```