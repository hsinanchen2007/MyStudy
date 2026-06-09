### 解题思路
由于不能用一系列的判断，所以我们递归这种想法就暂且放弃。想到STL中有函数恰好能a满足条件，
iota函数的参数是从一个数组的开头到结尾（也可以是你自己想要的其他位置）从（第三个参数是从哪个数开始）1开始递增放入数组中；
accumulate函数第三个参数是从哪个位置开始加；
最后得到答案！

### 代码

```cpp
class Solution {
public:
    int sumNums(int n) {
        //const int m=n;
      int *val=new int[n];
        iota(val,val+n,1);
       int a= accumulate(val,val+n,0);
       return a;
    }
};
```