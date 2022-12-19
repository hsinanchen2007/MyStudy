### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/10d231a835f32120f51514c96741346ac8651b43dc43e045feea77ae086adfc3-%E6%8D%95%E8%8E%B7.PNG)
如果i<3改为i<guess.size()的话，执行时间会变为4ms，所以这种固定的还是直接写死，会好一点。

### 代码

```cpp
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int sum = 0;
        for(int i=0 ; i<3 ; i++)
            if(guess[i] == answer[i])   
                sum++;
        return sum;
    }
};
```