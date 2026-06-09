### 解题思路
2大步骤：
1.把"{a,b}c{d,e}f"转化成{ab","c","d,e","f"}并且内部排序
2.dfs深度搜索排列

![image.png](https://pic.leetcode-cn.com/b3fa84f8924c255becb164464f06065d359bb4d37fdbdee32bf8c049fc2aa53d-image.png)

### 代码

```cpp
class Solution {
    string tmp;
    vector<string> result;
public:
    vector<string> expand(string S) {
        int n = S.size();
        if(n==0) return result;
        vector<string> ss = split(S);
        int ss_size = ss.size();
        for(auto& s:ss){
            sort(s.begin(),s.end());
        }
        dfs(ss,0,ss_size);
        return result;
    }
    void dfs(vector<string>& ss,int i,int ss_size){
        if(i==ss_size) {
            result.push_back(tmp);
            return;
        }
        for(auto a:ss[i]){
            tmp+=a;
            dfs(ss,i+1,ss_size);
            tmp.pop_back();
        }
    }
    vector<string> split(string S){
        int n = S.size();
        vector<string> res;
        string tmp = "";
        int left=0,right=0;
        while(right<n){
            if(S[right]>='a'&&S[right]<='z'){
                tmp=S[right];
                res.push_back(tmp);
                right++;
            }
            else if(S[right]=='{'){
                tmp="";
                right++;
                while(S[right]!='}'&&right<n){
                    if(S[right]!=',') tmp+=S[right];
                    right++;
                }
                res.push_back(tmp);
            }
            else right++;
        }
        return res;
    }
};
```