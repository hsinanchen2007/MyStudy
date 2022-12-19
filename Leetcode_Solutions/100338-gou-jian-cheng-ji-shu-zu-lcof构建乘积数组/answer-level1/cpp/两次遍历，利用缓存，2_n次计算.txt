### 解题思路
1、从左向右，计算累乘结果放到结果数组里；
2、从右向左，使用一个临时变量记录后遍历过的数的乘积，逐步替换结果数组里面的元素。

### 算法

1、lefts[0] = A[0]; 1->n: lefts[i] = A[0]*A[1]*...*A[i];
2、rightResult = 1; n->1: lefts[i] = lefts[i-1]*rightResult, rightResult *= A[i];
3、lefts[0] = rightResult;

### 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> lefts;
        if(a.empty()) return lefts;
        lefts.push_back(a.front());
        for(int i = 1; i < a.size(); i++) {
            lefts.push_back(lefts.back()*a[i]);
            // cout<<lefts.back()<<endl;
        } 
        
        int r = 1;
        for(int i = a.size()-1; i > 0; i--) {
            lefts[i] = lefts[i-1] * r;
            r *= a[i];
        }
        lefts[0] = r;
        return lefts;
    }
};
```