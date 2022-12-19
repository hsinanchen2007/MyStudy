### 解题思路
此处撰写解题思路
问题还是防溢出
### 代码

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0,j = (int)sqrt(c);
        while(i <= j){
            if((c - i*i) == j*j)     return true;
            else if((c - i*i) > j*j){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};
```