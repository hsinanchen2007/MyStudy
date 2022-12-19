代码：
```
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int left=0,mid=0,right=1,n=nums.size();
        if(n==0){
            return {};
        }
        vector<string>res;
        if(n==1){
            res.push_back(to_string(nums[0]));
            return res;
        }
        while(left<=right&&right<n){
            while(right<n&&nums[right]==nums[mid]+1){
                right++;
                mid++;
            }
            if(left!=mid){
                string t=to_string(nums[left])+"->"+to_string(nums[mid]);
                left=right;
                mid=right;
                right+=1;
                res.push_back(t);
            }
            else{
                string t=to_string(nums[left]);
                left=right;
                mid=right;
                right+=1;
                res.push_back(t);
            }
            if(right==n){
                string t=to_string(nums[mid]);
                res.push_back(t);
            }
        }
        return res;
    }
};
```
