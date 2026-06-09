对于n个字母的组合，可以先求得前n-1个字母的组合，再将结果和最后一个进行组合即可。 n>=1  
边界条件：当n为1时，是这个数字的所有字符可能。当n为0时，结果为空。  

```
class Solution {
public:
    Solution()
    {
        vecvec.push_back({'a', 'b', 'c'});//2
        vecvec.push_back({'d', 'e', 'f'});//3
        vecvec.push_back({'g', 'h', 'i'});//4
        vecvec.push_back({'j', 'k', 'l'});//5
        vecvec.push_back({'m', 'n', 'o'});//6
        vecvec.push_back({'p', 'q', 'r', 's'});//7
        vecvec.push_back({'t', 'u', 'v'});//8
        vecvec.push_back({'w', 'x', 'y', 'z'});//9
    }


    vector<string> help(int start, const string& digits)
    {
        vector<string> vec;
        if(digits.empty())
            return vec;
            
        if(start > 0)
        {
            vector<string> vec2 = help(start - 1, digits);
            for(auto& str : vec2)
            {
                for(auto& ch : vecvec[digits[start] - '2'])
                {
                    vec.push_back(str + ch);   
                }
            }
        }
        else if(start == 0)
        {
            for(auto& ch : vecvec[digits[0] - '2'])
            {
                vec.push_back(string(1, ch));   
            }
        }
        return vec;
    }

    vector<string> letterCombinations(string digits) {
        return help(digits.size() - 1, digits);
    }

    protected:
        vector<vector<char>> vecvec;
};
```
