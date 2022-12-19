## 暴力法
### 解题思路
直接模拟分发过程.
### 代码
```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int i = 0;
        while(candies)
        {
            int temp = (i+1 < candies)? i+1: candies;
            result[i % num_people] += temp;
            candies -= temp;
            i++;
        }
        return result;
    }
};
```
## 附录: 数学计算法的思路
假设完全分配的轮数为$k$, 已分配的糖果数为$(1+2+\cdots +n)k+(0+1+\cdots+(k-1))n^2=nk(nk+1)/2$, 设总的糖果数为$p$,则有
$$
\frac{nk(nk+1)}{2}\le p<\frac{n(k+1)[n(k+1)+1]}{2}
$$
于是得到:
$$
k=ceil(\frac{-1+\sqrt{8p+1}}{2n})=floor(\frac{-2+\sqrt{8p+1}}{2n})+1\tag{1}
$$
这样, 第$i$个(从1开始)小朋友在第$k$轮结束时分得的糖果数为$ik+(0+1+\cdots+(k-1))n=k[(k-1)n+2i]/2$, 最后一轮分配前, 剩余糖果数为
$$
q=p-nk(nk+1)/2 \tag{2}
$$
最后, 计算最后一轮中, 每个小朋友获得的糖果数, 设$j$是最后一轮(即第$k+1$轮)中第一个没有获得足够糖果的小朋友, 那么有:
$$
1+\cdots+(j-1)+(j-1)kn\le q<1+\cdots+j+jkn
$$
于是
$$
j=floor(\frac{-2kn+\sqrt{(2kn-1)^2+8(kn+q)}}{2})+1 \tag{3}
$$
于是, 第$j$个小朋友在最后一轮得到的糖果数为
$$
r=q-(j-1)(2kn+j)/2 \tag{4}
$$
综上, 算法流程如下:
- 按(1)式计算$k$, 按(2)式计算$q$, 按(3)式计算$j$, 按(4)式计算$r$.
- 第$i$个小朋友(i从1开始)得到的糖果数量为
    - $(k+1)(kn+2i)/2,\quad i<j$
    - $k[(k-1)n+2i]/2+r,\quad i=j$
    - $k[(k-1)n+2i]/2,\quad i>j$

但是, 上述公式有许多数值计算问题待解决, 并且式子可能有错误, 打卡要紧, 暂时不深究了. ^_^ :(