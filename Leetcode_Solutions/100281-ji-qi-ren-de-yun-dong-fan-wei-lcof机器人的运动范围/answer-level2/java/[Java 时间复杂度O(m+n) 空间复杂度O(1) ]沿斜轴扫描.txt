### 解题思路
按 ij = i+j 扫描
![下载 (3).png](https://pic.leetcode-cn.com/5adcf2bb1cc677d86ddeae32f01cb00aa923b13138bbbed04ddb0a37a7cdd005-%E4%B8%8B%E8%BD%BD%20\(3\).png)

1.先假设 m,n 无穷大的情况

1.1
计算全宽度 fullWidth 每行增加 deltaFullWidth = 1

1.2.1
第一个周期内 同一行数值 为 smallValue
这部分宽度每次增加 deltaSmallWidth = 1

1.2.2
会在每次 ij % 10 节点，会发生数值分歧
1.2.2.1
一部分数值为 greatValue = smallValue 宽度此时等于 全宽度
1.2.2.2
另一部分数值为 smallValue = 0 初始宽度 SmallWidth 0  
这部分宽度增加速度在下个节点前恒定比上个节点多 1 
deltaSmallWidth = deltaSmallWidth + 1 

持续扫描，在 k < smallValue 时结束。


2.处理边界被切割的情况
![下载.png](https://pic.leetcode-cn.com/2936a2e24138ac6b43dc2428ef63ed8bb105390189022c87170aa25493b46860-%E4%B8%8B%E8%BD%BD.png)

2.1
假设另一边无限远
2.1.1
第一次越过切割点时
2.1.1.1
计算全宽度 停止增长 deltaFullWidth = 0
2.1.1.2
因为边界天然为小值区
deltaSmallWidth = deltaSmallWidth - 1 
2.1.2
此后每隔10的距离
2.1.2.1
因为边界天然为小值区
deltaSmallWidth = deltaSmallWidth - 1 

2.2
两边切割点都被越过时
2.2.1
计算全宽度 开始减小 deltaFullWidth = -1
2.2.2
计算全宽度为 0 时，停止扫描。

整理以上全部条件，合理初始化后，解决问题
![下载 (5).png](https://pic.leetcode-cn.com/2c5ddc12f437284e1951340ec7db9f715cf519a7601a6df5bc325ca6b51ef9af-%E4%B8%8B%E8%BD%BD%20\(5\).png)


注 因为本题 i,j 取值为 2 位数
数值分歧只有2种情况

数值大小和数值分歧种类关系  distinct = log(n)
推测 m,n 取值扩大后，如能妥善处理数值分歧
算法时间复杂度为 O((m+n)log(m+n))
算法空间复杂度为 O(m+n)

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        int smallWidth = 0;
        int smallValue = -1;
        int greatValue = -1;
        int fullWidth = 0;
        int deltaSmallWidth = 1;
        int mDeltaFullWidth = 1, nDeltaFullWidth = 1;
        int deltaFullWidth = mDeltaFullWidth + nDeltaFullWidth - 1;
        int o = 10;
        int ret = 0;
        for (int ij = 1; smallValue <= k; ij++) {
            // System.out.print(smallWidth + "," + fullWidth + "," + ij + "\t\t");
            // System.out.println(smallValue + "," + greatValue);
            if (greatValue > k) {
                ret += smallWidth;
            } else {
                ret += fullWidth;
            }

            smallValue++;
            greatValue++;
            if (o-- == 0) {
                deltaSmallWidth++;
                o = 9;
                greatValue = smallValue;
                smallValue = ij / 10;
                smallWidth = 0;
                // System.out.println(smallWidth);
            }

            if (m-- == 0) {
                deltaSmallWidth--;
                deltaFullWidth = (mDeltaFullWidth = 0) + nDeltaFullWidth - 1;
                m = 9;
            }
            if (n-- == 0) {
                deltaSmallWidth--;
                deltaFullWidth = mDeltaFullWidth + (nDeltaFullWidth = 0) - 1;
                n = 9;
            }

            smallWidth += deltaSmallWidth;
            fullWidth += deltaFullWidth;
            if (fullWidth == 0) {
                break;
            }
        }
        return ret;
    }
}
```