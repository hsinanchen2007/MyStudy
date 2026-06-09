### 解题思路
遍历informTime数组，自底向上求通信时间。toup数组记录已经求得的从某个点到根节点所需要的时间，避免重复计算。例如toup[i]的值即i节点到headID节点所需要的时间。

### 代码

```cpp
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int max = 0;
        int cur;
        int toup[n] = {0};
        for(int i = 0; i < n; i++){
            if(informTime[i] == 0 || toup[i] != 0) continue;  //若i节点为根节点(没有下属)，或者已经被计算过了到headID的时间，直接跳过
            cur = getTime(i, headID, manager, informTime, toup);
            max = (cur > max) ? cur : max;
        }
        return max;
    }

    int getTime(int myID, int headID, vector<int>& manager, vector<int>& informTime, int* toup){
        if(myID == -1) return 0;  
        if(manager[myID] >= 0 && toup[manager[myID]] != 0){     //若此节点的上司已被计算过到根节点的时间，则直接相加即可
            toup[myID] = informTime[myID] + toup[manager[myID]];
        }else{                                                 //若没有被计算过，需要递归计算。
            toup[myID] = informTime[myID] + getTime(manager[myID], headID, manager, informTime, toup);
        }
        return toup[myID];
    }
};
```