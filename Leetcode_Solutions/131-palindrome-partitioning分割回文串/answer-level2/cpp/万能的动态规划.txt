
![image.png](https://pic.leetcode-cn.com/7a81be42fffbcb36c4d961094cf98cc74d180f80f7fa07a026af3944073156bf-image.png)

### 解题思路
以分析aabc为例,从a开始解所有的分割方案， 逐渐增加一个字符：aa --> aab  ---> 

```
a      : {a}
aa     : {a, a}   {aa}
aab    : {a,a,b}  {aa,b}      抛弃{a, ab} {aab}
aabc   : {a,a,b,c}{aa,b,c}    抛弃{a,a, bc} {aa,bc} {a,abc} {aabc}
```
总子每次增加一个字符后，从最后一个字符开始，分别于前面的n字符组成回文串，再加入到前面子串分割结果中。
例如：aab 增加一个字符c后为aabc
将 c 添加到aab的所有分割方案中： {a,a,b, c} {aa, b, c}
将 bc 添加到aa的所有分割方案中,但是bc不是回文串，直接抛弃
将 abc 添加到a的所有分割方案中,但是abc不是回文串，直接抛弃
最后判断aabc是不是回文串，不是则抛弃，否则加入到aabc的分割方案中。


### 代码

```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {

        if(s.size() < 2){
           return vector<vector<string>>(1, vector<string>(1, s));
        }

        int length = s.size();
        vector<vector<bool>> isReStr(length, vector<bool>(length, false));
        vector<vector<vector<string>>> dp;
        for(int i=0;i< s.size(); i++)
        {
            vector<vector<string>> curPart;
            for(int j = i; j > 0; j-- )
            {
                if(s[j] == s[i] && (i-j < 3 || isReStr[j+1][i-1])  )
                {
                    isReStr[j][i] = true;
                    string newStr(s.begin()+j, s.begin() + i +1);
                    for(auto elem : dp[j-1])
                    {
                        elem.push_back(newStr);
                        curPart.push_back(std::move(elem) );
                    }
                }    

            }
            if(s[0] == s[i] && (i < 3 || isReStr[1][i-1]) )
            {
                isReStr[0][i] = true;
                string newStr(s.begin(), s.begin() + i +1);
                curPart.push_back(vector<string>(1, newStr) );
            }
            dp.push_back( std::move(curPart) );
        }
        return dp[length -1];
    }
};
```