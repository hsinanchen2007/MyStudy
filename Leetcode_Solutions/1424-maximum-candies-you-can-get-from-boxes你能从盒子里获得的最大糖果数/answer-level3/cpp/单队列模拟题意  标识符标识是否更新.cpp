算法流程
1 将当前获得得盒子添加到队列当中
2 取出盒子 判断是否有钥匙打开获得得盒子，能打开，添加糖果，并更新新盒子包含得钥匙与盒子 如果不能打开 记录此盒子
3 如果不能打开得盒子在 队列中得元素全部遍历一遍后 依然打不开 结束循环 返回总糖果数
```
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<int> hash(n, 0);
        int res = 0;
        queue<int> que;
        int flag;
        for(auto i:initialBoxes) que.push(i);
        while(!que.empty()){
            int now = que.front();
            hash[now] = 1;
            que.pop();
            if(status[now] == 1){
                res += candies[now];
                for(auto temp:keys[now]){
                    status[temp] = 1;
                }
                for(auto temp:containedBoxes[now]){
                    que.push(temp);
                }
            }
            else{
                if(flag == now)
                    break;
                flag = now;
                
                que.push(now);
            }
        }
            
        return res;
    }
};
```
