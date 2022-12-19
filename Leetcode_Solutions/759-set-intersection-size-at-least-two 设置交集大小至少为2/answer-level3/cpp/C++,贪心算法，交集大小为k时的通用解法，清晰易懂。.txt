法思路：现对于区间按照第二位的大小排序。对于每个区间，如果当前set已经和这个区间相交2个元素了，continue；否则就设置两个数，在设置这两个数时用的是
贪心策略。我们每次都尽可能选取价值最大的数，也就是这个数，在包含在当前区间情况下，在下面未遍历的区间出现的次数最多。这样我们就要选择，最大的数，
和最大的数-1（如果这个区间只需要1个数了，那么第二个数不用选了，为了写程序方面，设置成一个无效数，比如-100）。为什么这样设置就行呢？因为排序后，
假设x1在下面出现次数最多，那么x1+1的出现次数也一定会等于x1的出现次数。大家可以画图试一试。这样就可以使用2个元素相交最多的区间了。
```
class Solution {
public:
    static bool comp(const vector<int> &a,const vector<int> &b){
        if(a[1] != b[1])
            return a[1] < b[1];
        else return a[0] > b[0];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),comp);
        int ans = 0;
        vector<int> visited(intervals.size(),2);
        for(int i = 0 ; i < intervals.size() ; i++){
            if(visited[i] <= 0) 
                continue;
            int a1,a2;
            ans += visited[i];
            if(visited[i] == 2){
                a1 = intervals[i][1];
                a2 = a1-1;
            }
            else{
                a1 = intervals[i][1];
                a2 = -100;
            }

            for(int j = i ; j < intervals.size() ; j++){
                if(a1<=intervals[j][1] && a1 >= intervals[j][0])
                    visited[j]--;
                if(a2<=intervals[j][1] && a2 >= intervals[j][0])
                    visited[j]--;
            }
        }
        return ans;
    }
}; 
```
