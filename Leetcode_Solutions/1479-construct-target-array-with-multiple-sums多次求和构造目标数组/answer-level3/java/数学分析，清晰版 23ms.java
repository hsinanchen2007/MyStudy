### 解题思路
递归解题：如果当前数组是可以构造的，那么上一个数组也是可以构造的。
结束条件：全部为1，或者检验出不可构造
由构造的方法，可知：__当前数组的最大值即为上一次的改变的数__
如何构造出上一个数组：
1.假设当前的数组从小到大__排序__后是这样的：
$$x_1\le x_2 \le ... \le x_{n-1} \le x_n$$
2.再假设在上一回合中，对应的数是这样的：
$$x_1\le x_2 \le ... \le x_{n-1},x^{0}_n(并不知道原来的位置)$$
3.此时仅有$x^{0}_n$是未知的，其他都是已知的。设：
$$S_{n-1}=x_1+x_2+...+x_{n-1}$$
根据题设构造规则，
$$x_n=S_{n-1}+x^{0}_n$$
从而
$$x^{0}_n=x_n-S_{n-1}$$
4.由于所有数都是从1开始的，不会减少，只会增加。所以：
$$x^{0}_n=x_n-S_{n-1}\ge 1$$
一旦不满足，返回`false`。
5.如果4没有出错，则令数组`target`为上一次的样子，即：
$$ target: x_1,x_2,...,x_{n-1},x^{0}_n$$
递归检验。

由于有些样例无法在`int`范围内求出$S_{n-1}$，所以用最大值从后往前减去来检验。
### 代码

```java
class Solution {
    public boolean isPossible(int[] target) {
        //Arrays.sort(target);
        int n =target.length;
        if(n==1&&target[0]==1)return true;
        if(n==1)return false;
        return isPossible(target,n); 
    }
    public boolean isPossible(int[] target,int n){
        Arrays.sort(target);
        int max=target[n-1];
        if(max==1 && target[0]==1)return true;//1,1,1,...,1
        for(int i=n-2;i>=0;i--){
            max-=target[i];
            if(max<1)return false;//检验式子4
        }
        target[n-1]=max;
        return isPossible(target,n);//式子5，递归
    }
}
```