### 解题思路
这题对于我这种小白来说的话，最开始要理解的就是如何颠倒数字的原理。比如21这个数字，首先我们要把1抽取出来，也就是x%10求余能得到个位数上的1。然后要得到2的话就需要让x/10来得到十分位上面的数字。之后再将个位的数字乘以10再加上十分位的数字，就可以将21反转成12了。这是最简单的两位数的反转。同理，一直做这个运算，就可以将所有的数字反转啦。明白了这个之后，我们又碰到一个问题，如果溢出怎么办。首先看看rev=rev*10+pop;这个表达式，这里面有两个变量rev和pop。首先，rev只要>integer.maxvlaue||<integer.minvalue则必定溢出。当rev==integer.maxvlaue||integer.minvalue时，也就是说这里的个位是零。那起决定性作用的就是pop了。我们先计算一下int型的最大值和最小值,发现个位上的值分别为7和-8。这样，pop只要>7或者<-8时必定溢出。所以，从这两个方面将溢出值返回零即可。

### 代码

```java
class Solution {
    public int reverse(int x) {
       int rev=0;
       while(x!=0){
           int pop=x%10;
           x/=10;
           if(rev > Integer.MAX_VALUE/10||(rev==Integer.MAX_VALUE/10&&pop>Integer.MAX_VALUE%10)){return 0;}
           if(rev < Integer.MIN_VALUE/10||(rev==Integer.MIN_VALUE/10&&pop<Integer.MIN_VALUE%10)){return 0;}
           rev=rev*10+pop;
       }
       return rev;
    }
}
```