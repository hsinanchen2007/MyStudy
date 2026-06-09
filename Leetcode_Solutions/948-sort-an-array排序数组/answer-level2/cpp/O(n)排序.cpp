```

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int temp[100001];
        memset(temp,0, sizeof(temp));
        for(int t:nums)
            temp[t+50000]++;
        int j=0;
        for(int i=0;i<100001;i++){
            while(temp[i])
            {
                nums[j++]=i-50000;
                temp[i]--;
            }
        }
        return nums;
    }
};
```
就硬用100001个数组遍历完所有的数，然后把保存每个数输出。

遍历一遍O（n），输出一次O（n），打卡了= =