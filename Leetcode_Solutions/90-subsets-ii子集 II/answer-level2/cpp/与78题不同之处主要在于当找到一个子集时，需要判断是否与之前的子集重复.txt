    class Solution {
    private:
        vector<vector<int>> res;
        void find(vector<int>& nums,int start,int k,vector<int> &p){
            if(p.size() == k)//查找res中是否有与p相同的子集，没有则加入p
            {
                bool flag = false;
                //子集相同必然长度相等，通过限制长度，可减少不必要的计算
                for(int i=res.size()-1;i >= 0 && res[i].size()==k;i--)
                {
                    if(res[i] == p)
                    {
                        flag = true;
                        break;
                    } 
                }
                if(!flag)
                    res.push_back(p);
                return;
            }
            for(int i=start;i<nums.size()-(k-p.size())+1;i++)
            {
                p.push_back(nums[i]);
                find(nums,i+1,k,p);
                p.pop_back();
            }
            return;
        }
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            res.clear();
            vector<int> p;
            res.push_back(p);
            if(nums.size() == 0)
                return res;
            //排序是必须的，这样可以保证相同的子集，元素的存放顺序是一样的
            //便于后续的比较
            sort(nums.begin(),nums.end());
            for(int i=1;i<nums.size();i++)
                find(nums,0,i,p);
            res.push_back(nums);
            return res;
        }
    };