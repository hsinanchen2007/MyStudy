`class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        // 简单的题不写注释，因为太特么简单了
        int len = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        vector<int> temp;
        int absdiff = arr[1] - arr[0];
        
        for(int i = 1; i < len; i++){
            if(arr[i] - arr[i - 1] > absdiff)
                continue;
            else if(arr[i] - arr[i - 1] < absdiff){
                absdiff = arr[i] - arr[i - 1];
                result.clear();
            }
            temp.clear();
            temp.push_back(arr[i - 1]);
            temp.push_back(arr[i]);
            result.push_back(temp);
        }
        return result;
    }
};`