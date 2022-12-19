利用string的find函数，从长到短寻找，没找到就加上长度。
这题目思路到比较清晰，重点是保证速度，官方答案的字典树应该是最有效率的，不过有点难写。
这里不用官方的find函数就会超时。
```
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        vector<vector<string>> total;
        total.resize(7);
        for(auto x:words){
            total[x.size()-1].push_back(x);
        }
        string s="";
        int res=0;
        for(int i=6;i>=0;--i){
            for(int j=0;j<total[i].size();++j){
                if(s.empty()){
                    s=total[i][j]+"#";
                    res=total[i][j].size()+1;
                }
                else if(s.find(total[i][j]+"#")==string::npos){
                    s+=total[i][j]+"#";
                    res+=total[i][j].size()+1;
                }
            }
        }
        return res;
    }
};
```
