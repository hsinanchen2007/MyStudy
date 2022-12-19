### 解题思路

思路：有些说回溯的题解，其实感觉就是DFS深度搜索，dfs(string cop,string restDigits),cop是正在组合的字母，等剩余数字字符串为空也就是长度为0时，把一个字母最终组合放到res数组里，变量temp是用来存数字字符对应的字母字符串的，比如扫描到2时，temp为abc，再循环temp，拿出其中每个字母和剩下的数字字符串作DFS，DFS的终止条件就是没有数字可以扫描到了，比如“23”，扫描完3后，就没有了，先把ad加到res数组里。
### 代码

```cpp
class Solution {
public:
    map<string,string> m;
    vector<string>res;
    vector<string> dfs(string cop,string restDigits){
        if(restDigits.length()==0){
            res.push_back(cop);
        }
        string cur=restDigits.substr(0,1);
        string temp=m[cur];
        for(int i=0;i<temp.length();i++){
                //cop+=temp[i]  不能用这句，否则会改变cop，本来只应该传和过去
            dfs(cop+temp[i],restDigits.substr(1));//
        }
        return res;
    }

    vector<string> letterCombinations(string digits) {
        m["2"]="abc";
        m["3"]="def";
        m["4"]="ghi";
        m["5"]="jkl";
        m["6"]="mno";
        m["7"]="pqrs";
        m["8"]="tuv";
        m["9"]="wxyz";
        if(digits.length()!=0){
            return dfs("",digits);
        }else{
            return res;
        }
    }
};
```