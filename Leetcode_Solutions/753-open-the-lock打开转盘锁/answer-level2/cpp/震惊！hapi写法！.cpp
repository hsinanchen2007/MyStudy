### 解题思路
和其他人的思路大同小异。

### 代码

```cpp
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 从 target出发 dead:优化查找, visited:避免重复入队
        set<string> dead;
        set<string> visited;
        for(string it : deadends){
            dead.insert(it);
        }
        // 如果dead中含有“0000”则-1
        if(dead.count("0000")){
            return -1;
        }
        queue<string> go;
        go.push(target);
        visited.insert(target);

        int deep = 0;
        while(!go.empty()){
            deep++;
            int curSize = go.size();
            // 把当前层的节点出队
            while(curSize--){
                string tmp = go.front();
                go.pop();
                // 四个位置入队
                for(int i=0;i<4;i++){
                    char ch = tmp[i];

                    // 上转
                    tmp[i] = ((tmp[i] - '0' + 9) % 10) + '0';
                    if(tmp == "0000"){
                        return deep;
                    }
                    // 没有被访问过且不存在dead中
                    if(dead.count(tmp) == 0 && visited.count(tmp) == 0){
                        visited.insert(tmp);
                        go.push(tmp);
                    }
                    // 恢复
                    tmp[i] = ch;

                    // 下转
                    tmp[i] = ((tmp[i] - '0' + 1) % 10) + '0';
                    if(tmp == "0000"){
                        return deep;
                    }
                    // 没有被访问过且不存在dead中
                    if(dead.count(tmp) == 0 && visited.count(tmp) == 0){
                        visited.insert(tmp);
                        go.push(tmp);
                    }
                    // 恢复
                    tmp[i] = ch;
                }               
            }
        }
        // 最后都无法达到"0000"
        return -1;
    }
};
```