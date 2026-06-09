### 解题思路
搬运工，和***的测试用例不太一样，要小修改一下

### 代码

```cpp
class Solution {
private:
    unordered_map<int,double> map;
    double _mypow(double x, long n){
        if(n > 0){
            if(map.find(n) != map.end())
                return map[n];
            if(n == 1)
                return x;
            if(n % 2 == 0){
                return map[n] = _mypow(x, n / 2) * _mypow(x, n / 2);
            }else{
                return map[n] = _mypow(x, n / 2) * _mypow(x, n / 2 + 1);
            }

        }else if(n < 0){
            return 1 / _mypow(x, -n);
        }else{
            return 1;
        }
    }
public:
    double myPow(double x, int n) {
       return _mypow(x, n);
    }
};
```