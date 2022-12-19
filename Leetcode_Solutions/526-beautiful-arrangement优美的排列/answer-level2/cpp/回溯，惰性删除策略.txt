标记为0表示已访问过。时间O（n3）QAQ 空间O（n）
```
class Solution {
public:
    int result=0;
    void generate(vector<int>& nums,vector<int>& pre)
    {
        if(pre.size()==nums.size())
        {
            result++;
            return;
        }
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==0)
            {
                continue;
            }
            int pos=pre.size()+1;
            if(nums[i]%pos==0||pos%nums[i]==0)
            {
                pre.push_back(nums[i]);
                nums[i]=0;
                generate(nums,pre);
                nums[i]=pre[pre.size()-1];
                pre.pop_back();
            }
        }    
    }
    int countArrangement(int N) {
        vector<int> nums(N);
        std::iota(nums.begin(),nums.end(),1);
        vector<int> tmp;
        generate(nums,tmp);
        return result;
    }
};
```
