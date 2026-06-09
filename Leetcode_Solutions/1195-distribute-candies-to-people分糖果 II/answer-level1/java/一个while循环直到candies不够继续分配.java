### 解题思路
一个while循环直到candies不够继续分配，再将剩余的糖果分给下一个小孩。

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] res = new int[num_people];
        int i = 0;
        int n = 1;
         while(candies>=n){
            if(i==num_people)
                i = 0;
            res[i] += n;
            candies -= n;
            n++;
            i++;
        }
        res[i%num_people] += candies;
        return res;
    }
}
```