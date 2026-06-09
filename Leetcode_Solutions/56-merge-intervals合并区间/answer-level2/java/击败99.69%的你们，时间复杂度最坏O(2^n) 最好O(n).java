### 解题思路
解题思路
从第一个起开始遍历，如果遇到重合的两个，把前面的数组置为无效区间【1.-1】，后面的置为重合区间。如果merge成功，挑出子循环继续父循环。


### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        int len = intervals.length;
        int mergeCount = 0;
        for(int i = 0; i< len; i++) {
            for(int j = i + 1; j<len; j++) {
                if(merge(intervals, i, j)) {
                    mergeCount++;
                    break;
                };
            }
        }
        
        int[][] res = new int[len - mergeCount][2];

        int index = 0;
        for(int i = 0; i< len; i++) {
           if(intervals[i][0] ==  1 && intervals[i][1]== -1) {
               continue;
           }
           res[index][0] =  intervals[i][0];
           res[index][1] =  intervals[i][1];
           index ++;
        }
        return res;

    }

    public boolean merge(int[][] intervals, int k, int j) {
        if(j <=  k) {
            return false;
        }
        if(intervals[k][1] == -1 && intervals[k][0] == 1) {
            return false;
        }
        if(intervals[j][1] == -1 && intervals[j][0] == 1) {
            return false;
        }
        if(intervals[k][0] < intervals[j][0] && intervals[k][1] < intervals[j][0]) {
            return false;
        }

        if(intervals[j][0] < intervals[k][0] && intervals[j][1] < intervals[k][0]) {
            return false;
        }

           int left = Math.min(intervals[k][0], intervals[j][0]);
           int right =  Math.max(intervals[k][1], intervals[j][1]);
           intervals[j][0] = left;
           intervals[j][1] = right;
           intervals[k][0] = 1;
           intervals[k][1] = -1;
           return true;


    }

![20191219133350.jpg](https://pic.leetcode-cn.com/9b3ab9ab4f9547a76109c1d7babfbb04c87c0790c7ff9157706c89ef45ccafe0-20191219133350.jpg)

}


```