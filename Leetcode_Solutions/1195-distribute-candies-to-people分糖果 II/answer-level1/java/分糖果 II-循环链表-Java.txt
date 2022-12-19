### 解题思路
首先我看到再回到队伍的起点、重复上述过程等字眼，第一想法就是用循环链表和循环队列的数据结构。
我这里用循环链表来实现的。
1、先让dividedCandy数组默认都是0;
2、再让第一个小朋友默认分1颗糖果;
3、循环判断总剩余糖果与将要分的糖果count颗数；
4、对将要分的小朋友取模运算，这样保证不管怎么遍历也只是num_people个小朋友中的其中一个；
5、对i进行取模加1，也就是下一个小朋友；
6、总糖果数每次都要减掉分配给某个小朋友的count糖果数；
7、糖果数count++；
8、最后剩余糖果数小于等于将要分配的糖果数count时，最后那个人就加上最后剩余的糖果数。

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] dividedCandy = new int[num_people];
        for (int i = 0; i < num_people; i++) {
            dividedCandy[i] = 0;
        }

        int i = 0, count = 1;
        dividedCandy[i] = count;
        i++;count++;candies--;
        while (candies > count) {
            dividedCandy[i % num_people] += count;
            i = i % num_people + 1;
            candies -= count;
            count++;
        }
        dividedCandy[i % num_people] += candies;
        return dividedCandy;
    }
}
```