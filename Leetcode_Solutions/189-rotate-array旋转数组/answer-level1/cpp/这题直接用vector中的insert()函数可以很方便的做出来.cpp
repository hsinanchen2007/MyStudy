class Solution {
public:
    void rotate(vector<int>& vec, int k) {
        int l=vec.size();
        if(!(l==0||l==1))
        {
            k%=l;
            if(k!=0)
            {
                auto it=vec.end();
                for(int i=0;i<k;i++)
                {
                    it--;
                }
                vec.insert(vec.begin(),it,vec.end());
                for(int i=0;i<k;i++)
                {
                    vec.pop_back();//删除多余的
                }
            }
        }
    }
};