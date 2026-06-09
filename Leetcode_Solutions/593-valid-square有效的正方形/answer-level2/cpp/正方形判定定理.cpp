### 解题思路
已知四点，共有六种连线，可分三种情况，判断条件则依据正方形判定定理：四边相等，对角线相等以及勾股定理。另外，注意排除四点存在共点情况。
![微信图片_20191205182704.png](https://pic.leetcode-cn.com/fed55096f7256cfadd15ceda1e564eadb7b31140c95cf1f0af19d1021ecea88b-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191205182704.png)

### 代码

```cpp
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int p12 = pow((p1[0]-p2[0]),2) + pow((p1[1]-p2[1]),2);
        int p13 = pow((p1[0]-p3[0]),2) + pow((p1[1]-p3[1]),2);
        int p14 = pow((p1[0]-p4[0]),2) + pow((p1[1]-p4[1]),2);
        int p24 = pow((p2[0]-p4[0]),2) + pow((p2[1]-p4[1]),2);
        int p34 = pow((p3[0]-p4[0]),2) + pow((p3[1]-p4[1]),2);
        int p23 = pow((p2[0]-p3[0]),2) + pow((p2[1]-p3[1]),2);
        if(p12 == 0 || p13 == 0 || p14 == 0 || p23 == 0 || p24 == 0 || p34 == 0)
            return false;
        if(p12==p13 && p24==p34 && 2*p13==p23 && p23==p14 || p12==p14 && p23==p34 && 2*p14==p24 && p24==p13 || p13==p14 && p23==p24 && 2*p14==p34 && p34==p12)
            return true;
        return false;        
        
    }
};
```