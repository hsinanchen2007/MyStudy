### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void swap(int &x, int &y){
        int tmp = x;
        x = y;
        y = tmp;
    }
    bool canMeasureWater(int x, int y, int z) {
        if (z>x+y) 
            return false;
        if (x > y) 
            swap(x, y);

        while(x>0 && x <= y && z>0){
            /*倒掉y升*/
            if (z >= y)
                z = z - y;
            /*倒掉x升*/
            if (z >= x)
                z = z - x;
            /*还能拼出更小的x，y升*/
            y = y - x;
            if (x > y) 
                swap(x, y);
        }
        return z == 0;
    }
};
```