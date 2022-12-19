### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> nodePaths[N];
        vector<int> ansewr(N);
        for(int i=0;i<paths.size();i++){
            nodePaths[paths[i][0]-1].push_back(paths[i][1]);
            nodePaths[paths[i][1]-1].push_back(paths[i][0]);
        }
        
        for(int i=0;i<N;i++){
            set<int> tempPath;
            //cout << nodePaths[i].size() << endl;
            
            for(int j=0;j<nodePaths[i].size();j++){
                int node = nodePaths[i][j];
                tempPath.insert(ansewr[node-1]);
            }
            
            int num = 1;
            for(set<int>::iterator it=tempPath.begin();it!=tempPath.end();it++){
                
                if(*it==0){
                    continue;
                }
                if(*it == num){
                    num++;
                }else{
                    break;
                }
            }
            ansewr[i] = num;
        }
        return ansewr;
    }
};
```