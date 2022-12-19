### 解题思路
1.将s里的每一个单词加入res数组中。
2.res数组中单词长度最大的赋给maxlen。
3.将res数组中长度小于该maxlen的加上' '（空格字符）直到数目等于maxlen。
4.遍历。第一个for循环为元素长度的遍历，第二个循环为res元素的遍历，根据题意，后面的空字符不需要，所以碰到第一个不为' '字符，ans[i]才开始添加。

### 代码

```cpp
class Solution {
public:
    vector<string> printVertically(string s) {
        if(s.size()==0) return {};
        int maxlen=0,count=0;
        vector<string>res;
        string tmp="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                tmp+=s[i];
                count++;
                maxlen=max(maxlen,count);
            }
            else {
                res.push_back(tmp);
                tmp="";
                count=0;   
            }
        }
        res.push_back(tmp);
        for(int i=0;i<res.size();i++){
            while(res[i].size()<maxlen){res[i]+=' ';}
        }
        vector<string>ans(maxlen,"");
        for(int i=maxlen-1;i>=0;i--){
            int j=res.size()-1;
            while(res[j][i]==' ') {j--;}
            while(j>=0){
                ans[i]+=res[j][i];
                j--;
            } 
            cout<<ans[i]<<endl;
        }
        for(int i=0;i<ans.size();i++){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};
```