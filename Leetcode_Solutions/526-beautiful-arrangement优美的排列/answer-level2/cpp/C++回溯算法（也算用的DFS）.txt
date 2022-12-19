![QQ图片20191130202934.png](https://pic.leetcode-cn.com/5a951a5dd1bec5df0445f47c63a591584e076af126f2e27d5fe23c29960024cb-QQ%E5%9B%BE%E7%89%8720191130202934.png)
这道题思路其实很容易，就是测试1-N个位置，按照题设的规则，测试哪些数还可以放入
```
class Solution {
public:
    int ans = 0;    //结果设为全局变量，便于回溯中直接调用 
    void backTrace(int k, int N, vector<int>& temp, vector<int>& vis)
    {
        if(temp.size() == N)    //已经找到一个满足要求的数组
        {
            ans++;
            return;
        }

         for(int j = 1; j <= N; j++)    //遍历所有数
        {
            if(!vis[j] && ((k + 1) % j == 0 || j % (k + 1) == 0))   //当该数还未填入到数组中（vis == 0）且满足条件之一
            {
                vis[j] = 1;     
                temp.push_back(j);      //将该数字放入数组
                backTrace(k + 1, N, temp, vis);     //继续回溯
                temp.pop_back();    //回到之前，将刚才加入数组的数弹出
                vis[j] = 0;
            }
        }
    }
    int countArrangement(int N) {
        vector<int> t;  //存放答案
        vector<int> vis(16, 0);     //标记数组
        backTrace(0, N, t, vis);
        return ans;
    }
};
```
算比较好理解一点。第一次写题解，写的不好多多见谅！
