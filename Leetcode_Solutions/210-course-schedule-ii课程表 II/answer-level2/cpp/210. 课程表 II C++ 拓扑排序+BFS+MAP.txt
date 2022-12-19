### 解题思路
拓扑排序 可以参考：https://www.cnblogs.com/bigsai/p/11489260.html
1.度的含义：即该节点的父节点的个数，度为0的节点即根，一张图上可以有多个根
2.算法：
1）计算有向图的度
2）以度为0的节点，进行初始队列，进行bfs。如果度为0的节点A有子节点B，则B节点degreeB--，如果B节点的度为0则加入队列
度为0的逻辑含义表示：没有其他节点在该节点之前，即为该图的根；
3）通过删除度为0的节点，会产生新的度为0的节点，将度为0的节点加入队列。
当队列为空时，如果结果序列result长度不等于numCourses时，说明存在环，导致无法找到度为0的节点。

### 代码

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> degree = vector<int>(numCourses,0);
        vector<int> result;
        deque<int> buff;
        map<int, vector<int>> coursemap;

        if(prerequisites.empty()||prerequisites[0].empty()){
            for (int i = 0; i < numCourses;i++){
                result.push_back(i);
            }
            return result;
        }

        for (int i = 0; i < prerequisites.size();i++){
            degree[prerequisites[i][0]]++;
            coursemap[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < degree.size();i++){
            if(degree[i] == 0){
                buff.push_back(i);
            }
        }

        while(!buff.empty()){
            int length = buff.size();
            for (int i = 0; i < length;i++){
                result.push_back(buff.front());
                for(auto num:coursemap[buff.front()]){
                    degree[num]--;
                    if(degree[num] == 0){
                        buff.push_back(num);
                    }
                }

                buff.pop_front();
            }
        }

        if(result.size()== numCourses){
            return result;
        }

        return vector<int>();
    }
};
```