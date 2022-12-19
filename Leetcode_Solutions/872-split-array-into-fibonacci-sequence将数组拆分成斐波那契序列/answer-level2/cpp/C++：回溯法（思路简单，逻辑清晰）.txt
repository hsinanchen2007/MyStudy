**题解：**
* 回溯法

**算法思路：**
* 1）i、j、k分别代表第一个、第二个和第三个数字的起始下标，i 初始化为0表示第一个数字的下标包含0
* 2）数字超过 INT_MAX 直接返回 false
* 3）回溯的出口为递归到字符串都完成匹配

思路来自：[@Over-Lord](/u/over-lord/)的[306. 累加和](https://leetcode-cn.com/problems/additive-number/solution/xia-biao-zuo-wei-fen-duan-dian-dfs-by-over-lord/)。

**代码如下：**
```cpp
class Solution {
public:
    vector<int> splitIntoFibonacci(string& S) {
        vector<int> res;
        int i=0;
        for(int j=i+1;j<S.size();++j){
            for(int k=j+1;k<S.size();++k){
                res.clear();
                if(backtrack(S,i,j,k,res)){
                    if(res.size()>2){
                        return res;
                    }
                }
            }
        }
        return {};
    }

    bool backtrack(string& S,int i,int j,int k,vector<int>& res){
        if((S[i]=='0'&&j-i>1)||(S[j]=='0'&&k-j>1))return false;//s[i]、s[j]为'0'，相差一位的话，满足题意
        long long a=0,b=0;
        for(int c=i;c<j;++c){
            a=a*10+S[c]-'0';
            if(a>INT_MAX)return false;
        }
        for(int c=j;c<k;++c){
            b=b*10+S[c]-'0';
            if(b>INT_MAX)return false;
        }
        if(k==S.size()){
            res.push_back(a);
            res.push_back(b);
            return true;
        }
        string sum=to_string(a+b);
        for(int c=0;c<sum.size();++c){
            if(S[c+k]!=sum[c])return false;
        }
        res.push_back(a);
        return backtrack(S,j,k,k+sum.size(),res);
    }
};
```
