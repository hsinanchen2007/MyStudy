### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int s = sqrt(area);
        if(s*s == area)
            return {s,s};
        while(s){
            if(area%s == 0)
                return {area/s, s};
            s--;
        }
        return {};
    }
};
```