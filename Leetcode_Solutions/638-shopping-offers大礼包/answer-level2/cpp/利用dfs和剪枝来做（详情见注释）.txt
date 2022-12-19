```
class Solution {
public:
    int minFee=0x3f3f3f3f;//设置一个变量存最小的钱数
    void dfs(int fee,vector<int> &need,vector<int>& price, vector<vector<int>>& special,int s)//s表示搜索到第s个大礼包了
    {
        
        if(minFee<fee) return;//剪枝1,当前费用比最小的大了就不用搜了
        if(accumulate(need.begin(),need.end(),0)==0) {//剪枝2,当前就已经满足希求了，这时候直接更新一下最小值并返回就可以了，也不用再搜了
            if(minFee>fee) minFee=fee;
            return;
        }
        if(s>=special.size())//dfs的退出条件，搜完所有的大礼包，就看一下还有哪些需求不满足，就直接买
        {
            for(int i=0;i<need.size();i++)
                fee+=need[i]*price[i];
            if(minFee>fee) minFee=fee;
            return;
        }
        vector<int> sNeed(need);//设置一个变量，买当前大礼包之后还剩余的需求是什么
        int flag=0;
        for(int i=0;i<special[s].size()-1;i++)
        {
             if(need[i]<special[s][i])//如果当前礼包有供大于求的情况就退出
            {
                flag=1;
                break;
            }
            sNeed[i]-=special[s][i];
       //     cout<<sNeed[i]<<" ";
        }
       // cout<<endl;
        dfs(fee,need,price,special,s+1);//不买这个礼包，交给dfs来处理之后的情况
        if(!flag)
        dfs(fee+special[s][special[s].size()-1],sNeed,price,special,s);//买这个礼包之后，交给dfs来处理之后的情况
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
      //  return 0;
        for(int i=0;i<special.size();i++)//一个循环除去那些存在不需要的物品的大礼包
        {
            if(special[i].size()>price.size()+1)
                special.erase(special.begin()+i);
        }
        int fee=0;
        vector<int> need(needs);
        dfs(fee,need,price,special,0);
        return minFee;
    }
};
```
