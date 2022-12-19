## 思路
- 1-首先分成两个坐标
- 2-each坐标验证是否合法并且合法的字符串所表示的坐标有多少个;
- 例如judge("1")=1;
- judge("10")=1
- 3-把每个合法的坐标存入左右坐标数组，例如[[0.1],[0.2],[0.4],[3,3]]
- 4-两个坐标组合得到结果。

```
vector<string> ambiguousCoordinates(string S) {
        vector<string> ret;
        int len=S.size();
        for(int i=1;i<len-2;i++){
            int m = judge(S,1,i);
            int n = judge(S,i+1,len-2);
            appends(S,ret,m,n,i);
        }
        return ret;
    }
```

## 一、首先分解坐标
思路是首先👋我们要拆成左坐标与右坐标从
S[1]-S[n-2]
设一个中间的i从1到n-1
表示的是S[1]-到S[i]的字符串代表左坐标 和S[i+1]到 S[n-1]

## 二、然后判断合法和包含的合法坐标字符串个数：

这里需要判断
a>长度是否为1，这种状态只有一个返回1
b>首尾是否为0，这种状态不合法返回0
c>首位为0，末尾不为0，这种只能0.xxxx，返回状态-1
d>其他状态，总共n-m+1种
```
    int judge(string &S,int m,int n){
        if(n-m==0)return 1;
        else if(S[m]=='0'&&S[n]=='0')return 0;
        else if(S[n]=='0')return 1;
        else if(S[m]=='0')return -1;
        else return n-m+1;
    }
    
```

## 三、进行组合
这里直接把我们第一步做的拆分两个坐标的拆分位置传入参数，
然后判断左右坐标的合法个数，
把他们的合法数存入数组
然后进行组合

```

    void appends(string &S,vector<string> &ret,int m,int n,int i){
        if(m==0||n==0)return;
        vector<string> ret1;
        vector<string> ret2;
        if(m==1) ret1.push_back(S.substr(1,i));
        else if(m==-1)ret1.push_back(S.substr(1,1)+'.'+S.substr(2,i-1));
        else {
            for(int t=0;t<m-1;t++){
                ret1.push_back(S.substr(1,t+1)+'.'+S.substr(t+2,i-t-1));
            }
            ret1.push_back(S.substr(1,m));
        }
        
        if(n==1) ret2.push_back(S.substr(i+1,S.size()-i-2));
        else if(n==-1)ret2.push_back(S.substr(i+1,1)+'.'+S.substr(i+2,S.size()-i-3));
        else {
            for(int t=0;t<n-1;t++){
                ret2.push_back(S.substr(i+1,t+1)+'.'+S.substr(i+t+2,S.size()-i-t-3));
            }
            ret2.push_back(S.substr(i+1,n));
        }
        
        for(int i=0;i<ret1.size();i++){
            for(int j=0;j<ret2.size();j++){
                ret.push_back("("+ret1[i]+", "+ret2[j]+")");
            }
        }
        
    }
```

## 四、总结
希望看的开心的您可以给个建议
新手菜鸟希望多多学习。
```
class Solution {
public:
    int judge(string &S,int m,int n){
        if(n-m==0)return 1;
        else if(S[m]=='0'&&S[n]=='0')return 0;
        else if(S[n]=='0')return 1;
        else if(S[m]=='0')return -1;
        else return n-m+1;
    }
    
    void appends(string &S,vector<string> &ret,int m,int n,int i){
        if(m==0||n==0)return;
        vector<string> ret1;
        vector<string> ret2;
        if(m==1) ret1.push_back(S.substr(1,i));
        else if(m==-1)ret1.push_back(S.substr(1,1)+'.'+S.substr(2,i-1));
        else {
            for(int t=0;t<m-1;t++){
                ret1.push_back(S.substr(1,t+1)+'.'+S.substr(t+2,i-t-1));
            }
            ret1.push_back(S.substr(1,m));
        }
        
        if(n==1) ret2.push_back(S.substr(i+1,S.size()-i-2));
        else if(n==-1)ret2.push_back(S.substr(i+1,1)+'.'+S.substr(i+2,S.size()-i-3));
        else {
            for(int t=0;t<n-1;t++){
                ret2.push_back(S.substr(i+1,t+1)+'.'+S.substr(i+t+2,S.size()-i-t-3));
            }
            ret2.push_back(S.substr(i+1,n));
        }
        
        for(int i=0;i<ret1.size();i++){
            for(int j=0;j<ret2.size();j++){
                ret.push_back("("+ret1[i]+", "+ret2[j]+")");
            }
        }
        
    }
    

    vector<string> ambiguousCoordinates(string S) {
        vector<string> ret;
        int len=S.size();
        for(int i=1;i<len-2;i++){
            int m = judge(S,1,i);
            int n = judge(S,i+1,len-2);
            appends(S,ret,m,n,i);
        }
        return ret;
    }
};
```
