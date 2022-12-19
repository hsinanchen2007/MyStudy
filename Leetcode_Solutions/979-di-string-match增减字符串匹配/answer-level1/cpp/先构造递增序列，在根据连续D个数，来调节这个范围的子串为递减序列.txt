```
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ret(S.size()+1, 0);
        int i = 0;
        int j = 0;
        for(i=0; i<ret.size(); i++)
        {
            ret[i] = i;
        }
        for(i=0; i<S.size(); i++)
        {
            if(S[i] == 'D')
            {
                j = i;
                while(i<S.size() && S[i] == 'D')
                    i++;
                reverse(ret, j, i);
            }
        }
        return ret;
    }
    void reverse(vector<int>& data, int i, int j)
    {
        while(i<j)
        {
            swap(data[i], data[j]);
            i++;
            j--;
        }
    }
};
```
