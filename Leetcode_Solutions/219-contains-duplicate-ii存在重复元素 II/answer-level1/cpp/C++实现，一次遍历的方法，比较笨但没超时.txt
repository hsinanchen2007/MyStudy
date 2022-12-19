class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> a;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            if(a[temp]==0){
                a[temp]=i+1;//+1是因为存入第一个元素的下标为0，避免条件判断出错+1，相对值没有改变；
            }
            else if(a[temp]!=0){
                int sub=i+1-a[temp];
                if(sub<=k){
                    return true;
                }
                a[temp]=i+1;
            }
        }
        return false;
    }
};