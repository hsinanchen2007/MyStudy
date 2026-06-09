### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
//使用最小堆来解，使用C++中的priority_queue容器，
1、排序：按照会议开始时间进行排序，使用sort()方法，注意第三个参数的写法（一般都用lamda）。被坑的很惨。
2、定义一个按照升序排列的priorty_queue队列，第三个参数使用greater<int>.如果是降序排列，则使用less<int>
3、比较当前会议的开始时间和priorty_queue队列中最早结束的会议时间，做如下操作：
   如果当前会议开始时间>=最早的会议结束时间：不需要新增会议室。将最早的会议结束时间更新为当前会议的结束时间
   如果当前会议开始时间<最早的会议结束时间：则需要新增会议室。将当前会议技术间push到priority_queue队列中
4、全部比较完成之后：priority_queue队列的size就是需要的会议室个数。
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if(size <= 0){
            return 0;
        }

        sort(intervals.begin(),intervals.end(),cmp);//按照会议开始时间升序排列会议。

        priority_queue<int,vector<int>,greater<int>> q;//定义优先级队列，里面按照升序存储会议结束的时间，也就是最早结束的会议时间放在队列的top位置。
        q.push(intervals[0][1]);

        for(int i = 1;i < size;i++){
            if(intervals[i][0] >= q.top()){//下一个会议时间大于之前会议的最早时间，说明不需要新增会议室，只需将当前会议的结束时间push到队列中即可。
                q.pop();
                q.push(intervals[i][1]);
            }else{//否则就要新增会议室，方法就是将当前会议的结束时间push到队列中。
                q.push(intervals[i][1]);
            }
        }

        return q.size();
    }

    static bool cmp(const vector<int> &a,const vector<int> &b){//sort()排序函数的第三个参数。
        return a[0] < b[0];
    }
};
```