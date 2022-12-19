**思考：**
&emsp;这一题真的很有意思，用动态规划可以很直观的解决问题。还是需要不断的深入动态规划的概念，**动态规划第一要义就是找到动态转移方程，**当前的状态是如何从前一个状态得到，然后处理边界值。对于这一题，新状态就是再右边增加柱子，然后用dp[n]存储到下标为n的柱子能容纳多少水。

**思路过程：**
&emsp;**1、首先找到起始的下标**（做剪枝），找到第一个不开始递增的值（第一个峰值），然后遍历到最后一根柱子

&emsp;**2、思考动态转移方程**，对于新柱子的到来，会出现以下的情况：
                        
&emsp;&emsp;2.1. 新柱子小于等于上一根柱子，那么存水量与前一个状态相同，转移方程为：**dp[i] = dp[i-1]**
&emsp;&emsp;2.2. 新柱子大于最后一根，需要找到前面的第一根最高的柱子（第一根最大是为了避免存在同样高的柱子），下标为preIndex，称为前最高柱柱子。对于找到的前最高柱子有以下两种情况
&emsp;&emsp;&emsp;(1) 前最高柱柱子小于等于新柱子，则前最高柱柱子与新柱子之间的存水量=（间距*前最高柱柱子高度） - 之间柱子占用的面积，
&emsp;&emsp;&emsp;(2) 前最高柱柱子大于新柱子，则前最高柱柱子与新柱子之间的存水量=（间距*新柱子高度） - 之间柱子占用的面积。
&emsp;&emsp;&emsp;假设高度为maxHeight，间距为wide，柱子之间占用面积为block，**转移方程为 dp[i] = dp[preIndex] + maxHeight*wide-block**

&emsp;**3、还要考虑一种特殊情况**，比如{3,2,2,2,3,4,5}，对于后面的5，如果处理方式按照2.2.2处理，会错误的减去了高度为4的柱子的占用面积，这种情况为当前柱子和前一个柱子都大于等于任何条件情况下的最高柱子的高度prehigh，这种情况只需要直接移动即可，状态转移方程为**dp[i] = dp[i-1]**

&emsp;根据上面的思路，可以写出代码：
```
 public int trap(int[] height) {
        int n = height.length;
        //最少需要3根柱子才能装雨水
        if (n < 3) {
            return 0;
        }
        int[] dp = new int[n];

        //找到第一个不开始递增的值,作为左起点（剪枝）
        int left = 0, right = n - 1;
        for (int i = 1; i < n - 1; i++) {
            if (height[i] < height[i - 1]) {
                left = i - 1;
                break;
            }
        }
        //左起点不存在、左右重合或者左右起点之间为1根的情况（不可能存放雨水）
        if (left < 0 || right - left <= 1) {
            return 0;
        }

        //任何条件情况下的最高柱子的高度prehigh
        int prehigh = height[left];
        //遍历每一根新柱子
        for (int i = left + 1; i <= right; i++) {
            prehigh = Math.max(prehigh, height[i - 1]);//放在开始则比较上一个柱子

            //2.2.1新柱子小于等于上一根柱子
            if (height[i] <= height[i - 1]) {
                dp[i] = dp[i - 1];
                continue;
            }
            //2.2.3当前柱子和前一个柱子都大于等于前最高柱子
            if (i > left + 1 && height[i] >= prehigh && height[i - 1] >= prehigh) {
                dp[i] = dp[i - 1];
                continue;
            }

            //从右到左找到第一根最高的柱子
            int maxHeight = Integer.MIN_VALUE;//符合要求的柱子的高度，也可能为新柱子的高度
            int preIndex = -1;//符合要求的柱子index
            for (int j = i - 1; j >= left; j--) {
                //遇到比当前柱子还高的第一根柱子，剪枝
                if (height[j] >= height[i]) {
                    preIndex = j;
                    maxHeight = height[i];//最大高度只能为新柱子
                    break;
                }
                //找到最大的不超过新柱子高度的柱子，maxHeight使用等号，因此取第一个
                if (maxHeight < height[j]) {
                    preIndex = j;
                    maxHeight = height[j];
                }
            }

            //新柱子和符合要求的柱子之间的占用位置
            int black = 0;
            for (int k = preIndex + 1; k <= i - 1; k++) {
                black += height[k];
            }

            dp[i] = dp[preIndex] + (i - preIndex - 1) * maxHeight - black;
        }

        return dp[right];
    }
```

深入理解属于动态规划一道不错的题目，推荐继续研究接雨水二。