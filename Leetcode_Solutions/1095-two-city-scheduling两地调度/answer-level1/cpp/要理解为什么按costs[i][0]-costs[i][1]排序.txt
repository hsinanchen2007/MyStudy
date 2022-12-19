class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return (a[0] - a[1]) < (b[0] -b[1]);
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        // 按costs[i][0]-costs[i][1]从小到大排序
        sort(costs.begin(), costs.end(), comp);

        int ans = 0;
        for (int i = 0; i < costs.size(); i++) {
            if (i < costs.size()/2) {
                ans += costs[i][0]; // 前N个到A
            } else {
                ans += costs[i][1]; // 后N个到B
            }
        }
        return ans;
    }
};