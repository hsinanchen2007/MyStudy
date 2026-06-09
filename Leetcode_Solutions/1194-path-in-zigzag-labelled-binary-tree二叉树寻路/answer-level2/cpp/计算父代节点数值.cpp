### 解题思路
计算上一节点数值进行迭代循环

### 代码

```cpp
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int cl=label;
        vector<int>a;
        while(cl!=1)
        {
            int hh=int(log(cl)/log(2)+1);
            int ww=int((cl-pow(2,hh-1))/2)+1;
            a.push_back(cl);
            cl=pow(2,hh-2)+pow(2,hh-2)-ww;
        }
        a.push_back(1);
        reverse(a.begin(),a.end());
        return a;
    }
};
```