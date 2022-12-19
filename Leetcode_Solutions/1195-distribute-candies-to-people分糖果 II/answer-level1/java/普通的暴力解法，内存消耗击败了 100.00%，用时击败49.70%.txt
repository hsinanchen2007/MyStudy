### 解题思路
- 暴力破解
### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] arr = new int[num_people];
        int n = 0;
        while (candies > 0) {
            for (int i = 1; i <= num_people; i++) {
                arr[i - 1] += Math.min(candies, i + n * num_people);
                candies -= (i + n * num_people);
                if (candies <= 0) {
                    break;
                }
            }
            n++;
        }
        return arr;
    }
}
```