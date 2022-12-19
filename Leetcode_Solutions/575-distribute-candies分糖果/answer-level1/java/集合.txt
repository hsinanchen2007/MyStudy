```java
class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> set = new HashSet<>();
        int num = 0;
        int len = candies.length >> 1;
        for (int candy : candies) {
            if (!set.contains(candy)) {
                num++;
                if (num == len) {
                    break;
                }
                set.add(candy);
            }
        }
        return num;
    }
}
```
