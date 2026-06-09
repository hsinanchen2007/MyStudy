根据定义求解，对一条路径向下求解，当超出n的范围时，开始下一条路径，同时注意含有多种0的情况，如下：

1）迭代求解：
```
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur=1;
        for(int i=0;i<n;i++){
            res[i]=cur;
            if(cur*10<=n){
                cur*=10;
            }else{
                if(cur>=n) cur/=10;
                cur+=1;
                while(cur%10==0) cur/=10;
            }
        }
        return res;
    }
};
```


2）递归求解
```
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1;i<10;i++){
            helper(i,n,res);
        }
        return res;
    }
    void helper(int cur,int n,vector<int>& res){
        if(cur>n) return;
        res.push_back(cur);
        for(int i=0;i<10;i++){
            if(cur*10+i<=n){
                helper(cur*10+i,n,res);
            }else break;
        }
    }
};
```
