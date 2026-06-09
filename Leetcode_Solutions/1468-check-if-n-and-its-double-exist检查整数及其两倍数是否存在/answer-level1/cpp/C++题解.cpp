
### [1346. 检查整数及其两倍数是否存在](https://leetcode-cn.com/problems/check-if-n-and-its-double-exist/)

#### 题解
  + 遍历记录各个数是否出现
  + 遍历查询其倍数是否出现
  + 标记0的个数，特判
  + 由于有负数，并且有double的可能，所以整体前移$2 * 10^3$
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int flag = 0;
        bool exit[10010];
        memset(exit, false, sizeof(exit));
        for(int i = 0; i < arr.size(); i++)
            {
                exit[arr[i] + 2000] = true;
                if(arr[i] == 0) flag ++;
            }
        for(int i = 0; i < arr.size(); i++)
            if(exit[arr[i] * 2 + 2000] && arr[i] != 0) return true;
        if(flag >= 2) return true;
        return false;
    }
};
```