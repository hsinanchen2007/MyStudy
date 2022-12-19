### 解题思路
- 满意的数量 `=` 老板正常不生气的顾客满意数量(`grumpy[i]` 原本为`0`) `+` 老板使用秘密技巧获得顾客满意的数量(从 `grumpy[i]` 从`1 -> 0`)，统计量为`base`
- 老板正常不生气的获得顾客的满意数量使用for循环计算`grumpy[i`]为`0`时的`customer[i]`值
- 老板使用秘密技巧获得顾客满意的数量采用**滑动窗口**计算，统计量为`max_windows_profit`
    a) 窗口扩大，将`grumpy[i]`为`1`的`customer[i]`加进来
    b) 若窗口大于X时，收缩窗口，减去`grumpy[i-X]`为`1`的`customer[i-X]`
    c) 若当前窗口的值大于`max_windows_profit`,则更新`max_windows_profit`
- 返回`base + max_windows_profit`

### 代码

```cpp
class Solution {
public:
    

    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int base = 0;
        int max_windows_profit = 0;
        int current_windows_profit = 0;
        for(int i=0;i<customers.size();i++){
            base += (grumpy[i] == 0 ? customers[i] : 0);
            current_windows_profit += grumpy[i] * customers[i];
            if(i>=X){
                current_windows_profit -= grumpy[i-X] * customers[i-X];
            }
            max_windows_profit = max(max_windows_profit, current_windows_profit);
        }
        return base + max_windows_profit;
    }
};
```