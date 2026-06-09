### 解题思路
这道题需要自己列出几行数据，然后去寻找规律。先计算可以分到第count层，再计算count - 1层每个人能分到的糖果数，最后如果还有糖果剩余，继续分配。

### 代码

```java
class Solution {
    public static int[] distributeCandies(int candies, int num_people) {
        int count = 0;
        // 把1+2+3+...+n作为常数值
        int finalSum = num_people * (num_people + 1) / 2;
        int[] result = new int[num_people];
        if (candies == 0) {
            return result;
        }
        // 计算最终可以分到第几层
        while (true) {
            count++;
            candies -= (count - 1) * num_people * num_people + finalSum;
            if (candies <= 0) {
                break;
            }
        }
        int m = 0; // 第count - 1层的n的个数1,n+2,3n+3,6n+4
        for (int i = 1; i < count - 1; i++) {
            m = m + i;
        }
        int value = m * num_people + count - 1; // 第count - 1层的第一个人获得的糖果数
        for (int i = 0; i < num_people; i++) {
            result[i] = value + (count - 1) * i;
        }
        // 如果糖果刚好在count - 1层分发完
        if (candies == 0) {
            return result;
        }
        // 否则，为count层继续分发糖果
        m = 0;
        // 把循环里面count层减去的加回来
        candies += (count - 1) * num_people * num_people + finalSum;
        int remain = candies;
        // 如果分给第m + 1个人在count层应分配的糖果数之后，还有剩余，则继续分配，否则直接将糖果给到第m + 1个人
        candies = candies - ((count - 1) * num_people + m + 1);
        while (candies > 0) {
            result[m] += ((count - 1) * num_people + m + 1);
            remain = candies;
            m++;
            candies = candies - ((count - 1) * num_people + m + 1);
        }
        result[m] = result[m] + remain;
        return result;
    }
}
```