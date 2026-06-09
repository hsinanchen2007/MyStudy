原来读题出现歧义，原以为集合S也为连续区间，使用优先队列实现了一个解。
后来发现如果将集合S视为可以不连续，那么计算复杂度会上升一些，也是官方预期的答案咯。

解题思路：
    考虑在一个坐标系中建立各种横向线段。在纵坐标方向上优先按照 各线段的 左端点排序
    左右相同的话，那就以右端点的大小排序（即线段长短）
    排序完成后，依次向前遍历，看当前线段中的值有多少存在于已知集合中
    如果差值K-found>0,那么就从当前线段中的左侧开始，补充 K-found个值进入集合。



以下为详细解法，可以解交集为2最小集合，也可以解交集为K的最小集合。

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include "my_debug.h"

using namespace std;

#define E_LEFT  0
#define E_RIGHT 1

#define K 2

struct CMP {
    bool operator() (vector<int> *a, vector<int> *b) {
        if ((*a)[E_LEFT] == (*b)[E_LEFT]) {
            return (*a)[E_RIGHT] < (*b)[E_RIGHT];
        } else {
            return (*a)[E_LEFT] < (*b)[E_LEFT];
        }
    }
};

bool cmp(vector<int> &a, vector<int> &b) {
    if (a[E_LEFT] == b[E_LEFT]) {
        return a[E_RIGHT] < b[E_RIGHT];
    } else {
        return a[E_LEFT] < b[E_LEFT];
    }
}

class SetSizeAtLeastContainK : public MyDebug {
// class Solution {
public:

    int FindCount(vector<vector<int>>& intervals, set<int> &result, int cur) {
        set<int> found;
        // 依次查找当前线段中的值是否在之前的各线段中已经加入集合。
        // 只需要判断每个线段的头K个数据即可
        for (int i = cur + 1; i < intervals.size(); i++) {
            // 此处还可以优化，如果上一个线段和上上个线段开始是相同的，可以考虑优化掉
            int curRight = intervals[cur][E_RIGHT];
            // 如果之前线段的开始已经超出当前线段的结束，因为排序的缘故，已经不需要继续了。
            if (intervals[i][E_LEFT] > curRight) { break; }
            for (int j = 0; j < K; j++) {
                int oldLeftN = intervals[i][E_LEFT]+j;
                // 如果 之前线段的Left+j已经超出当前线段的结束，跳出小循环
                if (oldLeftN > curRight) { break; }
                // 找到的点加入合集
                if (result.find(oldLeftN) != result.end()){
                    found.insert(oldLeftN);
                }
            }
            // 找到的结果超出预期，不用继续了。
            if (found.size() >= K) { break; }
        }
        return found.size();
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        set<int> result;
        // 排序 线段左端最大的放到前面，如左端相同，右端最大的放前面。
        sort(intervals.begin(), intervals.end(), cmp);

        for (int cur = (int)intervals.size()-1; cur >= 0; cur--) {
            // 查找结果中是否已经存在 元素
            int found = FindCount(intervals, result, cur);
            // cout << "cur: (" << intervals[cur][0] << ", " << intervals[cur][1] << ") found: " << found << endl;
            if (found >= K) { continue; }
            // 刨去已经找到的个数，始终插入左边元素
            int count = intervals[cur][E_RIGHT] -intervals[cur][E_LEFT] + 1;
            for (int i = 0, insert = 0; insert < K - found && i < count; i++) {
                int val = intervals[cur][E_LEFT]+i;
                if (result.find(val) != result.end()) { continue; }
                result.insert(val);
                insert++;
            }
            // PrintSet(result, "set");
        }
        return result.size();
    }
    // 以下为错误的解，由于阅读歧义，原以为题目中的集合S为连续区间。
    int intersectionSizeTwo_wrong(vector<vector<int>>& intervals) {
        // 所有 线段压入 一个优先队列，队列中线段左端最大的放到前面，如左端相同，右端最大的放前面。
        priority_queue<vector<int> *, vector<vector<int> *>, CMP> pq;
        for (auto i = 0; i < intervals.size(); i++) { pq.push(&intervals[i]); }

        // 取出 左端 最大值,与右端 最小值
        vector<int> *max, *min, *cur;
        max = min = pq.top();
        while(pq.size() > 0) {
            cur = pq.top(); pq.pop();
            if ((*cur)[E_RIGHT] < (*min)[E_RIGHT]) { min = cur; }
        }
        // 分 有无重叠区域进行三种情况判断
        if ((*min)[E_RIGHT] < (*max)[E_LEFT]) {
            // 最左与最右 线段 没有重叠区域
            return (*max)[E_LEFT] - (*min)[E_RIGHT] - 1 + 2 * K;
        } else if ((*min)[E_RIGHT] - (*max)[E_LEFT] >= K - 1) {
            // 最左与最右 线段 重叠区域 不小于K (当前K为2)
            return K;
        } else {
            // 最左与最右 线段 有部分重叠区域 Overlap
            int Overlap = (*min)[E_RIGHT] - (*max)[E_LEFT] + 1;
            return 2 * K - Overlap;
        }
    }
};

int SetSizeAtLeastContainK_Tester() {
    int ret;
    // vector<vector<int>> intervals {{1,3},{1,4},{2,5},{3,5},};
    // [[2,10],[3,7],[3,15],[4,11],[6,12],[6,16],[7,8],[7,11],[7,15],[11,12]] 预期结果 5
    vector<vector<int>> intervals{{2,10},{3,7},{3,15},{4,11},{6,12},{6,16},{7,8},{7,11},{7,15},{11,12}};
    SetSizeAtLeastContainK s;
    s.PrintVector2(intervals, "input");
    ret = s.intersectionSizeTwo(intervals);
    cout << "result = " << ret << endl;
    return 0;
}
```