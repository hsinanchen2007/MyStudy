### 解题思路
模拟分糖果，将索引对num_people求余数；

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] result = new int[num_people];
        int i = 0;
        while(candies>0){
            int num = candies>=i+1?i+1:candies;
            result[i%num_people] += num;
            candies -= num;
            i++;
        }
        return result;
    }
}
```