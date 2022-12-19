虽然这题用简单的一维动态规划就还可以ac，今天学习了背包，这道题用完全背包变种回答：
coins的值可以作为占用容量，价值是1.如题可以的得到{v , w}{1 ， 1}{ 1 ， 2}{1 ， 5}.
总背包容量是amount = 11 ;
问题转换为填满背包时总价值最小（经典背包问题时最大）。
详细过程参照https://www.imooc.com/article/286140
唯一的区别在于选取out or in 时 选择价值最小的策略。
最后输出。

```javascript []
class Solution {
public:
  int problen_total(int cap  , vector<vector<int>>infor)
{
    int num_obj = infor.size();
    vector<vector<int>> table(num_obj +1 , vector<int>(cap +1, 10000));
      for(int  i = 0 ; i < num_obj + 1 ; i ++)
          table[i][0] = 0;
     
    for(int i = 1 ; i <=num_obj ; i ++)
        for(int v = 1 ; v <= cap ; v++)
        {
            int val_i = infor[i - 1][0];
            int cap_i = infor[i - 1][1];
            int k = v/cap_i; //可容纳多少该物件
           // if(k > 1) k = 1;//此处变成  01 背包问题
            int min_t = 10000;
            for(int in = 0 ; in <= k ; in++)
            {
                int val_t = table[i - 1][v - in * cap_i] + in *  val_i;
                min_t = (min_t < val_t) ? min_t : val_t;
            }
            table[i][v] = min_t;
        }
      if( table[num_obj][cap] == 10000) return -1;
    return table[num_obj][cap];
} 
    int coinChange(vector<int>& coins, int amount) {
   
        
        //完全背包 ,选最小
        vector<vector<int>> infor;
        for(auto c:coins)
            infor.push_back({1 , c});
       return  problen_total(amount , infor );
    }   
};

```


     
    