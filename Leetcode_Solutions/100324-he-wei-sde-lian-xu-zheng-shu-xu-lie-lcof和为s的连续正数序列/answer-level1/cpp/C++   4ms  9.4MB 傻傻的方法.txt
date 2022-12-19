粗略看了一下前面几个题解，感觉好像没有人用的是这个思路，看提交结果还不错，于是写个题解（总要有第一次的嘛

![image.png](https://pic.leetcode-cn.com/b287581b5ad5ebc2bd1581d2221a88672ab4453e13d42ab7039888c7212da7d6-image.png)




首先思考的第一步，就是考虑到如果一个数可以由`i`位连续的数相加得出，那么这个连续的`i`位数一定是唯一的（但`i`不一定唯一），于是，我们就考虑一个一个尝试`i`的可能的值，按题意这个连续正整数序列最少含有两个数，故我们从`i=2`开始尝试。
```
for(int i = 2;/*   */;i++) { }
```


第二步思考，如果一个数`target`可以由位数`i`不同的连续正整数序列相加得出，那么寻找有`i`位的连续正整数序列是否有某种方法？

首先，我们大致确定这个数组的位置，比如`target`可以由两位连续正整数序列相加得出，那么这个数组大约在`target/2`的地方，比如`target`可以由三位连续正整数序列相加得出，那么这个数组大约在`target/3`的地方。

然后我们分析每个不同的`i`，当`i=2`的时候，这个两个连续正整数应该分别在`target/2`的两边，且与`target/2`的差相等，，所以`target/2`必须要为`xxx.5`，这样这两个数相加就是`target/2-0.5 + target/2-0.5 == target`。同理当`i=4`的时候，这个两个连续正整数应该分别在`target/4`的两边，所以`target/4`必须要为`xxx.5`。

当`i=3`的时候，中间的第2个数一定等于`target/3`，所以`target/3`一定是整数，然后另外两个一个-1，一个+1，同理`i=5`时，中间的数一定等于`target/3`，然后一边是-2，-1，一边是+1，+2.

然后我们就发现了：
当`i`是偶数，且`target/i`为`xxx.5`的时候，应该存在一个`i`位的连续正整数序列相加为`target`。
当`i`是奇数，且`target/i`为整数的时候，应该存在一个`i`位的连续正整数序列相加为`target`。

```
for(int i = 2;/*   */;i++) {
    if(i % 2 == 0) {
        if(target % i == i / 2) { }
    }
    else {
        if(target % i == 0) { }
    }
 }
```


接下来就把这些东西都判断保存起来，填充下代码。
值得注意的是退出最外面for循环的条件反射。

```
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        double num;      //用于保存target/i
        vector<vector<int>> res;       //返回值
        for(int i = 2;/*   */;i++) {   //中间是空的，在下面的if-break判断。
            vector<int> mid;      //中间值，即用来暂时保存要放进res的每一个元素。
            if(i % 2 == 0) {       //如果i为偶数
                if(target % i == i / 2) {   //如果target/i为xxx.5的时候（这么写是为了不引入浮点数
                    num = target / i;       //找到大概位置，也就是xxx.5中的xxx
                    if(num < i / 2) {break;}    //如果这个if里是1的话，那么这个连续的数组里会含有0或
                                                //负数，不符合题意，且之后的i都会不符合题意，因为i变
                                                //大，num就变小，而i/2还是变大，于是这个判断恒是1.
                    for(int j = i / -2 + 1; j <= i / 2; j++) {   //把以num为中心向两边扩的连续数字
                        mid.push_back(num + j);                  //放进mid里，之后在把mid放进res
                    }
                    res.push_back(mid);
                }
            } else {       //如果i为奇数
                if(target % i == 0) {
                    num = target / i;
                    if(num <= ( i - 1 ) / 2) {break;}
                    for(int j = - ( i - 1 ) / 2; j <= ( i - 1 ) / 2; j++) {
                        mid.push_back(num + j);
                    }
                    res.push_back(mid);
                }
            }
        }
        sort(res.begin(),res.end());     //排序，因为我们是按`i`排序，而题目要求按第一个元素的大小排序
        return res;
    }
};
```

