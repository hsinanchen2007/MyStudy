### 解题思路
因为面试的每个人都要选择一个城市，要么A市要么B市，所有通过第i个人的abs(costs[i][0]-costs[i][1])的值按降序排序，对于该值相同的则按比较的两个人的最小值按升序排序
然后遍历数组costs （用A,B控制选择）

### 代码

```cpp
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](const vector<int> & a,const vector<int> &b){
            if(abs(a[0]-a[1])>abs(b[0]-b[1])) return true;
            if(abs(a[0]-a[1])==abs(b[0]-b[1])){
                if(min(a[0],a[1])<min(b[0],b[1])) return true;
                else return false;
            }
            return false;
        });
        int A=0,B=0;//任何值初始化都要有
        int time=0;
        int len=costs.size();
        for(int i=0;i<len;i++){
            if(costs[i][0]<costs[i][1]&&A<len/2) {
                A++;
                time+=costs[i][0];
                continue;
            }
            if(costs[i][0]>=costs[i][1]&&B<len/2) {
                B++;
                time+=costs[i][1];
                continue;
            }
            if(A==len/2) {
                time+=costs[i][1];
                B++;
                continue;
            }
            if(B==len/2) {
                time+=costs[i][0];
                A++;
                continue;
            }
        }
        return time;
    }
};
```