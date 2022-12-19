整体思路为先找到插入位置的左下标和右下标：
分为两种情况，如果rightIndex < leftIndex,说明只需插入该项，不用改变原有数组
否则，将插入项与插入位置对应的项进行合并。
```
public static int[][] insert(int[][] intervals, int[] newInterval) {
        int length = intervals.length;
        if(length == 0)
            return new int[][]{newInterval};
        //寻找左右边界
        int leftIndex,rightIndex;
        int leftBound = 0, rightBound = length - 1,center = (leftBound+rightBound)/2;;
        int left = newInterval[0], right = newInterval[1];
        //寻找左边界
        while(leftBound <= rightBound){
            if(left < intervals[center][0])
                rightBound = center - 1;
            else if(left > intervals[center][1])
                leftBound = center + 1;
            else
                break;
            center = (leftBound+rightBound)/2;
        }
        leftIndex = left > intervals[center][1] ? center + 1 : center;
        leftBound = 0;rightBound = length - 1;center = (leftBound + rightBound+1)/2;
        //寻找右边界
        while (leftBound <= rightBound){
            if(right < intervals[center][0])
                rightBound = center - 1;
            else if(right > intervals[center][1])
                leftBound = center + 1;
            else
                break;
            center = (leftBound+rightBound+1)/2;
        }
        rightIndex = center == length ? center-1 : right < intervals[center][0] ? center - 1:center;
        int [][] ans = new int[length - (rightIndex - leftIndex)][2];
        //合并数组
        if (leftIndex > rightIndex)//在leftIndex上插入该元素
        {
            for (int i = 0, j = i; i < length; i++,j++) {
                if(i == leftIndex)
                {
                    ans[j] = newInterval;
                    ans[++j] = intervals[i];
                }
                else
                    ans[j] = intervals[i];

            }
            if(leftIndex == length)
                ans[length] = newInterval;
        }
        //合并leftIndex和rightIndex指向的项
        else {
            if(left > intervals[leftIndex][0] )
                left = intervals[leftIndex][0];
            if(right < intervals[rightIndex][1])
                right = intervals[rightIndex][1];
            for (int i = 0, j = i; i < length; i++,j++) {
                if(i == leftIndex){
                    ans[j][0] = left;
                    ans[j][1] = right;
                    i = rightIndex;
                }
                else
                    ans[j] = intervals[i];
            }
        }
        return ans;
    }
```
可以看到，时间复杂度因对数组进行插入或者合并，为O（N），空间复杂度也为O（N）。
寻找左右边界的二分查找感兴趣的可以简单合并一下。