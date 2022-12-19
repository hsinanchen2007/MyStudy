```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0) return 1;
        else if (nums.size()==1){
            if(nums[0]!=1) return 1;
            else return 2;
        }
        int count=0;
        int minValue;
        map<int, int> numsMap; // map比unordered_map效率要高，详情参见两者的定义
        for(int i=0; i<nums.size();i++){
            if(nums[i]<=0) continue;
            if(count == 0) minValue = nums[i];
            else
                minValue = min(minValue, nums[i]);
            count++;
            numsMap[nums[i]]++;
        }
        if(minValue!=1){    //如果最小值不是1，那么没出现的最小正整数肯定是1.
            return 1;
        }else{
            int i = 1;
            while(1){
                //如果最小值是1， 那么从1开始查找，哪个数没有出现过
                if(numsMap.find(i) == numsMap.end()){
                    return i;
                }
                i++;
            }
        }
    }
};
```
map是按key的大小排列存储的，所以查最小值和写入map循环一次（N），找没出现的数遍历key一次（<N，最坏情况下N），故复杂度为$O(N)$