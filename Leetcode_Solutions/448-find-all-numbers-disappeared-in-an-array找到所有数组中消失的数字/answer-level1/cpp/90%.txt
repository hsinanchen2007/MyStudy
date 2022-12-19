1. `solve1`
对每个出现过的数字的下标进行标记，一种o(n)的办法是引入哈希表，直接进行标记，o(1)的办法是直接在原数组进行操作，使得和原来的数字发生区别那么我们就将其变成负数,然后遍历加入答案``

代码块
```class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
          int siz=nums.size();
          for(int i=0;i<siz;++i){
              //cout<<abs(nums[i])<<endl;
              if(nums[abs(nums[i])-1]<0)continue;
              nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
          }
          vector<int>ans;
          for(int i=0;i<siz;++i){
              if(nums[i]>0)ans.push_back(i+1);
          }

          return ans;
    }
};


2. solve2

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int siz=nums.size();
        //cout<<siz<<endl;
        if(!siz)return ans;
        sort(nums.begin(),nums.begin()+siz);
        for(int i=1;i<nums[0];++i)ans.push_back(i);
        for(int i=1;i<siz;++i){
            if(nums[i]-1!=nums[i-1]&&nums[i]!=nums[i-1]){
                for(int j=nums[i-1]+1;j<nums[i];++j)ans.push_back(j);
            }
        }
        for(int i=nums[siz-1]+1;i<=siz;++i)ans.push_back(i);
        return ans;
    }
}; 