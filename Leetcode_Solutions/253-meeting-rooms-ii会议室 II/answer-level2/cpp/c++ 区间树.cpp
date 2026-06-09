### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int> m;
        for(auto& e:intervals){
            m[e[0]]++;
            m[e[1]]--;
        }
        int res=0;
        int room=0;
        for(auto& e:m){
            res=max(res,room+=e.second);
        }
        return res;
    }
};
```