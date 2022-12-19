### 解题思路
在无重复字符代码的基础上先对字符串进行排序，这样重复字符必然相邻，然后在回溯过程中加一句判断条件去除重复排列

### 代码

```cpp
class Solution {
public:
    vector<string>res;
    vector<string> permutation(string S) {
        string s;
        int n=S.size();
        sort(S.begin(),S.end());//排序使得重复字符相邻
        vector<int>flag(n);
        process(S,s,n,flag);
        return res;
    }
    void process(string S,string& s,int n,vector<int>&flag)
    {
        //终止条件
        if(s.size()==S.size()){
            res.push_back(s);          
        }
        else{
            for(int i=0;i<n;i++){
                if(flag[i]==0){
                    if(i>0&&S[i]==S[i-1]&&flag[i-1]==1)continue;//若有重复字符，跳过该组合
                    s+=S[i];
                    flag[i]=1;
                    process(S,s,n,flag);
                    s.pop_back();//回溯到上一步
                    flag[i]=0;
                }
            }
        }
    }
};
```