### 解题思路
![image.png](https://pic.leetcode-cn.com/9bd5d46941c6701b374ffa70b663968cb75376e99020edf32f57fcd1545dda0b-image.png)
由图可以发现，遍历数组，计算当前柱子与前面柱子凹槽面积，
计算时机是：当数组递增（斜率>0）、递减、或者为最后一列时
计算大小：min(h[i], 左边第一个比h[i]大的，或者左边最大的但比h[i]小的h）* (i -lefti-1) - (sum[i-1]-sum[lefti])
存储，把柱高以单调递减存储，每次压时将比自己小的都pop出来，压栈时计算其与前一个峰值的凹槽，可以快速获得第一个比hi[i]大的或者最大的


### 代码

```java
class Solution {
    public int trap(int[] height) {
        if (height.length==0) return 0;
        LinkedList<Integer> topIndex = new LinkedList<>();
        Map<Integer, Integer> prew = new HashMap<>();
        int[] sum = sum(height);
        int res = 0;
        for (int i=0;i<height.length;i++) {
            if (i==0||height[i]>height[i-1]||i==height.length-1 || height[i]>height[i+1]) { //i是峰值
                if (topIndex.isEmpty()) {
                    topIndex.push(i); //第一个峰值
                } else { //形成凹槽
                    int lefti = topIndex.peekLast();
                    while (!topIndex.isEmpty()&&height[topIndex.peek()]<height[i]) { //保持递减 找到第一个比hi[i]大的
                        lefti = topIndex.pop();
                        if (!topIndex.isEmpty()&&prew.containsKey(lefti)) {
                            res -= prew.get(lefti); // 减去中间的小凹槽面积
                        }
                    }
                    if (!topIndex.isEmpty()) {
                        lefti = topIndex.peek();//此时的栈顶
                    }
                    int cur = (i -lefti-1)*Math.min(height[lefti], height[i])-(sum[i-1]-sum[lefti]); // 取左边最大峰值求取凹槽面积
                    if (cur>0) {
                        res+=cur;
                        prew.put(i, cur);
                    }
                    topIndex.push(i);
                }
            }
        }
        return res;
    }
    int[] sum(int[] h) {
        int[] sum = new int[h.length];
        sum[0] = h[0];
        for (int i=1;i<h.length;i++) {
            sum[i] = sum[i-1]+h[i];
        }
        return sum;
    }

}
```