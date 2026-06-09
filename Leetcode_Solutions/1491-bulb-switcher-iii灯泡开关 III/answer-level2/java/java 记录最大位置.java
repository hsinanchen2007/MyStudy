### 思路
遍历数组，记录当前最大亮起来的灯，如果最大亮起来的灯等于遍历过的灯的数量，那么说明前面灯都亮了。举个例子，`[2,1,3]`，当遍历到3的时候，最大的灯是3，等于当前已经亮起来的灯的个数，因此3左侧的灯全部亮了，算一个可行解。

```java
    public int numTimesAllBlue(int[] light) {
        int ans = 0;
        int curMax = 0;
        for (int i = 0; i < light.length; i++) {
            curMax = Math.max(curMax, light[i]);
            if (curMax == i + 1) {
                ans++;
            }
        }
        return ans;
    }
```