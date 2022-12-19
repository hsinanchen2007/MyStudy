### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/137528006a4e03d69c08106df25b9c121287e4ab78844bb8a5937fad9179bb83-%E6%8D%95%E8%8E%B7.PNG)

初始化n个0，然后赋值一正一负即可，偶数的话刚刚好，奇数的话最后一位本来为0，不用赋值即可。

### 代码

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n,0);
        for(int i=0 ; i<n-1 ;){
            res[i] = -(i*2+1);
            res[i+1] = i*2+1;
            i+=2;
        }
        return res;
    }
};

```