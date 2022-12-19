### 解题思路
数学方法，最后记得reverse

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        for(int i = 2;;i++){
            if(i%2){
                int avg = target / i;
                if(avg * i == target){
                    vector<int> v;
                    int head = avg - (i / 2);
                    if(head <= 0) break;
                    for(int j = head;j < head + i;j++) v.push_back(j);
                    ans.push_back(v);
                }
            }
            else{
                int avg = target / i;
                if(i / 2 + avg * i == target){
                    vector<int> v;
                    int head = avg - (i / 2) + 1;
                    if(head <= 0) break;
                    for(int j = head;j < head + i;j++) v.push_back(j);
                    ans.push_back(v);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```