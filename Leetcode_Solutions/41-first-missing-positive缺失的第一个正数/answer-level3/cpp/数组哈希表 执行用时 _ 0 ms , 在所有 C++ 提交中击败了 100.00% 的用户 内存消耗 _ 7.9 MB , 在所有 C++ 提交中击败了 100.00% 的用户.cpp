```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == i+1 || !nums[i]){
                continue;
            }
            if(nums[i] > nums.size() || nums[i] < 0){
                nums[i] = 0;
            }
            else{
                int a = nums[i], b = nums[a-1];
                while(nums[a-1] != a){
                    nums[a-1] = a;
                    if(b <= 0 || b > nums.size()){
                        break;
                    }
                    a = b;
                    b = nums[a-1];
                }
                nums[a-1] = a;
            }
        }
        int res = 0, i= 0;
        for(; i < nums.size(); ++i){
            if(nums[i] != i+1){
                res = i+1;
                break;
            }
        }
        return i == nums.size()? nums.size()+1:res;
    }
};
```
