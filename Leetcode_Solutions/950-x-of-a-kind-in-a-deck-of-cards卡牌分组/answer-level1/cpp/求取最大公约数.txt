### 解题思路
       //求取最大公约数，使用辗转相除法
        //1. 统计每个数字出现的次数，构建新的数组；
        //2. 对该数组使用辗转相除法，计算最大公约数，最大公约数>2则返回true

### 代码

```cpp
class Solution {
public:

    bool hasGroupsSizeX(vector<int>& deck) {
        //求取最大公约数，使用辗转相除法
        //1. 统计每个数字出现的次数，构建新的数组；
        //2. 对该数组使用辗转相除法，计算最大公约数，最大公约数>2则返回true
        unordered_map<int,int> count;
        for(int num:deck){
            count[num]++;
        }
        int a = 0;//公约数
        for(auto it = count.begin(); it != count.end(); ++it){
            if(it->second > 0) {
                a = gcd(a, it->second);
                if(1==a) return false;
            }
        }
        return a>=2;
    }
    int gcd (int a, int b) {
        return b == 0? a: gcd(b, a % b);
    }
};
```