根节点从0开始搜索，后续子节点为n的最小完全平方数与根节点的和。
![IMG_0784.jpg](https://pic.leetcode-cn.com/131c6fe1ded75be7f3d29cad5c589726cad8c04c0923617cccf6f985cbe23ca1-IMG_0784.jpg)

```
class Solution {
public:
    int numSquares(int n) {
        int min_sqrt_n = floor(sqrt(n));
        queue<int> Queue;
        Queue.push(0);
        int step = 0;
        
        while(!Queue.empty()){
            step ++;
            int size = Queue.size();
            for(int i = 0; i < size; i++){
                int front = Queue.front();
                Queue.pop();
                for(int j = 1; j <= min_sqrt_n; j++){
                    int sum = front + pow(j, 2);
                    if(sum == n) return step;
                    if(sum > n) continue;
                    Queue.push(sum);
                }
            }
        }
        return -1;
    }
};
```
