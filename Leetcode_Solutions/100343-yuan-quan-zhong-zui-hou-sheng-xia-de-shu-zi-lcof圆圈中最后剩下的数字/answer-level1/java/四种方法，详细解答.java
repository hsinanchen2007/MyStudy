## 本文参考
* [约瑟夫环详解](https://mp.weixin.qq.com/s?__biz=MzI4Njc4MzMwMw==&mid=2247483879&idx=1&sn=92ae32799b4c84e0ab07bf32ef5910e1&chksm=ebd6e3cfdca16ad9101200e5a1933432767d6b2f754563339566ef0880611fb43349e07e86cb&token=1909141869&lang=zh_CN#rd)


## 题目讲解
#### 解法1：常规解法（模拟一）
**【核心思想】**
* 用链表模拟这个游戏

**【数据结构】**
* 链表


**【思路】**
* 将[0,n]依次存储在链表中
* 只要链表的长度不为1，就一直循环，如果到了第m个就remove；**否则将其添加到链表尾部**
* 时间复杂度为O(nm)

**【代码】**
```java
public int lastRemaining(int n, int m) {
     List<Integer> list=new ArrayList<>();
     for(int i=0;i<n;i++)
         list.add(i);
     while(list.size()>1){
         for(int j=0;j<m;j++){
             if(j!=m-1)
                 list.add(list.get(0));
             list.remove(0);
         }
     }
     return list.get(0);
 }
```
**【备注】**
* 这个模拟的方法虽然简单，但是超时。怎么办？我们稍微改一下逻辑。

#### 解法2：常规解法（模拟二）
**【核心思想】**
* 用链表模拟这个游戏

**【数据结构】**
* 链表


**【思路】**
* 将[0,n]依次存储在链表中
* 通过举例可以得出第一次删除的数字下标为(m-1)%n记为c，之后每一次删除的数字下标均为(c+m-1)%list.size()

**【代码】**
```java
public int lastRemaining(int n, int m) {
     if(n==0||m==0)
		return -1;
     List<Integer> list=new ArrayList<>();
     for(int i=0;i<n;i++)
     	list.add(i);
     int c=(m-1)%n;
     while(list.size()!=1) {
     	list.remove(c);
     	c=(c+m-1)%list.size();  
     }
     return list.get(0);
 }
```
**【备注】**
* 这个模拟的方法可以通过oj的检测，但是还不是最佳的方案。这道题是一道**约瑟夫环**的问题，我们可以用数学的方法来解决。

#### 解法3：数学方法（迭代与递归）

**【思路】**
* n个数字的圆圈，不断删除第m个数字，我们把最后剩下的数字记为f(n,m)
* n个数字中第一个被删除的数字是(m-1)%n (取余的原因是m可能比n大)， 我们记作k，k=(m-1)%n
* 那么剩下的n-1个数字就变成了：0,1,……k-1,k+1,……,n-1，我们把下一轮第一个数字排在最前面，并且将这个长度为n-1的数组映射到0~n-2。

|原始数组| 映射数字|
|--|--|
| k+1| 0|
| k+2| 1|
| ...| ...|
| n-1| n-k-2|
| 0| n-k-1|
| ...| ...|
| k-1| n-2|
* 把映射数字记为x，原始数字记为y，那么映射数字变回原始数字的公式为 
$$y=(x+k+1) \mod n $$

* 在映射数字中，n-1个数字，不断删除第m个数字，由定义可以知道，最后剩下的数字为f(n-1,m)。我们把它变回原始数字，由上一个公式可以得到最后剩下的原始数字是（f(n-1,m)+k+1)%n，**而这个数字也就是一开始我们标记的f(n,m)**，所以可以推得递归公式为
$$f(n,m) =（f(n-1,m)+k+1)\mod n$$
* 将k=(m-1)%n代入，化简得到：
$$f(n,m) =（f(n-1,m)+m)\mod n， 且f(1,m) = 0$$
* 代码中可以采用迭代或者递归的方法实现该递归公式。时间复杂度为O(n)，空间复杂度为O(1)
* 注意公式中的mod就等同于%，为取模运算。值得注意的是，在数学中，下式成立：(a%n+b)%n=(a+b)%n

**【代码】**

```java
\\迭代
public int lastRemaining(int n, int m) {
    int flag = 0;   
    for (int i = 2; i <= n; i++) {
        flag = (flag + m) % i;
        //动态规划的思想，将f(n,m)替换成flag存储
    }
    return flag;
}

\\递归
public int lastRemaining(int n, int m){
    if(n < 1 || m < 1)       
        return -1;
    if(n == 1)
        return 0;
    return (lastRemaining(n-1, m) + m) % n;
}
```
* [【关注微信公众号，带你拿大厂offer】](https://mp.weixin.qq.com/s?__biz=MzI4Njc4MzMwMw==&mid=2247483879&idx=1&sn=92ae32799b4c84e0ab07bf32ef5910e1&chksm=ebd6e3cfdca16ad9101200e5a1933432767d6b2f754563339566ef0880611fb43349e07e86cb&token=1909141869&lang=zh_CN#rd)

