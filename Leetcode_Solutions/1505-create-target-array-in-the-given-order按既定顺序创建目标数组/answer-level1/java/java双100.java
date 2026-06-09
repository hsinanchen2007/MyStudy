### 解题思路
关键是判断填充的时候target数组中是否已经被填充，是的话就给新的填充挪位置（target当前下标开始的数组的往后移动）

### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int len = nums.length;
        int[] targetArr = new int[len];
        Arrays.fill(targetArr, -1);
        for (int i = 0; i < len; i++) {
            int curIdx = index[i];
            int curNum = nums[i];
            if (targetArr[curIdx] != -1) {
                for (int j = len - 1; j > curIdx; j--) {
                    targetArr[j] = targetArr[j - 1];
                }
            }
            targetArr[curIdx] = curNum;
        }
        return targetArr;
    }
}
```