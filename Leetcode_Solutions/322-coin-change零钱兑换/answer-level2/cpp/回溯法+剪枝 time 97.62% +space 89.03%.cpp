### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:


    int coinChange(vector<int>& coins, int amount) {
       sort(coins.begin(), coins.end());
       vector<int> temp;
        int res=INT_MAX;
        backtrack(coins.size()-1,temp,res,coins,0,amount);
        return res==INT_MAX?-1:res;
    }
    void backtrack(int coinindex,vector<int> &temp,int &res,vector<int> & coins,int sum,int amount)
    {
           
        for(int i=coinindex;i>=0;--i)
            {  
                if(sum==amount){
                  if(temp.size()<res)
                    res=temp.size();
                  return;
                }
               
                if(sum>amount) return; 
                if(res!=INT_MAX &&(amount-sum)/coins[i]+temp.size()>=res) return ;
                temp.push_back(coins[i]);
                backtrack(i,temp,res,coins,sum+coins[i],amount);
                temp.pop_back(); 
        }
    }
};
```