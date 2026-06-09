class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        if(n > 45) return res;
        int N= 1<<9;
        for(int i=0;i<N;i++){
            vector<int>temp;
            int sum = 0;
            for(int j=0;j<9;j++){
                if(i&(1<<j)){
                    temp.push_back(j+1);
                    sum += j+1;
                }
            }
            if(temp.size() == k && sum == n)
                res.push_back(temp);
        }
        return res;
    }
};