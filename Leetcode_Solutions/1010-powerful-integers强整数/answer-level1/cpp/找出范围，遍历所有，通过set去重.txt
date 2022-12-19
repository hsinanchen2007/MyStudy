### 解题思路
找出x^n和y^n的所有小于bound的值,用两个vector<int>保存，然后通过循环遍历组合，如果组合值小于等于bound，添加进去，最后通过set去重

### 代码

```cpp
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> result;
        if(bound < 2) return result;

        vector<int> xv, yv;
        xv.push_back(1);
        yv.push_back(1);
        int a = x, b = y;
        while(a != 1 && a < bound){
            xv.push_back(a);
            a *= x;
        }
        while(b != 1 && b < bound){
            yv.push_back(b);
            b *= y;
        }
        
        for(int& i : xv){
            for(int& j : yv){
                if(i + j <= bound){
                    result.push_back(i + j);
                }else{
                    break;
                }
            }
        }
        
        set<int> s(result.begin(), result.end());
        result.assign(s.begin(), s.end());

        return result;
    }
};
```