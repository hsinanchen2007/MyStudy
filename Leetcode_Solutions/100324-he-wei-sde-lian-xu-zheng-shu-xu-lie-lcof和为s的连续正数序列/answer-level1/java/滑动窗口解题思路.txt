### 解题思路
滑动窗口
1，先求最大可用的窗口
2，获取到最大到窗口后，左指针右移，收缩窗口范围
不断寻找，直到找到所以到窗口为止

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
       
        //保存结果值
        List<int[]> list = new ArrayList<>();


        //和为target 最大值不超过target/2
        int maxValue = target/2;

        //滑动窗口题解
        int left = 1;//左指针
        int right = 1;//右指针

        //总和
        int sum = 0;

        while (left <= maxValue) {
             if (sum < target) {//右指针一直向右滑动
                 sum += right;
                 right++;
             } else if (sum > target) {//左指针一直向右滑动
                 sum -= left;
                 left++;
             } else {//找到了值
                 int[] item = new int[right - left];
                 for (int i = left; i < right; i++) {
                     item[i-left] = i;
                 }
                 list.add(item);
                 sum -= left;
                 left++;
             } 
        }

        return list.toArray(new int[list.size()][]);
    }
}
```