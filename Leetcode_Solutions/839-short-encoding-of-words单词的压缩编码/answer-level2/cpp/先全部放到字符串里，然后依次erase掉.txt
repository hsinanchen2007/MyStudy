### 解题思路
先将全部单词后加“#”，组成字符串S;
然后通过exitPos返回每个单词在S中出现的n个位置；
如果单词在S中出现次数 > 1，检查出现之前是否为“#”，如果是就删除该单词和“#”；
最后返回S的长度。

### 代码

```cpp
class Solution {
public:
    vector<int> exitPos(string S,string word){
        vector<int> ans;
        int len,cur;
        word += '#';
        len = word.size();

        cur = S.find(word);
        while(cur != string::npos){
            ans.push_back(cur);
            cur = S.find(word,cur+len);
        }

        return ans;
    }

    int minimumLengthEncoding(vector<string>& words) {
        int len = words.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return words[0].size()+1;

        string S = "";
        for(int i = 0;i < len;i++){
            S += words[i];
            S += '#';
        }

        for(int i = 0;i < len;i ++){
            vector<int> ans = exitPos(S,words[i]);
            
            for(int j = 0;j < ans.size();j++){

                if(ans.size() == 1)
                    break;

                if(ans[j] != 0){
                    if(S[ans[j]-1] == '#'){
                        S.erase(ans[j],words[i].size()+1);
                    }
                }
                else{
                    S.erase(0,words[i].size()+1);
                }         
                
                ans = exitPos(S,words[i]);   
            }
        }

        return S.size();
    }
};
```