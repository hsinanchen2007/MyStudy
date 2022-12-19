字典序，1，10，100...，首先想到的就是dfs
```
class Solution {
public:
    void dfs(vector<int>& res,int num,int n){
        if(num>n)return;
        for(int i=0;i<=9;i++){
            if(num+i>n||(num+i==10&&i!=0))break;//抛去初始值为10的情况，因为在num=1，i=0的时候递归就可以得到。
            res.push_back(num+i);//依次将num+i添加到res中
            dfs(res,(num+i)*10,n);//乘以10在此递归
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        dfs(res,1,n);
        return res;
    }
};
```
