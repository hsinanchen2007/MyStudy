这道题实际就是递归问题，和青蛙跳台阶差不多，我想了好久才想出一个答案。
用类似广度优先的方法计算，不过用字典代替队列，时间超出。然后加了一个集合表示已经计算过的值，这些值肯定不会产生最少的硬币数量，内存和时间评价为5%。
本质上都是需要保存计算过的结果。
```
class Solution {
public:
    int cnt=0;
    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;
        set<int> s{amount};
    set<int> s_tmp;
    set<int> s_h(s);//剩余硬币数集合，之后不再计算这些数
    int flag=1;
    while(flag&&!s.empty()){
        for(auto it=s.begin();it!=s.end()&&flag;it++){
            for(int i=0;i<coins.size();i++){
                if(coins[i]==*it){
                    
                    flag=0;
                    break;
                }
                else if(coins[i]<*it && s_h.find(*it-coins[i])==s_h.end()){
                    s_tmp.insert(*it-coins[i]);
                    s_h.insert(*it-coins[i]);
                }
            }
        }
        ++cnt;
        s=s_tmp;
        s_tmp.clear();
    }
    if(flag) return -1;
    else return cnt;
    }
};
```
