### 解题思路
先用map数组把S中的字符位置记录一下
再去扫描words中的单词，如果能从map中找到一个递增的字符下标序列，res++

### 代码

```cpp
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>>v(26);
        for(int i=0;i<S.size();i++) v[S[i]-'a'].push_back(i);//map数组，存储字符出现的每个位置
        int pre,f;
        int i,j,k;
        int res=0;
        for(i=0;i<words.size();i++){//扫描每个单词
            pre=-1;
            for(j=0;j<words[i].size();j++){//分解单词，扫描每个字符
                f=0;
                for(k=0;k<v[words[i][j]-'a'].size();k++){
                    if(v[words[i][j]-'a'][k]>pre){
                        pre=v[words[i][j]-'a'][k];f=1;break;
                    }
                }
                if(f==0) break;//只有该字母找到了一个对于S的下标，才继续，否则直接跳出循环
            } 
            if(j==words[i].size()) res++;//扫描到该单词末尾，说明存在该子序列
        }
        return res;
    }
};
```