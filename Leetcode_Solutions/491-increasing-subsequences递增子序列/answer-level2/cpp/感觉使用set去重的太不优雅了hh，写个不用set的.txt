```c++
class Solution {
public:
    vector<vector<int>>res;
    vector<int>current;
    int n,cnt,v;//cnt记录当前序列中有几个元素，v表示该位置是否访问
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        dfs(nums,0);
        return res;
    }
    void dfs(vector<int>& nums,int start){
        if(cnt>=2) res.push_back(current);
        if(start==n) return ;
        for(int i=start;i<n;++i){
            if(cnt!=0 && nums[i]<current[cnt-1])continue;
            if(check(nums,start,i))continue;
            v|=1<<i;
            current.push_back(nums[i]);
            cnt++;
            dfs(nums,i+1);
            v-=1<<i;
            current.pop_back();
            cnt--;
        }
    }
    bool check(vector<int>& nums,int &begin,int &end){
        for(int i=begin;i<end;++i){
            if(nums[i] == nums[end])return true;
        }
        return false;
    }
};
```