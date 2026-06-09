### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         int n=points.size();
         int count=n;
        sort(points.begin(),points.end());
          for(int i=1;i<n;i++){
             if(points[i][0]>points[i-1][1])
                 continue;
             else {
                   count--;
                 if(points[i][1]>points[i-1][1]){
                    points[i][1]=points[i-1][1];  
                 }            
             }
        }
        return count;
    }
};
```