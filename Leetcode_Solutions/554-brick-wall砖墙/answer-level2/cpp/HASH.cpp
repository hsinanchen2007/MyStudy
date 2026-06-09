## 问题描述
你的面前有一堵方形的、由多行砖块组成的砖墙。 这些砖块高度相同但是宽度不同。你现在要画一条**自顶向下**的、穿过**最少**砖块的垂线。

砖墙由行的列表表示。 每一行都是一个代表从左至右每块砖的宽度的整数列表。

如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。你需要找出怎样画才能使这条线穿过的砖块数量最少，并且返回穿过的砖块数量。

**你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。**

![](https://pic.leetcode-cn.com/26c7d4a44d6a81972261c7ba5a0e1a6e05580980dd0f24a57596811b058e2fe0.png)

[砖墙](https://leetcode-cn.com/problems/brick-wall/ "砖墙")

## 解决方法
### 哈希

- 哈希表记录能到达某高度的数量，然后遍历哈希表，砖的行数减去哈希表中各个值不断更新最小值即可

```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int>m;
        int size=wall.size();
        int res=size;
        for(int i=0;i<size;i++){
            int len=wall[i].size()-1;
            int temp=0;
            for(int j=0;j<len;j++){
                temp+=wall[i][j];
                m[temp]++;
            }
        }
        for(auto item:m){
            res=min(size-item.second,res);
        }
        return res;
    }
};
```

my site: [https://liyiping.cn/](https://liyiping.cn/)