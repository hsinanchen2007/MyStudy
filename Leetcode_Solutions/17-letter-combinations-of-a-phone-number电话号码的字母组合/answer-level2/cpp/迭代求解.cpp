### 解题思路
用两个vector pre,ans进行迭代，每次从pre里取出字符串，在其末尾加入相应的字符，得到新一轮迭代的字符串，将每个字符串加入到ans中，最后，更新pre=ans，进行下一轮迭代

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
 map<int,string> s;
        s[1]="!@#";
        s[2]="abc";
        s[3]="def";
        s[4]="ghi";
        s[5]="jkl";
        s[6]="mno";
        s[7]="pqrs";
        s[8]="tuv";
        s[9]="wxyz";
        
        int len=digits.length();
        
        vector<string> pre;
        vector<string> ans;
        pre.push_back("");
        int cnt=0;
        for(int i=0;i<len;i++)
        {
            int digit=digits[i]-'0';
            string cur=s[digit];
            ans.clear();
            for(int j=0;j<cur.length();j++)
            {
                for(string p:pre)
                {
                    ans.push_back(p+cur[j]);
                }
            }
            pre=ans;
        }
        return ans;
    }
};
```