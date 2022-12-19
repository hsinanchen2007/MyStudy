### 解题思路
    如果最大种类数比糖果数的一半小，则妹妹能得到的糖果种类就为最大种类数。如果最大种类数比糖果数的一半大，即使有这么多类，妹妹也只能得到糖果数的一半。那么此时最多的种类就是她每种拿一个，即个数是糖果总数的一半。

### 代码

```java

class Solution {
    public int distributeCandies(int[] candies) {
        HashSet<Integer> set=new HashSet<Integer>();
        for(int candy:candies)
        {
            set.add(candy);
        }
        return Math.min(set.size(),candies.length/2);     
    }
}
```