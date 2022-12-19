class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        int c1 = 0, c2 = 0, count1 = 0, count2 = 0;
        // 摩尔投票 两个候选人 c1, c2
        // 群众投出一票 看这一票是 c1 || c2 ,两者的票不冲突
        // 如果两个票数有其中之一归 0 了，那么就要重新选择一个候选人， 当前的 num 作为新的候选人  
        // 如果两个票都不为 0， 那么每个人的票数减 1
        for(auto num : nums){
            if(num == c1) count1++;
            else if(num == c2) count2++;
            else if(count1 == 0) c1 = num,count1++;
            else if(count2 == 0) c2 = num,count2++;
            else{count1--; count2--;}
        }
        count1 = 0, count2 = 0;
        for(auto num : nums){
            if(num == c1) count1++;
            else if(num == c2) count2++;
        }
        vector<int> ret;
        if(count1 * 3 > n) ret.push_back(c1);
        if(count2 * 3 > n) ret.push_back(c2);
        return ret;
    }
};