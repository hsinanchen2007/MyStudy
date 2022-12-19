### 解题思路
先按气球位置的第一个值对所有气球排序，然后从第二个气球遍历整个vector。具体见下面for循环。

### 代码
```
bool cmp(const vector<int>& a, const vector<int>& b){
    return a[0]<b[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {  
        if(points.size() == 0){
            return 0;
        }
        sort(points.begin(), points.end(),cmp);
        int shoot_num = 1;
        int shoot_begin = points[0][0];
        int shoot_end = points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0] <= shoot_end){
                shoot_begin = points[i][0];
                if(shoot_end > points[i][1]){
                    shoot_end = points[i][1];
                }
            }else{
                shoot_num++;
                shoot_begin = points[i][0];
                shoot_end = points[i][1];
            }
        }
        return shoot_num;
    }
};
```