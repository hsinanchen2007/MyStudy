### 解题思路
遍历小朋友，遍历完最后一个再从头开始，直到糖果发完为止

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        if (candies <= 0 || num_people <= 0) {
            return null;
        }
        int[] ans = new int[num_people];
        int add = 0;
        for (int i = 0; i < num_people; i++) {
            ++add;
            if (candies <= add) {
                //当糖果个数少于这次要发的，这次发完就结束循环
                ans[i] += candies;
                break;
            } else {
                ans[i] += add;
                candies -= add;
            }
            if (i + 1 >= num_people) {
                i = -1;//一边循环完毕再次退回到0
            }
        }
        return ans;
    }
}
```