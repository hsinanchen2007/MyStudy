### 解题思路
先用 string[] 保存摩尔斯密码映射字典
set<string> ans 保存单词映射后的摩尔斯密码(去重)
返回ans.size()即可
### 代码

```cpp
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        //所有26个英文字母对应摩尔斯密码表
        string morse[26] ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> ans;
        for(auto s: words)
        {
            string curr("");
            for(auto c : s){
                curr += morse[c-'a'];
            }
            ans.insert(curr);
        }
        return ans.size();
    }
};
```