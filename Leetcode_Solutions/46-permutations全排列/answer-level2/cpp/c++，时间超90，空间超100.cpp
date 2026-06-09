嗯，，，没啥好说的，就直接疯狂遍历就ok了
```
class Solution {
    int theminnotused(bool *used,int len)
    {//寻找最靠前的未使用的元素
        int i = 0;
        for(;i<len;i++)
        {
            if(used[i] == false)
                return i;
        }
        return len;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        int i,j;
        bool used[nums.size()];
        memset(used,false,nums.size()*sizeof(bool));//false指没有用过,即没有出现在栈中
        vector<vector<int>> re;
        vector<int> sta,rettt;
        i = 0;
        while(sta.size() > 0||i < len)
        {
            while(sta.size() < len)
            {
                i = theminnotused(used,len);
                //cout<<i;
                sta.push_back(i);
                used[i] = true;
            }
            if(sta.size() == len)
            {
                rettt.clear();
                for(j = 0;j < len;j++)
                {
                    rettt.push_back(nums[sta[j]]);
                }
                re.push_back(rettt);
                //cout<<"1111";
            }
            while(sta.size() > 0)
            {
                i = sta[sta.size()-1];
                sta.pop_back();
                used[i] = false;
                //i = theminnotused(used,len);
                i++;
                while(i < len)//寻找下一个尚未使用的最小的元素，不能从第一个开始因为在这个位置上已经出现过
                {
                    if(!used[i])
                        break;
                    i++;
                }
                if(i < len)
                {
                    //i++;
                    sta.push_back(i);
                    used[i] = true;
                    break;
                }
                else
                {
                    if(sta.size() == 0)
                        break;
                }
            }
        }
        return re;
    }
};
```
