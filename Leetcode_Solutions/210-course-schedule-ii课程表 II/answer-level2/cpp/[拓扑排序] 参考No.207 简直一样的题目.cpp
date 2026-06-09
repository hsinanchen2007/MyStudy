### 题意说明，输出是 依赖“顺序”约定的，因此想到是topo排序，写给新手朋友一同搞定topo排序的题目，207题目注释非常完整可参考 [LeetCode.207](https://leetcode-cn.com/problems/course-schedule/solution/c-tuo-bu-topopai-xu-jian-dan-yi-dong-zhu-shi-wan-z/)


![image.png](https://pic.leetcode-cn.com/dcb718fdaa748137415e3bb5bc32e246bea44a7766f546c65c154af49260d7f7-image.png)

### 代码

```cpp
/*
此题跟 207 题几乎就是一道题，只不过是输出是拓扑排序后的结果
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> inDegree(numCourses, 0);  // 记录Node的入度
        vector<vector<int>> adjLst(numCourses, vector<int>());  // 邻接表
        for(auto arr : prerequisites) {
            inDegree[arr[0]]++;  // 更新 入度及其邻接表adjTable
            adjLst[arr[1]].push_back(arr[0]);
        }
        
        queue<int> que;  // topo排序依赖的队列
        for(auto cnt=0;cnt<inDegree.size();cnt++) {
            if(inDegree[cnt]==0) que.push(cnt);
        }
        vector<int> res;
        while(!que.empty()) {
            auto tmp = que.front(); que.pop();
            // cout<< tmp << endl;
            res.push_back(tmp);  // 拓扑排序
            for(auto i : adjLst[tmp]) {   // 更新排序节点的连通nodes的入度
                if(--inDegree[i]==0) que.push(i);
            }
        }
        if(res.size() == numCourses) return res;
        else return {} ;
    }
};
```