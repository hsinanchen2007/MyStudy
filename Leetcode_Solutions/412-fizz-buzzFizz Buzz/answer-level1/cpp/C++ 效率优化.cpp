### 解题思路
思路很简单，但是还是要尽力的优化程序的执行效率和占用资源。
1. 资源问题：变长数组建议使用 vector，所有基本上资源这里没办法优化太多
2. 效率问题：在每个判断分支加入一句 "continue;" 之后，每次循环判断最少只会执行一次而最多是三次
3. 相比不加 "continue;" 效率提升非常大；另外，先判断能否整除 15，也可以提升一些效率。

执行结果：
![image.png](https://pic.leetcode-cn.com/549202f37e2b19d04f79ddb6a097a3d3e796dc15824d31dfca3bd2e4f9aff067-image.png)

### 代码

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<std::string> vec;
        for (int i=1; i<=n; i++){
            if (i%15==0){
                vec.insert(vec.end(), "FizzBuzz");
                continue;
            }
            else if(i%3==0 && i%5!=0){
                vec.insert(vec.end(), "Fizz");
                continue;
            }
            else if(i%5==0 && i%3!=0){
                vec.insert(vec.end(), "Buzz");
                continue;
            }
            else
                vec.insert(vec.end(), std::to_string(i));
        }
        return vec;
    }
};
```