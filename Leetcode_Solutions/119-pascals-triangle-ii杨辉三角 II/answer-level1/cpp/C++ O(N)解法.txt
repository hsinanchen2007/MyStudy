### 解题思路
杨辉三角中第k行第i列元素值为C(k,i)，行列标从0开始。
利用组合数C(k,i)与C(K,i+1)之间的关系，一次遍历即可。
如：
C(k,1) = (k) / (1);
C(k,2) = (k*(k-1)) / (1 * 2);
C(k,3) = (k*(k-1)*(k-2)) / (1 * 2 * 3);

### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);
        long a = rowIndex, b = 1;
        for(int i = 1; i < rowIndex; ++i){
            ans[i] = (int)ans[i - 1] * (a--) / (b++);
        }
        return ans;
    }
};
```