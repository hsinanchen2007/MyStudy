没见到c++的题解，，写一个：
#include <math.h>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> nums(26,0);
        for(int i=0;i<tasks.size();i++){
            nums[tasks[i]-'A']++;
        }
        
        sort(nums.begin(),nums.end());
        int maxCount = nums[25];
        int min_count = (maxCount-1)*(n+1);
        int count=0;
        
        for(int j=0;j<nums.size();j++){
            if(nums[j]==maxCount){
                count++;
            }
        }
        
        int temp = min_count+count;
        int len = tasks.size();
        int result = max(temp,len);
        return result;
    }
};