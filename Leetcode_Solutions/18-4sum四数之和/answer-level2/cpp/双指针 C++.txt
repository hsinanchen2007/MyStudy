解题思路：固定两个指针left和right，用一个for循环从left == 0开始，然后对右边进行从right == nums.size()开始遍历right--,相同就再--，直到left + 3 <= right - 1，固定两端的指针时中间两个数r和l一直往中间靠近，直到l == r算是完成一次检测。
附上代码：
class Solution {
public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int right = nums.size() - 1;
            int left = 0;
            int l = left + 1;
            int r = right - 1;
            int sum = 0;
            vector <vector<int>> tmp;
            sort(nums.begin(), nums.end());
            if(nums.size() < 4){
                return tmp; 
            }
            if(nums.size() == 4){
                if(target == nums[0] + nums[1] + nums[2] + nums[3]){
                    tmp.push_back({nums[0] , nums[1] , nums[2] , nums[3]});
                }
                return tmp;
            }
            for(int k = 0; k < nums.size() - 3; k++){
                if(k > 0 && nums[k] == nums[k - 1]){
                    continue;
                }
                left = k;
                right = nums.size() - 1;
                l = left + 1;
                r = right - 1;
                while(left + 3 <= right){
                    while(l < r){
                        sum = nums[left] + nums[l] + nums[right] + nums[r];
                        if(sum == target){
                            tmp.push_back({nums[left], nums[l], nums[r], nums[right]});
                            l++;
                            r--;
                            while(l < r && nums[l] == nums[l - 1]){
                                l++;
                            } 
                            while(l < r && nums[r] == nums[r + 1]){
                                r--;
                            } 
                        }
                        else if(sum > target){
                            r--;
                        }
                        else{
                            l++;
                        }
                    }
                    if(l >= r){
                        right--;
                        while(left + 3 <= right && nums[right] == nums[right + 1]){
                            right--;
                        } 
                        l = left + 1;
                        r = right - 1;
                    }
                }
            }
            return tmp;
        }
};