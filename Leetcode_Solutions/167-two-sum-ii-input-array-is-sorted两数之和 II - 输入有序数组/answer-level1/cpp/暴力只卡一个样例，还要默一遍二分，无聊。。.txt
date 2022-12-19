```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int temp_index1=0,temp=0;
        vector<int> ans;
        int n =numbers.size();
        for(int i=0;i<numbers.size();i++){
            temp=numbers[i];
            int fin = target-numbers[i];
            int left = i+1,right = numbers.size()-1;
            while(left<=right){
            int mid = (left+right)/2;
            if(numbers[mid]>fin){
                right=mid-1;
            }else if(numbers[mid]==fin){
                ans.push_back(i+1);
                ans.push_back(mid+1);
                return ans;
            }else{
                left=mid+1;
            }
          }
        }
        return ans;
    }
};
```
