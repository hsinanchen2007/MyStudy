### 解题思路
使用数据记录字母出现的次数，应该不算正统解法！

### 代码

```cpp
class Solution {
public:
    //可以利用replace求解
    bool isUnique(string astr) {
        int size = astr.size();
        int a[26] = {0};
        for(int i=0;i<size;i++){
            int temp = astr[i] - 'a';
            a[temp]++;
            if(a[temp] > 1) return false;
        }
        return true;
    }
};
```