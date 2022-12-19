```
// 说一下, 为什么刷题要用工具类!!
class Solution {
   public int[][] merge(int[][] intervals) {
        // 这里获取原有数组的长度, 目的是为了存储 intervals可能会因为合并区间而缩短长度的结果数组
        int oldLength = intervals.length;
        if (oldLength == 0){
            return intervals;
        }
        quickSort(intervals,0, intervals.length-1);

        // 定义prev,next, prev表示上一个比较的数组的索引, next是下一个比较数组的索引,
        int prev = 0, next = 1;
        while(next < oldLength){
            // 这里表示后一个数组的左区间小于等于下一个数组的右区间, 则进行合并
            if (intervals[next][0] <= intervals[prev][1]) {
                intervals[prev][1] = intervals[next][1] > intervals[prev][1] ? intervals[next][1] : intervals[prev][1];
            }else{
                intervals[++prev] = intervals[next];
            }
            next++;
        }

        // prev的返回结果就是有效数组长度的最后一个位置
        // 且因为有效数组是紧密排列的, 如果长度比原数组要小就需要将有效数组拷贝到一个新数组中
        if (prev < oldLength-1) {
            int[][] resultArr = new int[prev+1][2];
            copy(resultArr, intervals, 0, prev+1);
            return resultArr;
        }else { // 这里表示原数组没有进行过任何合并, 所以返回原有数组, 这里也包含了数组长度为0的情况
            return intervals;
        }
    }

    /**
     * 将一个数组从原数组拷贝到目标数组, 指定数组长度
     * @param target
     * @param source
     * @param length
     */
    private void copy (Object[] target, Object[] source, int start, int length) {
        int targetIndex = 0;
        for (int i = start; i < start+length; i++) {
            target[targetIndex++] = source[i];
        }
    }

    /**
     * 这里使用快速排序, 将二维数组按照内层数组的第一个数字将二维数组升序排列
     * @param intervals
     */
    private void quickSort(int[][] intervals, int leftBorder, int rightBorder){
        // 循环终止条件, 当只有一个元素时, 返回
        if (leftBorder == rightBorder) {
            return;
        }

        // 这里进行取中间值处理, 将中间值存放在rightBoder-1处
        midian3(intervals, leftBorder, rightBorder);

        // 如果长度在3或者3以下, 做完中间值处理就已经排好序了
        if(rightBorder - leftBorder < 3){
            return;
        }

        int left = leftBorder;
        int right = rightBorder-1;
        int midValueIndex = rightBorder-1;
        while (left < right){
            while (intervals[++left][0] <= intervals[midValueIndex][0] && left < midValueIndex);
           while (intervals[--right][0] >= intervals[midValueIndex][0] && right > leftBorder);
            if (left < right) {
                swap(intervals, left, right);
        }
        }
        // 整体交换结束后互换mid的值和left的值, 将left作为下层比较的中间结点
        swap(intervals, left, midValueIndex);

        // 本次排序结束, 进入下层排序, 将leftBorder-rightBorder分为两个区间,left作为中间断点 进行快速排序
        quickSort(intervals,leftBorder,left);
        quickSort(intervals,left+1,rightBorder);

    }

    /**
     * 以在左中右中取中间值的方式进行选择中间值
     * 这里使用的策略是 小放左, 大放右, 中间值放在right-1, 原因是中间位置不确定, 需要动态的寻找
     * @param intervals
     * @param left
     * @param right
     */
    private void midian3(int[][] intervals, int left, int right){
        int middle = (left+right)/2;
        // 这里使用冒泡排序的思想进行三个值互换,
        if(intervals[left][0] > intervals[middle][0]){
            swap(intervals, left, middle);
        }
        if(intervals[middle][0] > intervals[right][0]){
            swap(intervals, middle, right);
        }
        if(intervals[left][0] > intervals[middle][0]){
            swap(intervals, left, middle);
        }
        swap(intervals, middle, right-1);
    }


    /**
     * 互换外层数组中指定位置的两个数组
     * @param intervals
     * @param i1
     * @param i2
     */
    private void swap(int[][] intervals, int i1, int i2) {
        int[] temporaryArray = intervals[i1];
        intervals[i1] = intervals[i2];
        intervals[i2] = temporaryArray;
    }
}
```
