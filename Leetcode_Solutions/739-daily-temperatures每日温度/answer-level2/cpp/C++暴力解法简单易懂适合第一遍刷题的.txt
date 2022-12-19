class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size());
        for(int i=0;i<T.size()-1;i++)
        {
            if(T[i]<100)
            {
                for(int j=i+1;j<T.size();j++)
                {
                    if(T[j]>T[i])
                    {
                        res[i]=j-i;
                        break;
                    }
                }
            }

        }
        return res;
    }
};