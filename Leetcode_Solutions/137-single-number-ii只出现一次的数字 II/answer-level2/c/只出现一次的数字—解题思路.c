## 解题思路
在这里整理一下这个题目评论区中的解题思路，我将尽可能通过数学推导的方式提供一个通用的解题思路。
为了方便讨论，假设现在一共有$n$个数字，并且每个数字由$s$个`bit`组成，如下图所示：

$$
x_1:b_s^{(1)}b_{s-1}^{(1)}\cdots b_i^{(1)}\cdots b_2^{(1)}b_1^{(1)}\\
x_2:b_s^{(2)}b_{s-1}^{(2)}\cdots b_i^{(2)}\cdots b_2^{(2)}b_1^{(2)}\\
\vdots\\
x_n:b_s^{(n)}b_{s-1}^{(n)}\cdots b_i^{(n)}\cdots b_2^{(n)}b_1^{(n)}
$$

假设每个数字要么出现$m>1$次，或者只出现一次（只出现一次的数字就是我们需要找到的数字，这里将其称为$target$）。接着考虑按照`bit`位置进行相加，可以得到以下结论：
$$
\sum_{k=1}^nb_i^{(k)}=tm\quad\text{or}\quad tm+1\quad(i=1,2,\cdots,s)
$$
其中$t$表示在第$i$个`bit`位置处是1的整数的个数（不包括数组中只出现一次的那个数字）。如果上述式子的求和结果是$tm$，说明$target$在第$i$个`bit`位置处的值是0。反之，如果求和结果是$tm+1$，说明$target$在第$i$个`bit`位置处的值是1。
有了以上结论之后，为了求得$target$的确切值，我们只需要确定$target$每个`bit`的值是0还是1即可，而这点可以根据模$m$运算得到。于是我们的解题思路就是计算：
$$
b_i = \sum_{k=1}^nb_i^{(k)}\mod m\quad(i=1,2,\cdots,s)
$$
于是$target=(b_sb_{s-1}\cdots b_2b_1)_2$。
有了上面一般形式的讨论之后，我们讨论两种具体的情况：
### 情况1: $m=2$
在这种情况下，需要的就是模2运算，因为模2运算的结果只能是0或1，所以只需要1`bit`的空间作为缓存空间即可。并且模2运算就等同于xor，于是我们就可以直接通过xor运算对该题目进行求解：

```c
int singleNumber(int *nums, int numsSize){
    int result=0;
    //模2运算
    for(int i=0; i<numsSize; i++)
    {
        result = result ^ nums[i];
    }
    return result;
}
```
语句`result ^ nums[i]`可以认为是对`nums[i]`的每个`bit`同时进行模2加法，因此最终就可以求得仅出现一次的数字。

### 情况2: $m=3$
在这种情况下，需要模3运算，而模3运算的结果有0，1，2三个结果，因此我们至少需要2个`bit`的空间作为缓存空间。假设$h$表示高位`bit`，$l$表示低位`bit`，那么模3加法的真值表为
|$x$|$h_t$|$l_t$|$h_{t+1}$|$l_{t+1}$|
|---|---|---|---|---|
|0|0|0|0|0|
|0|0|1|0|1|
|0|1|0|1|0|
|1|0|0|0|1|
|1|0|1|1|0|
|1|1|0|0|0|

根据真值表，可以得到析取范式
$$
h_{t+1} = \bar{x}h_t\bar{l_t}+x\bar{h_t}l_t\\
l_{t+1} = \bar{x}\bar{h_t}l_t+x\bar{h_t}\bar{l_t}=\bar{h_t}(x\oplus l_t)
$$
上述式子中，乘法表示and操作，加法表示or操作，$\oplus$表示xor。
于是代码如下：
```c
int singleNumber(int* nums, int numsSize){
    int h=0,l=0,tmp;
    //模3运算
    for(int i=0; i<numsSize; i++)
    {
        tmp = l;
        l = (~h) & (nums[i] ^ l);
        h = (~nums[i])&h&(~tmp) | nums[i]&(~h)&tmp;
    }
    return l;
}
```
为了使代码更加简洁一点，如果忽略真值表的第三列，并且考虑$l_{t+1}$，则可以将$h_{t+1}$表示为
$$
h_{t+1}=\bar{l_{t+1}}(x\oplus h_{t})
$$
于是代码可以更改为：
```c
int singleNumber(int* nums, int numsSize){
    int h=0,l=0;
    //模3运算
    for(int i=0; i<numsSize; i++)
    {
        l = (~h) & (nums[i] ^ l);
        h = (~l) & (nums[i] ^ h);
    }
    return l;
}
```
这种方法相当于是针对每一个`bit`都创建了一个模3的计数器，也可以采用另一种思路，只创建一个计数器，然后逐个比特位置进行判断：
```c
#define M 3

int singleNumber(int* nums, int numsSize){
    int mask, counter, result=0;
    for(int i=0; i<32; i++)
    {
        counter = 0;
        mask = 1 << i;
        for(int j=0; j<numsSize; j++)
        {
            if(mask&nums[j])
                counter++;
        }
        if(counter%M!=0)
            result |= mask;
    }
    return result;
}
```
