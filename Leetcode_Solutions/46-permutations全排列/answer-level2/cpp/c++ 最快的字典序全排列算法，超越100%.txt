
O(n)时间复杂度计算下一个字典序，计算全排列组合数个字典序.
```C++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        result.push_back(nums);
        for(int i=1; i < fac(nums.size()); i++){
            nextPermutation(nums);
            result.push_back(nums);
        }
        return result;
    }
private:
    void nextPermutation(vector<int>& nums) {
        int id = -1;
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i-1]<nums[i]){
                id = i-1;
                break;
            }
        }
        if(id==-1) sort(nums.begin(), nums.end());
        else{
            sort(nums.begin()+id+1, nums.end());
            auto it = upper_bound(nums.begin()+id+1, nums.end(), nums[id]);
            swap(nums[id], *it);
        }
    }

    int fac(int n){	
        int result = 1;
        if(n<0)	return -1;
        else if(n == 0)	return 1;
        while (n>1){	
            result *= n;
            n--;
        }
        return result;
    }
};
```