### 解题思路
本来偷懒使用暴力求解，结果超时了。。。
使用map将每个区间的起始点和区间位置映射，然后利用sort函数将每个区间的起始点进行升序，然后对于每个区间的终点，在已经排序的数组中进行二分查找（因为有的区间可能不存在右侧区间，所以使用二分查找右侧边界），详细解释见注释
### 代码

```cpp
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size(), -1);  //答案数组，初始化为-1
        map<int, int> valToint;  //起始点和区间位置的映射map
        vector<int> ints;  //存储每个区间的起始点
        for(int i = 0; i < intervals.size(); i ++)
        {
            valToint[intervals[i][0]] = i;
            ints.push_back(intervals[i][0]);
        }
        sort(ints.begin(), ints.end());  //对起始点进行排序
        for(int i = 0; i < intervals.size(); i ++)
        {
            int left = 0, right = ints.size(), target = intervals[i][intervals[i].size()-1];
            while(left < right)  //二分查找右侧边界，若target存在，则返回target的位置，若target不存在，返回target左侧的最大值的位置
            {
                int mid = left + (right-left)/2;
                if(ints[mid] == target) left = mid + 1;
                else if(ints[mid] < target) left = mid + 1;
                else if(ints[mid] > target) right = mid;
            }
            if(left <= ints.size())
            {
                if(ints[left-1]>=target)  //由于是二分查找右侧边界，若数组内的值都小于target，left-1的值为ints.size()-1,所以要进行判断
                ans[i] = valToint[ints[left-1]];
                else  //同理，target不存在，返回的是target左侧最大值对应的位置，要判断left位置是否存在，若存在，left一定符合题意
                {
                    if(left < ints.size() && ints[left]>=target)
                    ans[i] = valToint[ints[left]];
                }
            }
        }
        return ans;
    }
};
```