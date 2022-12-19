```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<int> tmp;
        ret.push_back(tmp);
        //保存起始位置
        vector<int> begin_pos;
        //第一位保存插入元素在begin_pos 中的位置，第二个数保存插入元素在nums 中的位置
        vector<vector<int>> info;
        info.push_back(tmp);
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])continue;
            //长度为1的子集插入
            tmp.push_back(begin_pos.size());
            tmp.push_back(i);
            info.push_back(tmp);
            tmp.clear();
            //记录元素位置
            begin_pos.push_back(i);
            //插入当前结果至返回数组中
            tmp.push_back(nums[i]);
            ret.push_back(tmp);
            tmp.clear();

        }
        //将末尾位置插入
        begin_pos.push_back(nums.size());
        int start=1,end=ret.size();
        for(int i=2;i<=nums.size();++i)
        {
            for(int j=start;j<end;j++)
            {
                vector<int> tmp_info=info[j];
                tmp=ret[j];
                //判断是否有重复数字
                if(tmp_info[1]+1<begin_pos[tmp_info[0]+1])
                {
                    tmp_info[1]++;
                    tmp.push_back(nums[tmp_info[1]]);
                    ret.push_back(tmp);
                    info.push_back(tmp_info);
                    tmp.clear();
                }
                //追加不重复数字
                for(int k=tmp_info[0]+1;k<begin_pos.size()-1;k++)
                {
                    tmp_info[0]=k;
                    tmp_info[1]=begin_pos[k];
                    info.push_back(tmp_info);

                    tmp=ret[j];
                    tmp.push_back(nums[tmp_info[1]]);
                    ret.push_back(tmp);
                    tmp.clear();
                }
            }
            start=end;
            end=ret.size();
        }
        return ret;
    }
};
```