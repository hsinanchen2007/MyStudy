### 解题思路
就用最简单的+-1来，n分奇数和偶数的情况

### 代码

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
    vector <int> re;
    if (n % 2 == 0){
        for (int i = 0; i < n/2; i++){
        re.push_back (-n /2 + i); 
        re.push_back (n/2 - i); 
    } }
    else{
        for (int i = 0; i < n; i++){
        re.push_back (-(n-1) /2 + i); 
    } }
    return re;
    }
};
```