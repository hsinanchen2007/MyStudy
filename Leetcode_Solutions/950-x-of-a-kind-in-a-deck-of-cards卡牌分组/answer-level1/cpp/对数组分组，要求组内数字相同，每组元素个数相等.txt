### 解题思路
解法空间时间占用都很高，容易出错的点是map_vec[deck[i]]写成map_vec[i]
gcd算法应该是需要自己写的，优化版gcd是分成了偶数和奇数两大类；
注意~按位取反符号，是先变补码（正数补码等于自身（反码一样），负数补码等于符号位不变，其余位取反（此时即为负数的反码）后再+1）
再取反（符号位也要变）（因为计算机存的是二进制补码）所以-1取反为0，-3取反为-2，3取反还是3

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> map_vec(10000,0);
        for(int i =0;i<deck.size();i++){
            map_vec[deck[i]]++;
        }
        int g = -1;
        for(auto iter = map_vec.begin();iter!=map_vec.end();iter++){
            if(*iter != 0){
                if(~g){
                    g = gcd(g,*iter);
                }
                else
                    g = *iter;
            }
        }
                
    return g>1? true:false;
    }
};
```