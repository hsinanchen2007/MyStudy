### 解题思路
1. customers[i]与grumpy[i]对应数组元素相乘相加，得到满意客户人数，
2. customers[i]与(1-grumpy[i])相乘得到生气客户对应位置，
3. 滑动求和得到X范围内生气客户最大值，
4. 将直接满意客户与使用秘密技巧满意客户人数相加。
### 代码

```cpp
#include <numeric>
#include<vector>
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        vector<int> angry_res(customers.size(),0);
        vector<int> laugh_res(customers.size(),0);
        int max=0,tmp_max=0,laugh_sum=0;
        for(int i=0;i<customers.size();i++){
            angry_res[i] = customers[i]*grumpy[i];
            laugh_res[i] = customers[i]*(1-grumpy[i]);
            laugh_sum += laugh_res[i];
        }
        for(int i=0;i<X;i++){
            max+=angry_res[i];
        }
        tmp_max = max;
        for(int j=X;j<customers.size();j++){
            tmp_max = tmp_max + angry_res[j] - angry_res[j-X];
            if(tmp_max>max){
                max = tmp_max;
            }
        }
        laugh_sum+=max;
        return laugh_sum;
        
    }
};
```