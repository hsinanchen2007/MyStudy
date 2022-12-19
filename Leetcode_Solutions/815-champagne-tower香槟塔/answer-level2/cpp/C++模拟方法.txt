### 解题思路
不用开那么大的数组，只要记住这一层就能算下一层了。

### 代码

```cpp
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> vol{double(poured)};
        for(int i = 1; i <= query_row; ++i)
        {
            vector<double> temp(vol.size()+1, 0);
            if(vol[0] > 1)  temp[0] += (vol[0] - 1)/2;
            if(vol[vol.size()-1] > 1)   temp[temp.size()-1] += (vol[vol.size()-1] - 1)/2;
            for(int j = 1; j < temp.size()-1; ++j)
                temp[j] += max((vol[j-1]-1)/2 , 0.) + max((vol[j]-1)/2 , 0.);
            vol = temp;
        }
        return min(vol[query_glass],1.);
    }
};
```