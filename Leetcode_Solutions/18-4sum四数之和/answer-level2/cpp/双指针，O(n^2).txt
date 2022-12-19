1，15，16和这道题类似吧，双指针的思路是一样的。
```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        //unorder_map rets;


        int n = nums.size();
        int pts1,pts2;
        int sum;

        for (int i=0;i<n-3;i++) {
            if (i>0 and nums[i] == nums[i-1]) {cout<<"pass:"<<i<<'\n';continue;}
            for (int j=i+1;j<n-2;j++) {
                if (j>i+1 and nums[j] == nums[j-1]) continue;
                cout << "j: "<< j << '\n';
                pts1 = j+1;
                pts2 = n-1;

                while (pts1<pts2) {
                    sum = nums[i] + nums[j] + nums[pts1] + nums[pts2];
                    if (target == sum) {
                        cout <<i<<','<<j<<','<<pts1<<','<<pts2<<','<<'\n';
                        ret.push_back(vector<int> {nums[i], nums[j], nums[pts1], nums[pts2]});
                        pts1++;
                        pts2--;
                        while (pts1<pts2 and nums[pts1] == nums[pts1-1]) pts1++;
                        while (pts1<pts2 and nums[pts2] == nums[pts2+1]) pts2--;
                    }
                    if (target < sum) {
                        pts2--;
                        while (pts1<pts2 and nums[pts2] == nums[pts2+1]) pts2--;
                    }
                    if (target > sum) {
                        pts1++;
                        while (pts1<pts2 and nums[pts1] == nums[pts1-1]) pts1++;
                    
                    }
                }
            }
        }
        return ret;
    }
};
```
