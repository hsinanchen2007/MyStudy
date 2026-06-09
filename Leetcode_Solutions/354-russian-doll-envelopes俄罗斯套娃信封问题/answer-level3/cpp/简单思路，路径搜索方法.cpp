### 解题思路
首先所有的信封按照长度升序，那么我们**从后往前**判断和**记录**每个**信封最大的嵌套数目**，因为是按照升序排列且已经得到后面所有信封能够嵌套的信封数目，所以只需要查找后面比当前信封宽度大(且长度不相等)的所有信封中嵌套数目的最大值，然后+1赋值给当前信封嵌套数目即可。最后，查找所有信封嵌套数目中最大值即可。
这里使用c++给出代码，执行用时920ms，内存消耗13.7MB。

### 代码

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0)
            return 0;
        int res = 0;
        std::sort(envelopes.begin(), envelopes.end(), \
            [](const vector<int>& lv, const vector<int>& rv) {
                return (lv[0] < rv[0]);
            });// 升序排列
        vector<int> maxLen(envelopes.size());// 记录每个信封嵌套最大值
        for(int i = envelopes.size()-1; i >= 0; i--){
            maxLen[i] = 1;// 至少有自己
            int h = envelopes[i][0];
            int w = envelopes[i][1];
            int tmp = 0;
            for(int j = i+1; j < envelopes.size(); j++){
                if(envelopes[j][0] != h && envelopes[j][1] > w){
                    tmp = (tmp < maxLen[j]) ? (maxLen[j]) : (tmp);/* 找到最大的长度 */
                }
            }
            maxLen[i] += tmp;// 获得当前信封嵌套长度最大值
        }
        /* 查找所有嵌套中的最大值 */
        vector<int>::iterator max = max_element(maxLen.begin(), maxLen.end());
        res = *max;
        return res;
    }
};
```