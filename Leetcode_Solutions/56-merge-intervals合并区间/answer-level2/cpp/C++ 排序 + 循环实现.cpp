class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty())  return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int> tmp1, vector<int> tmp2){return tmp1[0] < tmp2[0];});
        int j = 0;
        result.push_back(intervals[0]);
        for (auto i = 1; i < intervals.size(); i++){
            if(result[j][1] >= intervals[i][0]){
                result[j][1] = max(result[j][1], intervals[i][1]);
            } else{
                result.push_back(intervals[i]);
                j++;
            }
        }
        return result;

    }
};