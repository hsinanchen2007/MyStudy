class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size() -1 , mid;
        while(left <= right){
            mid = left + (right - left)/2;
             // target在左子树
            if(nums[0] <= target){
                //mid 在右子树
                if(nums[mid] < nums[0]) right = mid - 1;
                //中点在左子树， 变为一般的二分查找问题
                else {
                    if(nums[mid] == target) return mid;
                    else if (nums[mid] > target) right = mid - 1;
                    else left = mid + 1;
                }

            }



            //target 在右子树
            else{
                //mid 在左子树
                if(nums[mid] >= nums[0]) left = mid + 1;
                //中点在右子树， 变为一般的二分查找问题
                else {
                    if(nums[mid] == target) return mid;
                    else if (nums[mid] > target) right = mid - 1;
                    else left = mid + 1;
                }
            

                
        
        }

        
    }
    return -1;
}

};