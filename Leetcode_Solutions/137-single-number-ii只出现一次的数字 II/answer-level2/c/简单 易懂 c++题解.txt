### 解题思路
其实就是某一位有3个1的时候要清零即可，我们使用两个数字来记录这一位上1的个数，分别记为a，b,b是低位，a是高位。
就是一个从00->01->10->00
下面要做的工作就是当遍历到新的i是如何变化a和b。
当新的数字i的某一位为1时且b的那一位也位1时要进位，即为int add=b&i;
b与i就是加法关系，使用异或就行。
下面是逻辑关系图：
![ib.jpg](https://pic.leetcode-cn.com/84d2c9b3b23e6df5fc6c073e2d5a54aa24b90e1fd12c22a22ad9ec6400bfaef0-ib.jpg)
然后a在加上进位add即可；

然后要判断是不是到有三个1的情况了，也就是ab如果是11就要把ab变成00，关系图在下面：
![ab.jpg](https://pic.leetcode-cn.com/8ec078f6a3ddcd3da53483c3c15d54d46b2be1d0e97a73d8274ddfc55f2e975a-ab.jpg)

有了关系图我们可以使用&和~和|实现这些逻辑，如果情况比较复杂可以画卡诺图。
代码如下 na是新的a，nb代表新的b。
```
            int na=a&(~b);
            int nb=(~a)&b;
            a=na;
            b=nb;
```






### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        int b=0;
       // cout<<a;
        for (int i:nums){
            int add=b&i;
            a^=add;
            b^=i;
            int na=a&(~b);
            int nb=(~a)&b;
            a=na;
            b=nb;
        }
        return b;

    }
};
```

其实还可以使用卡诺图进一步化简，直接画出a,b与i的关系然后使用极小项即可：
int na=((i&(~a)&b)|((~i)&a&(~b)));
int nb=((i&(~a)&(~b))|((~i)&(~a)&b));