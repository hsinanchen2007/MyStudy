### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sq(area);
        while(area % w != 0) w--;
        return {area/w, w};
    }
private:
    int sq(int area){
        long x = area;
        while(x*x > area){
            x = (x+ area/x)/2;
        }
        return x;
    }
};
```