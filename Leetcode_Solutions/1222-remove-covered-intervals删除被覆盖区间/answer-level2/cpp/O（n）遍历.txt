### 解题思路
把线段按照开始端点存入数组里面，数组下标为线段开始端点值，数组值为线段编号。
此时应该顺便统计开始端点相同的线段，因为他们一定包含。
之后遍历数组，取出每一个线段，如果下一个线段的右端点大于当前线段，则当前线段能包含的，下一个线段也能包含，此时将当前线段替换为下一个线段；如果下一个线段的右端点小于等于当前线段，合并的线段数加加。

### 代码

```cpp
const int maxn=100105;
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        int a[maxn+10];
        memset(a,-1,sizeof(a));
        int i=0,right=-1;
        for (auto inte: intervals) {
            if (a[inte[0]]==-1) 
                a[inte[0]]=i;
            else {
                int pre=a[inte[0]];
                int b=inte[1];
                int d=intervals[pre][1];
                ans++;
                if (b>d) {
                    a[inte[0]]=i;
                }
                
            }
            right=max(right,inte[1]);
            i++;
        }
        int pre=-1;
        for (int i=0;i<right;i++) {
            if (a[i]!=-1) {
                if (pre==-1) {
                    pre=a[i];
                }
                else {
                    int b=intervals[a[i]][1];
                    int d=intervals[pre][1];
                    if (b<=d) {
                        ans++;
                    }
                    else {
                        pre=a[i];
                    }
                }
            }
            else {
                if (pre!=-1&&intervals[pre][1]==i) {
                    pre=-1;
                }
            }
        }
        return intervals.size()-ans;
    }
};
```