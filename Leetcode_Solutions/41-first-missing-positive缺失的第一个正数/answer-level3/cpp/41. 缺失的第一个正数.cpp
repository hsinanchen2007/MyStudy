```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        nums.resize(n+1);
        //测试用例里又有INT_MAX和INT_MIN，不能加减1，只能resize数组了,要不就得用long long,贱！
        nums[n]=0;
        for(int i=0;i<=n;++i)
        {
            while(true)
            {
                int tmp=nums[i];
                if(tmp<=0)break;
                if(tmp>n)
                {
                    nums[i]=0;
                    break;
                }
                if(i==tmp)break;
                if(tmp==nums[tmp])
                {
                    nums[i]=0;
                    break;
                }
                swap(nums[i],nums[tmp]);
            }
        }

        for(int i=1;i<=n;++i)
        {
            if(i!=nums[i])return i;
        }
        return n+1;
    }
};
```
