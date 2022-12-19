### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ret = new int[num_people];
        // candy变量记录每一次给的糖果数
        int candy = 1;
        while(candies >= candy){
            ret[(candy - 1) % num_people] += candy;
            candies -= candy;
            candy++;
        }
        // 糖不够了直接把剩下的给最后一个人
        ret[(candy - 1) % num_people] += candies;
        return ret;
    }
}
```