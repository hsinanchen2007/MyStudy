### 解题思路
该题解决思路较为简单，只需将n分别与10取余数计算即可。由于刚开始学习C++，因此该题使用了array模板类进行计算，解决思路如下:
* 计算n的位数，并将n每位的数字放在数组中
* 循环遍历数组，计算乘积，求和
* 返回乘积值-求和值

Note: 本题解法耗费了较多内存，纯属为了练习array模板类才写的代码，并不推荐

本题的时间复杂度为O(N),空间复杂度为O(N)。

### 代码

```cpp
class Solution {
public:
    int subtractProductAndSum(int n) {
        std::array<int,100> arr {0};
        //计算n的位数
        int len = 1;
        while(n%10 != n)
        {
            arr[len-1] = n%10;
            n = n/10;
            len++;
        }
        arr[len-1] = n;

        //求乘积，求和
        int pos = 1;
        int sum = 0;
        for(int i=0; i<len;i++)
        {
            pos *= arr[i];
            sum +=arr[i];
        }
        //计算结果
        return(pos-sum);
    }
};
```