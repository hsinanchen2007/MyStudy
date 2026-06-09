### 解法一：递归
1. 变量index表示我们当前递归函数要处理的下标为index的字符的下标，假如某次递归index和字符串长度相等，说明我们处理完字符串S，则把处理的结果假如到结果字符串集合
2. 那么如何处理第index号字符呢？如果第index号字符是数字，那么我们不处理它。假如是字母，可以不修改它，然后进入下一层递归处理第index+1号字符；也可以选择修改它，然后进入下一层递归处理第index+1号字符。


### 解法一代码

```cpp
class Solution {
public:
    vector<string> ans; 
    vector<string> letterCasePermutation(string S) {
        dfs(S, 0);
        return ans;
    }
    void dfs(string& S, int index){
        if(index == S.size()){
            ans.push_back(S);
            return;
        }
        //未修改当前字符(字母或者数字)的一条分支
        dfs(S, index+1);
        //修改当前字母的的另一条分支
        if(isalpha(S[index])){
            S[index] = S[index] ^ 32;
            dfs(S, index+1);
        }
    }
};
```


### 解法二：非递归
参考用户@Gary chan的实现

### 代码二：
```cpp
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans{S};
        for(int i = 0; i < S.size(); i++){
            if(isalpha(S[i])){
                for(int j = ans.size() - 1; j >= 0; j--){
                    ans.push_back(ans[j]);
                    if(isupper(ans[j][i])) ans[j][i] = tolower(ans[j][i]);
                    else ans[j][i] = toupper(ans[j][i]);
                }
            }
        }
        return ans;
    }
};

```
