### 解题思路
1.先对其进行排序
2.依次遍历，更新所有的射击区间

### 代码

```cpp
bool cmp(const vector<int> &a ,const vector<int> &b){
        return a.front() <= b.front();
}
class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0){
            return 0;
        }
        std::sort(points.begin(),points.end(),cmp);
        int shoot_num = 1;
        int shoot_begin = points[0].front();
        int shoot_end = points[0].back();
        for(int i = 1  ; i < points.size() ; i++){
            if(points[i].front() <= shoot_end){
                shoot_begin = points[i].front();
                if(points[i].back() <shoot_end){
                    shoot_end = points[i].back();
                }
            }else{
                shoot_num++;
                shoot_begin = points[i].front();
                shoot_end = points[i].back();
            }
        }
        return  shoot_num;
    }
};
```