### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isUgly(int num) {
        vector<int> b = {2,3,5};
        for(int i=0;i<b.size();i++){
            while(num > 0 && num % b[i] == 0)
                num /= b[i];
        }
        return num == 1;
    }
};
```