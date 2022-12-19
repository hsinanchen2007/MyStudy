### 解题思路
头文件`#include <unordered_map>`
通过无序哈希表来解决此题
首先，需要将每张骨牌的两个数字变换到容易比较的格式，有两种方法
    1，本题中所用，赋予每张牌面值，也就是将每张牌的两个数字转换成一个；
    2，将两个数字按照前大后小或者前小后打的方式重新整理。
最后计算结果的时候要注意计算的是对数，不是张数，另外如果三张牌相同的话，正确的结果应该是+3。
### 代码

```cpp
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans=0;
        unordered_map<int, int> map;
        for (auto c:dominoes){
            int temp;
            c[0]>c[1]? temp=c[0]*10+c[1]: temp=c[1]*10+c[0]; //赋予每张多米诺骨牌面值
            map[temp]++; //计算各种面值多米诺骨牌的张数
            ans=ans+map[temp]-1; //计算相同的骨牌对数，注意-1
        }

        return ans;
    }
};
```