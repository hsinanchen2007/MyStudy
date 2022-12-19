### 解题思路
爬n阶台阶很难直接算出，但是由于一次只能爬1或2个台阶，所以可以转化成：
> 爬 n 阶台阶=爬 n-1 阶楼梯+爬 1 个台阶;
爬 n 阶台阶=爬 n-2 阶楼梯+爬 2 个台阶;

那么
> 爬 n 阶台阶的方法=爬 n-1 阶楼梯的方法+爬 n-2 阶楼梯的方法；

这里使用数组对爬n阶台阶的方法进行存储。
因为在整个爬台阶过程中，我们比较好确定的是爬 1 、2 阶的方法数量。
通过递推关系，一步一步求解爬 n 阶台阶的方法总数。


### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> result;
        result.push_back(1);
        result.push_back(2);
        if(n>2){
            for(int i=2;i<n;i++){
                result.push_back(result[i-1]+result[i-2]);
            }
        }
        return result[n-1];
    }
};
```