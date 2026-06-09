### 原题概述
给出一个区间的集合，请合并所有重叠的区间。

示例 1:
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

### 解题思路
* 典型的递归算法
* 按照区间起点进行排序，这个很关键
* 不确定元素个数情况下，采用LinkedList能够更加节省资源。

### 踩坑
* 如何终止递归函数，可以解决边界问题，没有考虑数组为空的情况出现错误，后来进行了判空处理
* 线性列表两两元素比较时，必须明确最后一个如何进行处理，否则容易出现丢时问题
* 走到最后一个元素时，本想给一个相同元素走完合并，虽然结果正确，但是递归结束条件被破坏了，函数出现堆栈溢出
* 分析之后，两两处理，最后一个一定在最前面经过处理了，走到最后一个的就不需要处理了。
* 为了不出现case5的情况，进行按照区间起点进行排序即可进行规避，否则思维上就会来回反复。

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        int rowLen = intervals.length;
        if (rowLen == 0 || rowLen == 1) {
            return intervals;
        }
        Arrays.sort(intervals, (int[] range1, int[] range2) -> range1[0] - range2[0]);
        // 根据情况可以选择下面这个排序
        // Arrays.sort(intervals,Comparator.comparingInt((int[] range)->range[0]));
        List<int[]> ans = new LinkedList<>();
        // 是否继续递归区合并的关键条件
        boolean bMerged = false;
        for (int i = 0; i < rowLen; i++) {
            int[] range1 = intervals[i];
            if(i == rowLen -1) {
                ans.add(range1);
                continue;
            }
            int[] range2 = intervals[i+1];
            if (range1[1] >= range2[0]) {
                int[] range = new int[2];
                range[0] = range1[0];
                range[1] = Math.max(range1[1], range2[1]);
                ans.add(range);
                bMerged = true;
                //两个合成1个，所以多加一个1
                i++;
            } else {
                    ans.add(range1);
            }
        }
        int[][] result = new int[ans.size()][2];
        int i = 0;
        for (int[] range : ans) {
            result[i++] = range;
        }

        if (!bMerged) {
            return result;
        }
        return merge(result);
    }
}
```

### 几何线段相交建模
先进行领域建模，也就是与现实世界保持一致的模型。
[[a0,a1],[b0,b1],...[n0,n1]]

#### case1: 相等: a0 == b0 && a1 == b1
```
a0--------a1
b0--------b1
```
结果： [a0,a1]
#### case2: 合并区间: a0 < b0 && a1 < b1
```
a0--------a1
     b0--------b1
```
结果： [a0,b1]
#### case3: 合并区间: a1 = b0
```
a0--------a1
          b0--------b1
```
结果： [a0,b1]

#### case4: 不合并区间: a1 < b0
```
a0--------a1
               b0--------b1
```
结果： [a0,b1]

#### case5: 合并区间: a0 > b0 && a1 > b1
```
     a0--------a1
b0--------b1
```
结果： [b0,a1]

#### case6: 合并区间: a0 = b1
```
          a0--------a1
b0--------b1
```
结果： [b0,a1]

#### case7: 不合并区间: a0 > b1
```
                 a0--------a1
b0--------b1
```
结果： [a0,a1] [b0,b1]
