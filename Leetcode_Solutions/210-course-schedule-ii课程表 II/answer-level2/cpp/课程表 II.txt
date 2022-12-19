### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeep(numCourses);
        set<int> outdeep[numCourses];
        set<int> zeroNodes;
        vector<int> result;
        for(int i=0;i<prerequisites.size();i++){
            vector<int> temp = prerequisites[i];
            indeep[temp[0]]++;
            outdeep[temp[1]].insert(temp[0]);
        }

        for(int  i=0;i<numCourses;i++){
            if(indeep[i]==0){
                zeroNodes.insert(i);
            }
        }

        return KanhProcess(indeep,zeroNodes,outdeep);
    }

    vector<int> KanhProcess(vector<int> &indeep,set<int>& zeroNodes,set<int> outdeep[]){
        int zeroIndexTemp = 0;
        vector<int> result;
        while(zeroNodes.size()!=0){
            zeroIndexTemp = *(zeroNodes.begin());
            zeroNodes.erase(zeroIndexTemp);
            result.push_back(zeroIndexTemp);
            //cout << zeroIndexTemp << endl;
            while(outdeep[zeroIndexTemp].size()!=0){
                int outEdge = *(outdeep[zeroIndexTemp].begin());
                //cout << outEdge << endl;
                outdeep[zeroIndexTemp].erase(outEdge);
                indeep[outEdge] = indeep[outEdge] - 1;
                if(indeep[outEdge] == 0){
                    zeroNodes.insert(outEdge);
                }
            }
        }
        for(int i=0;i<indeep.size();i++){
            if(outdeep[i].size()!=0){
                vector<int> result1;
                return result1;
            }
        }

        return result;
    }
};
```