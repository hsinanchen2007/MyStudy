### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string world;
        int res = 0;
        while(ss>>world)
            res++;
        return res;
    }
};
```