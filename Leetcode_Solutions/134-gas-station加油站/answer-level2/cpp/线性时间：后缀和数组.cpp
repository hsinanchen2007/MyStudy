做题最重要的一步是什么：建立数学模型。

方法一：枚举法，两次循环，分别检查每个下标能否绕一圈回来。

方法二：建立数学模型，构建后缀和数组（其中后缀和数组来源自 gas - cost)，观察后缀和的第一个元素，若为负，则不能回来；否则返回该数组中最大的元素的下标。

为什么建立后缀和数组？
后缀和数组中每个元素元素指的是从当前位置出发，到达最后位置后剩余的油量。对于第一个元素而言，若元素值为负，代表转一圈后油量为负，则说明一定不能遍历；若元素为正/零，则说明从某一点开始可以转一圈。

从那一点开始走？贪心思想，从后缀和数组中最大的值开始走。

代码：
```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //寻找后缀和
        vector<int> sub( gas.size(), 0);
        for( int i = gas.size() - 1; i > -1; i--)
            if( i == gas.size() - 1)
                sub[i] = gas[i] - cost[i];
            else
                sub[i] = gas[i] - cost[i] + sub[i+1];
        if( sub[0] < 0)
            return -1;
        //寻找最大的元素的下标
        int maxSubSum = sub[0], pos = 0;
        for( int i = 0; i < gas.size(); i++)
            if( maxSubSum < sub[i])
                maxSubSum = sub[i], pos = i;
        return pos;
    }
};
```
