```
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        vector<int> index;
        for(int i = 0; i < S.size(); i++)
        {
            if((S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122))
            {
                index.push_back(i);
            }
        }
        res.push_back(S);
        if (index.empty())
            return res;
        generate(res, S, index, 0);
        return res;
    }

private:
    void generate(vector<string> &res, string &S, vector<int> &index, int i)
    {
        if(i >= index.size())
        {
            return;
        }
        if(S[index[i]]>= 65 && S[index[i]] <= 90)
            S[index[i]] += 32;
        else if(S[index[i]] >= 97 && S[index[i]] <= 122)
            S[index[i]] -= 32;
        res.push_back(S);

        generate(res, S, index, i + 1);
        if(S[index[i]]>= 65 && S[index[i]] <= 90)
            S[index[i]] += 32;
        else if(S[index[i]] >= 97 && S[index[i]] <= 122)
            S[index[i]] -= 32;
        generate(res, S, index, i + 1);
    }
};
```
解法二：
位运算
```
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        vector<int> index;
        for(int i = 0; i < S.size(); i++)
        {
            if((S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122))
            {
                index.push_back(i);
            }
        }
        if (index.empty())
            return {S};
        int all = pow(2, index.size());
        for(int i = 0; i < all; i++)
        {
            for(int j = 0; j < index.size(); j++)
            {
                if((1 << j) & i)
                {
                    if(S[index[j]] >= 65 && S[index[j]] <= 90)
                        S[index[j]] += 32;
                    else
                        S[index[j]] -= 32;
                    break;
                }
            }
            res.push_back(S);
        }
        return res;
    }
};
```
