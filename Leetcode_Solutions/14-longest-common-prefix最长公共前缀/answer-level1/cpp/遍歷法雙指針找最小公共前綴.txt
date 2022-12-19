### 解题思路
1. 遍歷二維數組的當前位，查看是否每一個單詞的當前位置都是相同的
2. 如果是，則將當前位放入答案中，如果不是則返回現有答案，即不包括當前位置的最大公共數組
3. 注意點：便利string數組要考慮首位越位問題，這裏代碼采用的是當前位和先前的位置進行對比判斷是否是公共單詞，因此數組應至少有兩個單詞，因此需要單獨處理size為0（沒有單詞，返回空string），1(一個單詞，返回本身)的情況

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int con=0,num=1;
        string ans="";
        if(strs.size()==0) return ans;
        if(strs.size()==1) return strs[0];
        while(con<strs[num].size())
        {
            while(num<strs.size())
            {
                if(strs[num][con]!=strs[num-1][con]) return ans;
                num++;
            }
            ans.push_back(strs[0][con]);
            con++;
            num=1;
        }
        return ans;
    }
};
```