```
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        string letters[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m",
                              "n","o","p","q","r","s","t","u","v","w","x","y","z"};
        int min[26] = {0};
        for(int j=0;j<A[0].length();j++)
        {
            min[A[0][j]-97]++;
        }
        for(int i=1;i<A.size();i++)
        {
            int tmp[26] = {0};
            for(int j=0;j<A[i].length();j++)
            {
                tmp[A[i][j]-97]++;
            }
            
            for(int k=0;k<26;k++)
            {
                if(tmp[k] < min[k])
                    min[k] = tmp[k];
            }
        }
        vector<string> res; res.clear();
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<min[i];j++)
            {
                res.push_back(letters[i]);
            }
        }
        return res;
    }
};
```