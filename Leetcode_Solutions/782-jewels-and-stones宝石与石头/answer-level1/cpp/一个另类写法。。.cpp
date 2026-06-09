class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int num=0;
        for(auto ch:S)
        {
            nums[(int)(ch)]++;
        }
        for(auto ch:J)
        {
            num+=nums[(int)(ch)];
        }
        return num;
    }
private:
    int nums[128]={0};
};