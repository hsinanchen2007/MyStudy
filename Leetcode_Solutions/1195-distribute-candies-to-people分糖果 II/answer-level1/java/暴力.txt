### 解题思路
两层循环，暴力迭代

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {

        int[] ans = new int[num_people];
        int num = 1;
        while (candies > 0){
            for (int i = 0; i < num_people; i++) {
                if (candies>num){
                    ans[i] += num;
                }else {
                    ans[i] += candies;
                    candies = 0;
                    break;
                }
                candies -= num;
                num++;
            }
        }
        return ans;
    }
}
```