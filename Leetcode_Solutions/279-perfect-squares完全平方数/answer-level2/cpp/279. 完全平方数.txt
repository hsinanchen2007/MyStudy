盗用别人的一张图，来加深自己的记忆，一般涉及到最短距离，一般是用BFS来进行搜索
![image.png](https://pic.leetcode-cn.com/1650e77ba56fdfaf0bac01f44aa54d0509628a8e068793c37c0ec9c60259a4fa-image.png)

如上图所示, 以12为例.
BFS是宽搜索, 以0为起点, 按层遍历, 第一层默认为0.
第二层为 0 + i^2 <= n, i in [1, sqrt(n)] 的完全平方数之和next, 如果next没有在队列中出现过则添加至队列尾部. 图上添加了1, 4, 9.
第三层为第二层每个值(共三个,分别为1, 4, 9) + i^2, i in [1, sqrt(n)] 的完全平方数之和next, 如果next没有在队列中出现过, 则添加至队列尾部. 图上添加了2,5,10,8.
第四层为 第三层每个值(共四个, 分别为2,5,10,8) + i^2, i in [1, sqrt(n)] 的完全平方数之和next, 如果next没有在队列中出现过, 则添加至队列尾部. 图上添加了3,6,11,且在这一层next = 8 + 2^2 = 12, 直接返回dist.


```
class Solution {
public:
    int numSquares(int n) {
        queue<int> queueList;
        queueList.push(0);

        vector<bool> visited(n + 1, false);
        int loop;
        int result = 0;
        int currVal, nextVal;

        while (!queueList.empty()) {
            result++;
            int queueSize = queueList.size();
            while (queueSize) {
                currVal = queueList.front();
                queueList.pop();
                for (loop = 1; (loop * loop) + currVal <= n; loop++) {
                    nextVal = (loop * loop) + currVal;
                    if (nextVal == n) {
                        return result;
                    }

                    if (nextVal < n && !visited[nextVal]) {
                        queueList.push(nextVal);
                        visited[nextVal] = true;
                    }
                }
                queueSize--;
            }
        }

        return result;
    }
};
```


其他的解法可以参考：
https://leetcode-cn.com/problems/perfect-squares/solution/si-chong-jie-ti-si-lu-by-steven-29/