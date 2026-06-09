中规中矩的做法就是递归了。注释写在代码中记录一下吧。

```
class Solution {
public:
    vector<int>res;//保存所有结果
    void helper(int num,int& N,int& K,int len){
        //参数说明：num表示当前数字，len表示当前数字的长度
        if(len==N){//达到所需长度，直接添加进结果即可
            res.push_back(num);
            return;
        }
        int n=num%10;//取最后一位数，用来判断接下来的数字
        if(n+K<=9)helper(num*10+n+K,N,K,len+1);//下一位递增
        if(n-K>=0)helper(num*10+n-K,N,K,len+1);//下一位递减
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        for(int i=1;i<=9;i++){
            helper(i,N,K,1);
        }
        if(N==1)res.push_back(0);//N=1时需要考虑0
        return res;
    }
};
```
