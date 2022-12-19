### 解题思路
首先按照右区间进行排序，然后再判断其是否有 重叠。
贪心的思路是，只要按照此顺序的区间与前一个区间没有重叠，那后面的也不可能重叠。
所以如果重叠的话，将省了一支箭，并将其base区间换成其重叠部分。否则，若没有重叠，
直接将此区间设为base区间。
具体的操作使用了双指针的方法。
这个方法首先进行了排序，后面又是个遍历。反正执行用时，内存消耗都很大。我后面再想办法优化吧。

### 代码

```cpp
class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
        {
            return 0;
        }
        sort(points.begin(), points.end(), cmp);
        //int i = 0;
        int begin = points[0][0];
        int end = points[0][1];
        int j = 1;
        for(int i = 1 ;i<points.size();i++)
        {
            if(points[i][0]<=end) //说明有重叠
            {
                
                //end = ponits[i][0];
                begin = begin<=points[i][0]?begin:points[i][0];
            }
            else  //没有重叠时，base区间换掉
            {
                begin = points[i][0];
                end = points[i][1];
                j++;
            }

        }
        return j;
        

    }
};
```