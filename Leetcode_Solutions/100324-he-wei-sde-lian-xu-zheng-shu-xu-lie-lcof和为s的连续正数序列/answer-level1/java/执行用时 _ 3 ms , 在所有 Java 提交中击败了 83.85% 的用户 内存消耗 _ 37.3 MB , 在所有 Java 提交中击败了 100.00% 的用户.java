### 解题思路


### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        int len = target / 2 + 2;
        int i = 2;
        int sum = 1;
        int start = 1;
        // 将起始点和结束点塞进队列
        Queue<Integer> queue = new LinkedList<>();
        while (i <= len) {
            if (sum == target) {
                // 如果sum==target,则sum减去当前起始点，加上当前终点i，然后起始点往后推移一位，结束点往后推移。
                if (start == i) {
                    break;
                }
                queue.add(start);
                queue.add(i - 1);
                sum = sum - start + i;
                start += 1;
                i++;
                continue;
            } else if (sum < target){
                // 如果sum<target,则sum加上当前终止点i，终止点i往后推移一位
                sum += i++;
                continue;
            }
            // 如果sum>target且起始点小于终止点,则sum减去当前起始点，起始点start往后推移一位
            while (start < i && sum > target) {
                sum -= start++;
            }
        }
        int queueLen = queue.size() / 2;
        int[][] result = new int[queueLen][];
        for (int n = 0; n < queueLen; n++) {
            // 从队列中取出每一次匹配好的起始点和终止点，进行赋值
            start = queue.remove();
            sum = queue.remove();
            int[] temp = new int[sum - start + 1];
            int k = 0;
            for (int j = start; j <= sum; j++) {
                temp[k++] = j;
            }
            result[n] = temp;
        }
        return result;
    }
}
```