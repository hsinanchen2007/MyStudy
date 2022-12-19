### 解题思路
队列法 和 127类似

### 代码

```cpp
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<int> vis(bank.size(), 0);
        int res = 0;
        queue<string>  now;
        now.push(start);
        while(now.size() > 0){
            res ++;
            for(int k = 0;k<now.size();k++){
                string tmp = now.front();
                now.pop();
                for(int i=0;i<bank.size();i++){
                    if(vis[i] == 0){
                        int dif = 0;
                        for(int j = 0;j<bank[i].size();j++){
                            if(bank[i][j] != tmp[j]) dif++;
                        }
                        if(dif == 1){
                            if(bank[i] == end) return res;
                            vis[i] = 1;
                            now.push(bank[i]);
                        }
                    }
                }
            }
            
        }
        return -1;
    }
};
```