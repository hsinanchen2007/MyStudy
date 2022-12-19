### 解题思路
区间问题要先排序
先在result中维持一个区间，然后与外面的区间不断比较

### 代码

```cpp
/*
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
*/

class Solution {
public:
    // 排序 
    bool static Compare(vector<int>a, vector<int>b)
    {
        return a[0] < b[0];
    } 

    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res;  /* 声明res */
        if (intervals.empty()) {
            return res;  /* 判断边界 */
    }

        sort(intervals.begin(), intervals.end(), Compare);  /* 将区间的左边界进行排序 */
        int index = 0;  /* res的遍历索引 */
        res.push_back(intervals[0]);    /* 先将intervals的第一个区间放到res里面 */
        for (auto interval : intervals) { /* 遍历intervals的其他区间 */
            int start = interval[0];
            int end = interval[1];
            if (res[index][1] >= start) {                                    
                if (res[index][1] <  end) { /* [1,4] 和 【2，6】合并为【1，6】 */
                    res[index][1] =  end;  
                }
                // [1,4] 和 【2，3】不变保持为【1，4】
            } else {                                      
                index++;                       /* 如果不满足有联通区域，直接将index++，并将当前的intervals[i] 放到res里面，进行下一时刻的合并  */
                res.push_back(interval);    /* [1,4] 和 【5，6】不变,同时把当前的interval新加进来 */
            }
        }
        return res;
    }
};
/*
int main()
{
    class Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = s.merge(intervals);
    cout << "The result is : " << endl;
    for (auto res : result) {
        for (auto r :res) {
            cout << r <<' ';
        }
        cout <<endl;
    }
    system("pause");
    return 0;
}
*/
```