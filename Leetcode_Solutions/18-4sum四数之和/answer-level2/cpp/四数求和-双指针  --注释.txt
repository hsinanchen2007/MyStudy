class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int front_low = 0,front_high,rear_low,rear_high;
        int n_size = nums.size();
        int possible_size = n_size - 2;
        if(n_size < 4) return result;
        sort(nums.begin(),nums.end());

        int ox = 0;
        int ox1 = 0;
        for(front_high = possible_size - 1;front_high > 0; front_high --){
            while (front_low < front_high && nums[front_high] == nums[front_high - 1]){
                    front_high--;
                    ox = 1;
            }
            if(ox == 1){ox = 0;front_high +=1;front_low = front_high -1;}
            for(;front_low < front_high; front_low ++){

                //增加如下判别条件 减少运行时间
                if(target<=0 && nums[front_low]>0) break;
                if(nums[front_low]+nums[front_low+1]+nums[front_low+2]+nums[front_low+3]>target) break;
                // 此时条件不满足
                if(nums[front_low]+nums[n_size-3]+nums[n_size-2]+nums[n_size-1]<target) continue;
                // 重复项
                if(front_low>0 && nums[front_low]==nums[front_low-1]) continue;
                //*********************************

                rear_high = n_size - 1;
                rear_low = front_high + 1;
                if(front_low > 0)
                    while (front_low < front_high && nums[front_low] == nums[front_low - 1]){
                        front_low++;
                        ox1 = 1;
                    }
                    if(ox1 == 1){ox1 = 0;front_low --;continue;}
                while(rear_high > rear_low){
                    if(rear_low > front_high + 1)
                        if (rear_low < rear_high && nums[rear_low] == nums[rear_low - 1]){
                            rear_low++;
                            continue;
                        }
                    if(rear_high < n_size - 1)
                        if (rear_low< rear_high  && nums[rear_high] == nums[rear_high + 1]){
                            rear_high--;
                            continue;           //正确使用，不执行下面语句
                        }

                    int sum = nums[front_high] + nums[front_low] + nums[rear_high] + nums[rear_low];
                    if( sum > target){
                        rear_high --;
                    }else if(sum < target){
                        rear_low ++;
                    }else{
                        vector<int> temp_res {nums[front_low], nums[front_high] ,nums[rear_low] ,nums[rear_high]};
                        result.push_back(temp_res);
                        rear_high --;
                        rear_low ++;
                    }
                }
            }
        front_low = 0; //*********************************************重要*******************************************
        }
        return result;
    }
};