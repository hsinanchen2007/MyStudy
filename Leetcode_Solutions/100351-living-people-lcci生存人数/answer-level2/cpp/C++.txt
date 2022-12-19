### 解题思路
排序，按时间顺序记录

### 代码

```cpp
class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        sort(birth.begin(),birth.end());
        sort(death.begin(),death.end());
        int cnt=0,Max=0,ans;
        while(!birth.empty()||!death.empty()){
            int bt=birth.empty()?INT_MAX:birth.front(),dt=death.empty()?INT_MAX:death.front();
            if(bt<=dt){
                cnt++;
                if(cnt>Max){
                    Max=cnt;
                    ans=bt;
                }
                birth.erase(birth.begin());
            }
            else if(bt>dt){
                death.erase(death.begin());
                cnt--;
            }
        }
        return ans;
    }
};
```