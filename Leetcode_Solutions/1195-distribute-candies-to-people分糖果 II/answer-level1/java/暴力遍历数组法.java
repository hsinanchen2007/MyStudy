### 解题思路
此处撰写解题思路
     思路是当剩余的糖果leftCandies还有，即leftCandies > 0时就一直派糖。
     循环遍历数组，当剩余糖果大于要被分派的糖果数量时，则循环继续，否则把所有剩余糖果分给当前数组元素，并结束循环。
### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int n = 1;
        int i;
        int sum = 0;
        int leftCandies = candies;
        int A[] = new int[num_people];
        while (leftCandies > 0) {
            for (i = 0;i < num_people;i++) {
                if (candies - sum >= n) {
                    A[i] += n;
                    leftCandies -= n;
                    sum += n;
                    n++;
                } else {
                    A[i] += leftCandies;
                    leftCandies = 0;
                }
                
            }
        }
        
        return A;
    }
}
```