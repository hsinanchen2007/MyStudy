```
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int count=0;
        int right=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int left=right-1;
        vector<int> ans;
        while(count<k){
            if(right==arr.size()){
                ans.push_back(arr[left--]);
            }
            else if(left==-1){
                ans.push_back(arr[right++]);
            }
            else{
                int right_num=abs(arr[right]-x);
                int left_num=abs(arr[left]-x);
                if(left_num<=right_num){
                    ans.push_back(arr[left--]);
                }
                else{
                    ans.push_back(arr[right++]);
                }
            }
            ++count;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
```
