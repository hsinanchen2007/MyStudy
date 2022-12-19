### 解题思路
1.使用hash_map记录相同距离的个数，因为方向不同也算一个回旋镖，因此每当有一个坐标到n个坐标都有相同的距离时就有2 * (n - 1)个回旋镖。
### 代码

```cpp
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
                int num = 0;
        int dis = 0;
        unordered_map<int,int> n;
        for(int i = 0;i < points.size();i++){
            n.clear();
            for(int j = 0;j < points.size();j++){
                if(i != j){
                    dis = pow(points[i][0] - points[j][0],2) + pow(points[i][1] - points[j][1],2);
                    n[dis]++;
                    if (n[dis] > 1)
                        num += 2 * (n[dis] - 1);
                }
            }
        }
        return num;
    }
};
```