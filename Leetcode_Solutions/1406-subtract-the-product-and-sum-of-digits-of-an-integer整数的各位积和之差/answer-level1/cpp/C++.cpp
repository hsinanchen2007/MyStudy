### 解题思路
通过 n % 10获取最低位的数字(使用vector<int> a保存))，n = n /10, 接着通过 n % 10再获取第二低位的数字，直到 n == 0;
### 代码

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
       vector<int> a;
       while(n){
           a.push_back(n%10);
           n /= 10;
       }
       int sum = 0;
       int product = 1;
       for( auto e:a){
           sum += e;
           product *= e;
       }
       return product - sum;
    }
};
```