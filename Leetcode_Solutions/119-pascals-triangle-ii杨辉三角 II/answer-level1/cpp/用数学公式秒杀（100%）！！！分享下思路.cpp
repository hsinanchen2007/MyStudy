### 解题思路
对于杨辉三角的题目我们并不陌生。事实上，我们中学也学过，概念就不再这里赘述了。很容易想到的一个思路就是，求出前K-1行，再用杨辉三角的定义求出第K行。其实这个方法不是特别高效，我们来看看用组合数学是怎么求的。

![image.png](https://pic.leetcode-cn.com/634b94a74759ad8bd15877b95b9cde61dc5cc3c861377b575f06d3835d4872c9-image.png)
由上图我们可以知道，这些数字，其实都可以用组合数表示出来。既然可以用数学公式表示出来，那我们写一个求组合数的函数然后一个个计算出来就行了。这当然是可行的，但是慢了。
我们推导可以发现，组合数的第K项和第K+1项是有关系的，我手写推导一下（字太丑~）。
![image.png](https://pic.leetcode-cn.com/2697327e55956d700b2451d0e52e1541d9c4f56fad8aa1a700542a864b8e4d50-image.png)
通过上面的推导我们就可以高效地通过第K-1项计算第K项了，献上代码：

### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex ++;//输入是从第0行开始的，偏移一位从第一行开始算。
        vector <int> row;
        long long c = 1;//c， n 取 k的意思。输入太大时，int会溢出。 
        int n = rowIndex - 1;

        for (int k = 1; k <= rowIndex; k ++){
            row.push_back(c);
            c = c * (n - k + 1) / k ;
        }
        return row;
    }
};
```