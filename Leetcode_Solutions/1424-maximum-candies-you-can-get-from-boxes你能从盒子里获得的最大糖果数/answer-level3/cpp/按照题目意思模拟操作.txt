按照题目意思这个题目应该进行如下操作:
1. 从拿到手的箱子中看有哪些箱子能打开(这里的能打开分为两种情况一是已经打开二是没打开但是有钥匙)
2. 从能打开的箱子中获得钥匙和新箱子
3. 取糖果
重复进行以上操作直到没有新箱子，同时获得的箱子都打不开
```cpp
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int sum=0;
        map<int,int> p_key;   //判断相应的箱子是否存在钥匙
        
        vector<int> res;        //存放获得的箱子
        for(auto ar:initialBoxes)
            res.push_back(ar);

        while(res.size()!=0)
        {
            int j=0;
            for(int i=0;i<res.size();i++)
            {
                if(status[res[i]]==1||(status[res[i]]==0&&p_key[res[i]]==1))  //遍历所有获得的箱子看是否有能打开的，
                    //如果没有能打开的就打开，否则丢弃第一个箱子
                {
                    j=i;
                    break;
                }
            }
            int index=res[j];
            res.erase(j+res.begin());   //此箱子是进行操作的箱子,无论打不打得开都从res中删除
           
            if(status[index]==1)    //已经是打开的箱子
            {
                sum+=candies[index];
                for(auto ar:containedBoxes[index])        //取出箱子里面存放的新箱子，加入到res中
                    res.push_back(ar);
                 for(auto ar:keys[index])  //吧打开的箱子里面的钥匙取出来
                    p_key[ar]=1;
            }   
            else if(status[index]==0&&p_key[index]==1)  //关闭但是有钥匙
            {
                sum+=candies[index];
                for(auto ar:containedBoxes[index])     //取出箱子里面存放的新箱子，加入到res中
                res.push_back(ar);
                 for(auto ar:keys[index])  //吧打开的箱子里面的钥匙取出来
                    p_key[ar]=1;
            }

        }
        return sum;
    }
};

```
