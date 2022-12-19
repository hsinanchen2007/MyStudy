感谢@hitwanyang 指点
`class Solution {
public:
    int judeg(int n){
        if(n<=4) return 0;
        vector<int> temp;
        temp=yinshu(n);
        if(temp.size()==2){
            return temp[0]+temp[1];
        }
        return 0;
    }
    vector<int> yinshu(int n){
        int m=sqrt(n);
        vector<int> ans;
        for(int i=1;i<=m;i++){
            if(n%i==0&&(n/i!=i)) ans.push_back(i);
        }
        return ans;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        int temp;
        int i;
        bool flag=false;
        for(i=0;i<nums.size();++i){
            temp=judeg(nums[i]);
            int q=sqrt(nums[i]);
            if(temp&&q*q!=nums[i]){
                ans+=(1+nums[i]+(temp-1)+(nums[i]/(temp-1)));
            }
        }
        return ans;
    }
};`