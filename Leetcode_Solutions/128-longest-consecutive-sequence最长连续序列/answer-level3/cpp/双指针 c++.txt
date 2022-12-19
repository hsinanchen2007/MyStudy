
```
int longestConsecutive(vector<int>& nums) {
        //判断是否为空
        if(nums.size()==0)
        {
            return 0;
        }
        //排序
        sort(nums.begin(),nums.end());
        //sub表示一段序列长度，res表示最长序列长度
        int res=1,sub=1;
        for(int i=0,j=1;j<nums.size();i++,j++)
        {   
            //后一个=前一个+1
            if(nums[j]==nums[i]+1)
            {
                sub+=1;
            }
            else
            {
                if(nums[j]>nums[i]+1)
                {
                    res=max(sub,res);
                    //从头开始计数
                    sub=1;
                }
            }
        }
        //这里需要考虑如果整个序列都是连续的情况
        return max(res,sub);
    }
```
