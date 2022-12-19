### 解题思路
![image.png](https://pic.leetcode-cn.com/27f4326db69221d280bb2d1c51e30106172c8be9d8d9ce10f7275b1141606dc9-image.png)
此处撰写解题思路
    **这道题其实就是一个递归：递归出口是num是只有一位数，以xyzcba为例，先取最后两位（个位和十位）即ba，如果ba>=26，必然不能分解成f(xyzcb)+f(xyzc)，此时只能分解成f(xyzcb);但还有一种情况，就是ba<=9,也就是该数十位上为0，此时也不能分解。代码如下：**
### 代码

```java
class Solution {
    public int translateNum(int num) {
        if (num<=9) {return 1;}
        //xyzcba
        int ba = num%100;
        if (ba<=9||ba>=26) {return translateNum(num/10);}
        else  {return translateNum(num/10)+translateNum(num/100);}
    }
}
```