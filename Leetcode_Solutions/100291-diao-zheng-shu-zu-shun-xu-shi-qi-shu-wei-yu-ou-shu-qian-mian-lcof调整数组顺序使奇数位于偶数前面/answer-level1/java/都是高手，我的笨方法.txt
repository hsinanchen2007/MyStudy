### 解题思路
一个list存偶数，一个list存奇数，然后遍历修改原数组，效率比较低。

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        List<Integer> jishu = new ArrayList<>();
        List<Integer> oushu = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] % 2 == 0) {
                oushu.add(nums[i]);
            } else {
                jishu.add(nums[i]);
            }
        }

        int jishuLength = jishu.size();
        for (int i = 0; i < jishuLength; i++) {
            nums[i] = jishu.get(i);
        }

        int oushuBegin= 0;
        for (int i = jishuLength; i < nums.length; i++) {
            nums[i] = oushu.get(oushuBegin++);
        }
        return nums;
    }
}
```