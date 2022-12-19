### 解题思路
1、递归

### 代码

```cpp
class Solution {
public:

    //index是字母索引数组(letter_indices)的索引
    void letter_cast_permute(const string& s, const vector<int>& letter_indices, int index, vector<string>& res)
    {
        if (index == letter_indices.size())
        {
            res.push_back(s);
            return;
        }

        letter_cast_permute(s, letter_indices, index + 1, res); //不变

        //转换大小写
        string tmp = s;
        if (islower(tmp.at(letter_indices.at(index))))
        {
            tmp.at(letter_indices.at(index)) = toupper(tmp.at(letter_indices.at(index)));
        }
        else
        {
            tmp.at(letter_indices.at(index)) = tolower(tmp.at(letter_indices.at(index)));
        }
        
        letter_cast_permute(tmp, letter_indices, index + 1, res);
    }

    vector<string> letterCasePermutation(string S) {

        //统计字母的索引
        vector<int> letter_indices;
        letter_indices.reserve(S.size());

        for (int i = 0; i < S.size(); ++i)
        {
            //if (S.at(i) >= 'A' && S.at(i) <= 'z')
            if(isalpha(S.at(i)))
            {
                letter_indices.push_back(i);
            }
        }

        vector<string> res;
        res.reserve(S.size() * 2);
        letter_cast_permute(S, letter_indices, 0, res);

        return res;
    }
};
```