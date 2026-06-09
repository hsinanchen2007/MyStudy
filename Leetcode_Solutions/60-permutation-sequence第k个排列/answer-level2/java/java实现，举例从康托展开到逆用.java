什么是康托展开式可以先从百度了解。本文直接从示例着手。

![question60 1.png](https://pic.leetcode-cn.com/44cb5d92c5ae37e8bde7c32e83f0a636e272ad02da58328185f38bd09c3f7f68-question60%201.png)


其实就是找出比"213"小的排列有几个，然后+1。

先比较首位，比2小的只有1，1开头的排列有1*2!个。

第二位比1小的不存在所以有0\*1!排列。

第三位比3小的有1和2但是前面已经用过所以有0\*0!个。

综上所述，有2个比"213"小的排列，所以"213"排在第3位。

**本题是逆用，知道n和第k个，求排列本身。**

例如：要找n=5，k=35的排列。共有5!=120个排列，从小到大要找第35个排列。

从首位开始找，首位分别是1、2、3、4、5的排列分成五组，每组各有(5-1)!=24个，由于k=35，所以要找的排列在第二组中，就是首位是2开头的24个排列中，即目标排列首位是"2"。

再看第二位，第二位可能是1、3、4、5分成四组，每组分别有(5-2)!=6个，由于k-24=11，所以要找的排列在第二组中，即目标排列的前两位是"23"。

同理，第三位可能是1、4、5分成三组，每组分别有(5-3)!=2个，因为k-6=5，所以要找的排列在第三组的两个排列中，即目标排列的前三位是"235"。

再然后第四位可能是1、4，分两组各有(5-4)!=1个，因为k-4=1，所以在第一组，即目标排列的前四位是"2351"。

最后第五位只剩下4，所以目标排列是"23514"。

找到第35个排列。

**其实这个方法就是分组，上例中找第一位时候将有序全排列按照首位数字分为5组，看看我们要找的那个排列在第几组中从而确定了首位数字。**

```java
public String getPermutation(int n, int k) {
    StringBuilder ans=new StringBuilder();
    //所有可用数字
    StringBuilder map=new StringBuilder();
    for (int i = 1; i <= n ; i++)map.append(i);
    int groupId,index=n;
    //逐位确定
    for (int i = 1; i <= n; i++) {
        index--;
        //确定在当前分组的第几组
        groupId=(k-1)/foc(index);
        //得到分组的数字，移除使用过的数字
        ans.append(map.charAt(groupId));
        map.deleteCharAt(groupId);
        //更新k
        k-=groupId*foc(index);
    }
    return ans.toString();
}
// 求 i!
private int foc(int i) {
    int x=1;
    while (i>=1){
        x*=i--;
    }
    return x;
}
```

时间复杂度：O(n^2)	题目说n的范围[1,9]，可以直接将1~9的阶乘预先保存在一个数组中。

```java
public String getPermutation(int n, int k) {
    StringBuilder ans=new StringBuilder();
    //0~9的阶乘,直接使用
    int factor[] = {1,1,2,6,24,120,720,5040,40320,362880};
    //所有可用数字
    StringBuilder map=new StringBuilder();
    for (int i = 1; i <= n ; i++)map.append(i);
    int groupId,index=n;
    //逐位确定
    for (int i = 1; i <= n; i++) {
        index--;
        //确定在当前分组的第几组
        groupId=(k-1)/factor[index];
        //得到分组的数字，移除使用过的数字
        ans.append(map.charAt(groupId));
        map.deleteCharAt(groupId);
        //更新k
        k-=groupId*factor[index];
    }
    return ans.toString();
}
```

时间复杂度：O(n)

---

本人菜鸟，有错误请告知，感激不尽！

更多题解和学习记录博客:[博客](https://blog.csdn.net/qq_42758551)**、**[github](https://jerrymouse1998.github.io/) 