使用c++自带排序


bool cmp(int a, int b){
    return a < b;
}

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> height = heights;
        int ans = 0;

        sort(heights.begin(), heights.end(), cmp);

        for(int i = 0; i < heights.size(); i++){
            if(height[i] != heights[i]){
                ans++;
            }
        }
    return ans;
    }
};