### 解题思路
超过99.78的执行耗时，内存消耗大，不知道为啥

### 代码

```cpp
class Solution {
public:
     int len;
    bool canJump(vector<int>& nums) {
        len=nums.size();
        if(len<=1) return true;
        return dfs(nums,len-1);
    }
    bool dfs(vector<int>& nums,int p){
        int tmp=p-1;
        if(p==0) return true;
        while(tmp>=0&&nums[tmp]+tmp<p){
            --tmp;
            //cout<<tmp;
        }
        if(tmp<0) return false;
        return dfs(nums,tmp);
    }
};
```