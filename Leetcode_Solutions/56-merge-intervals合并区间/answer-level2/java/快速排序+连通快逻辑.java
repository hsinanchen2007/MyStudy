### 解题思路
分为两步走
1，先对二维数组的左区间边界做快速排序
2，设置一个一维中间变量保存 合并后的连通快， 一个list保存合并后的连通快数组
3，遍历排序后的数据 如果当前数组右边界大于次级左边界 存合并后的连通快到list
如果不是，合并这个数组，最大值取当前连通快和当前数组的最大右边界

attention !!!!
遍历到最后一个时，不要忘记最后一个连通快赋值到list中 

最后，返回list的toArray方法即可

### 代码

```java
import java.util.List;
import java.util.ArrayList;
import java.lang.Math;
class Solution {
    public int[][] merge(int[][] intervals) {
        
        if (intervals.length <= 1) {
            return intervals;
        }

        //数组排序 连通快-快排排序
        quickSort(intervals, 0, intervals.length - 1);

        //保存新的排序数组
        List<int[]> list = new ArrayList<int[]>();

        //保存一个中间数组
        int[] tempArr = intervals[0];

        //遍历二维矩阵
        for (int i = 1; i < intervals.length; i++) {
            if (tempArr[1] < intervals[i][0]) {//右区间小于次数组的左区间 不能合并
                list.add(tempArr);
                tempArr = intervals[i];//中间数组重新赋值
            } else if (tempArr[1] >= intervals[i][0]) {//合并数组
                tempArr[1] = Math.max(tempArr[1], intervals[i][1]);
            }
            if (i == intervals.length - 1) {//如果循环到了最后一位 增加到列表值
                list.add(tempArr);
            }
        }
        
        return list.toArray(new int[0][]);
    }


    //quicksort - 快速排序
    private void quickSort(int[][] intervals, int low, int high){
        
        //快速
        int i = low;

        int j = high;

        //递归中止条件
        if (i >= j) {
            return;
        }

        //基准值
        int sentry = intervals[low][0];
        int[] sentryArr = intervals[low];

        //循环 两边扫描数组
        while (i < j) {
             //从右向左扫描 找到第一个小于基准值的数 右哨兵 细节 基准值必须等于 这是为了确保右边的值在左边 不然就会出现等于基准值在右边 attention
             while (i < j && sentry <= intervals[j][0]) {
                j--;
             }
             
             //从左向右扫描 找到第一个大于基准值的数 左哨兵
             while (i < j && sentry >= intervals[i][0]) {
                i++;
             }

             if (i < j) {//找到了 两个哨兵值
                 int[] temp = intervals[i];
                 intervals[i] = intervals[j]; 
                 intervals[j] = temp;
             }
        }

        //交互基准值 此时i和j已相遇 基准值此时应该在中间
        intervals[low] = intervals[i];
        intervals[i]   = sentryArr;

        //递归左区间 i中间值为准
        quickSort(intervals, low, i-1);

        //递归右区间 
        quickSort(intervals, i+1, high);
    }
}
```