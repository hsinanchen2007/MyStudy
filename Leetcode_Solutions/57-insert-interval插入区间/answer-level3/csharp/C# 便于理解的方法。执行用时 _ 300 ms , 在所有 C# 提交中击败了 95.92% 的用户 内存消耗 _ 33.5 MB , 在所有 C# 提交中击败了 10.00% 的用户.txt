第一次写题解，毕竟粗糙。

思路很简单，就是把原数组分成三份。

将合并新区间后的区间称为x;
第一份，小于x的所有区间。 intervals[i][1] < newInterval[0]
第二份，x包括的所有区间。
第三份，大于x的所有区间。intervals[i][0] > newInterval[1]

第一部分和第三部分很好找，判断一下边界即可。

只要找出第二部分就可以了。
第二部分中有几种情况：

int left = newInterval[0];
int right = newInterval[1];

int arrLeft = intervals[i][0] ;
int arrRight = intervals[i][1];

第一种 left< arrLeft;
第二种 arrLeft< left < arrRight;
第三种 arrRight < right;
第四种 arrLeft < right < arrRight;

第一、二种情况确定左侧边界，
第三、四种情况确定右侧边界。

即可将结果中的第二份区间确定出来。

将这三份区间按顺序加入list中，再转化成数组，即可得到答案。

```
public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval) 
    {
        if(intervals.Length == 0) return new int[][]{new int[]{newInterval[0], newInterval[1]}}; 

        int n = intervals.Length;

        //用left和right记录新区间的左端和右端
        int left = newInterval[0];
        int right = newInterval[1];

        bool isTrue = false;
        List<int[]> resultList = new List<int[]>();

        for(int i = 0; i < n; i++)
        {

            //找到left存在于原数组的哪个区间中，将左端对其。
            //left = 原属组区间的左端
            //可能right也在此区间，所以不continue
            if(left >= intervals[i][0] && left <= intervals[i][1])
            {
                left = intervals[i][0];
            }

            //找到right在原数组的哪个区间中，右端对其。
            
            if (right >= intervals[i][0] && right <= intervals[i][1])
            {
                right = intervals[i][1];
                continue;
            }
            //原数组的区间在新区间内，直接continue，不做记录。
            if(intervals[i][0] > left && intervals[i][0] < right)
            {
                continue;
            }
            
            //新区间之后的所有区间，记录进list中
            //第一次需要将新区间合并后的区间记录下来。
            if(intervals[i][0] > right)
            {
                if(!isTrue)
                {
                    resultList.Add(new int[]{left, right});
                    isTrue = true;
                }
                resultList.Add(new int[]{intervals[i][0],intervals[i][1]});
                continue;
            }
            //新区间之前的所有区间，记录进list中
            if(intervals[i][1] < left)
            {
                resultList.Add(new int[]{intervals[i][0],intervals[i][1]});
                continue;
            }
        }
        //若没有新区间之后的区间，
        //将合并后的新区间加到list中
        if(!isTrue)
        {
            resultList.Add(new int[]{left, right});
            isTrue = true;
        }
        return resultList.ToArray();
    }
}
```
