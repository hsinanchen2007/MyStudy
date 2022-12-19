### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] distribut = new int[num_people];
        int i;
        for(i = 1; (candies = candies - i) > 0; i++){
            distribut[(i - 1) % num_people] += i; 
        }
        distribut[(i - 1) % num_people] += candies + i;
        return distribut;
    }
}
```