### 解题思路
考虑边界条件：
1、如果最后一个数字为9，那么需要变为0，向前进1，若不为9则加1后直接返回。
2、遍历完检查第一个数字，若为0，则表明有1进位未在vector中，则需要在vector前端插入1。

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::reverse_iterator vIter;
        for(vIter=digits.rbegin();vIter!=digits.rend();vIter++){
            if(*vIter==9){
                *vIter=0;
            }else{
                *vIter = *vIter+1;
                return digits;
            }
        }
        if(digits[0]==0){
            digits.insert(digits.begin(),1);
            return digits;
        }
        return {};
    }
};
```