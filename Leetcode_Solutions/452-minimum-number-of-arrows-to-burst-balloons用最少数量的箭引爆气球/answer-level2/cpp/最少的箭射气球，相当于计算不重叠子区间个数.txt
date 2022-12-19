### 解题思路
最少的箭射气球，相当于计算不重叠子区间个数
但是是否交界的定义有不同

![无重叠区间.jpg](https://pic.leetcode-cn.com/e618e6844b1f312be182d41441b8fead6d0a94d5ab20e97a62736d16c04fa143-%E6%97%A0%E9%87%8D%E5%8F%A0%E5%8C%BA%E9%97%B4.jpg)



### 代码

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    static bool compare(vector<int>a,vector<int>b){
            return a[1]<=b[1];
    }

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) { //等于求不相交区间个数
        int n = intervals.size();
        if(n==0 ){
            return 0;
        }

        sort(intervals.begin(),intervals.end(),compare);
        int x_end = intervals[0][1];
        int count = 1;
        for(const auto& interval:intervals){
            if(x_end <interval[0]){ //在此题中交界认为也是相交的
                count++;
                x_end = interval[1];
            }
        }
        return count;
    }
};
```