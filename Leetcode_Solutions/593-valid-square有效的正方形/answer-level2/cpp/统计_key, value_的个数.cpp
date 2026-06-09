### 解题思路
4个点，两两相连，一共是6条边，如果是正方形，则6条边的分为两类：
- 四个相等的边
- 两个相等的对角线

用<key, value>的结构，也就是map,存储<边，个数>的关系，如果map的size是两个，则满足以上条件。
另外注意边长等于0的case。

### 代码

```cpp
class Solution {
public:
    int distance(vector<int> p1, vector<int> p2){
        return (p1[1] - p2[1])*(p1[1] - p2[1]) + (p1[0] - p2[0])*(p1[0] - p2[0]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> hash;
        int x1 = distance(p1, p2); hash[x1]++;
        int x2 = distance(p1, p3); hash[x2]++;
        int x3 = distance(p1, p4); hash[x3]++;
        int x4 = distance(p2, p3); hash[x4]++;
        int x5 = distance(p2, p4); hash[x5]++;
        int x6 = distance(p3, p4); hash[x6]++;

        if (x1==0 || x2==0 || x3==0 || x4==0 || x5==0 || x6==0 || hash.size()!=2){
            return false;
        }
        return true;
    }
};
```