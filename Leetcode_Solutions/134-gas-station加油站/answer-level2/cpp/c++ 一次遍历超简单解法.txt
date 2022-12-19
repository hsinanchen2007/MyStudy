/*!
 *思路: 当前的油量减去消耗即为油量的剩余（负数为缺口），sum[i]为前i个剩余油量的总和。
        这是一条曲线，曲线的最低点即为结束的点，起点则从下一个点开始，这个你细品一下就明白。
        结果判断总和是不是大于等于0，只有大于等于0，结果才是有效的。
 */







class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int minVal = INT_MAX;
      int sum    = 0;
      int ans    = 0;

      for(int i = 0; i < gas.size(); i++){
        sum += gas[i] - cost[i];
        if(minVal > sum){//找到比之前更低的点
          minVal = sum;
          ans = (i + 1) % gas.size(); //记录下一个位置
        }
      }

      if(sum >= 0){
        return ans;
      }

      return -1;
    }
};
