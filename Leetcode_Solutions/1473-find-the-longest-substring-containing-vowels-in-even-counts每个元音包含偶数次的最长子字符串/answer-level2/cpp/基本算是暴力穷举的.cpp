先统计前若干个字符里出现各种元音字母的个数。

这样可以快速算出子串s[start:end]到底符合不符合。

二重循环，外层start从前往后，内层end从后往前。

如果得出一个可行解，更短的字符串的情况可以跳过。

```
class Solution {
public:
    bool test(vector<vector<int>>&board,int start,int end){
        bool flag=1;
        for(int j=0;j<5;j++){
            if((board[j][end]-board[j][start])%2){
                flag=0;break;
            }
        }
        return flag;
    }
    int findTheLongestSubstring(string s) {
        vector<char>alpha{'a','e','i','o','u'};
        vector<vector<int>>board(5,vector<int>(s.size()+1,0));
        for(int i=0;i<s.size();i++){
            for(int j=0;j<5;j++){
                board[j][i+1]=board[j][i];
                if(s[i]==alpha[j])board[j][i+1]++;
            }
        }
        int ans=0;
        int start=0,end=s.size();
        for(;start<s.size();start++){
            end=s.size();
            if(end-start<ans)break;
            while(start<end){
                if(test(board,start,end))break;
                end--;
            }
            ans=max(ans,end-start);
        }
        return ans;
    }
};
```
