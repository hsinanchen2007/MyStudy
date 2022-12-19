### 解题思路
连续正整数，那就是用滑动窗口了，双指针，并且因为范围为 < n / 2

### 代码

```java
class Solution {

    /**
    * 连续正整数，那就是用滑动窗口了，双指针，并且因为范围为 < n / 2
    **/
    public int[][] findContinuousSequence(int target) {
        // 初始化窗口指针和返回结果
        int left = 1;
        int right = 2;
        List<List<Integer>> result = new ArrayList<> (10);

        int maxLen = -1;
        // 滑动窗口的右边界不能超过target的中值
        while (right <= (target/2 + 1)) {
            // 计算当前窗口内数字之和
            int curSum = 0;
            for (int i = left; i <= right + 1; i++) {
                curSum += i;
            }
            // 若和小于目标，右指针向右移动，扩大窗口
            if (curSum < target) {
                right++;
            } else if (curSum > target) {
                // 若和大于目标，左指针向右移动，减小窗口
                left++;
            } else {
                // 相等就把指针形成的窗口添加进 输出列表中
                List<Integer> item = new ArrayList();
                for (int i = left; i <= right + 1; i++) {
                    item.add(i);
                }
                if (maxLen < item.size()) {
                    maxLen = item.size();
                }
                result.add(item);
                right++;
            }
        }
        int[][] resArr = new int[result.size()][];
        int counter = 0;
        for (List<Integer> item : result) {
            int[] itemArr = new int[item.size()];
            int counter2 = 0;
            for (Integer item2 : item) {
                itemArr[counter2] = item2;
                counter2++;
            }
            resArr[counter] = itemArr;
            counter++;
        }
        return resArr;
    }
}
```