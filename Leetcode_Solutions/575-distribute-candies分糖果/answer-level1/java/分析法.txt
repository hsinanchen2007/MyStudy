### 解题思路
妹妹要满足两个条件：第一 糖果种类数目不能比哥哥少；第二 两人分到的糖果数量要一样。

所以考虑极端情况： 当糖果种类最多（即每种一个），妹妹也只能得到一半的糖果种类数（条件2限制）；糖果数量最少，就是一种糖果，妹妹获得一种糖果，糖果总量一般。

所以我们为了保证种类，分法：先每种糖果给妹妹一个，如果达到数目的一半，不管后面还有没有新种类，妹妹也只能得到一半。 如果发了几颗就已经开始重复（还没有到糖果的一半），那发再多种类也只有这么多；

所以妹妹能得到的就是 糖果种类数目 和糖果总数一半 两者取小。

### 代码

```java
class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> set = new HashSet<>();
        for(int candy:candies){
            set.add(candy);
        }
        int len = candies.length;
        return Math.min(set.size(),len/2);
    }
}
```