### 解题思路
* 走到第n个小朋友要分n块糖
* 走到第n个小朋友如果没有n块糖，分给小朋友的糖果就是剩余的和n取最小值
* 暴力分配方法是每次分配都取两者之间的最小值
* 分糖果时要累积，小朋友每一轮分配的糖果都加起来

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int n = num_people;
        int[] ans = new int[n];
        int residue = candies;
        int i = 0;
        while(residue != 0) {
            int yourCandies = Math.min(residue,i+1);
            ans[i%n] += yourCandies;
            residue -= yourCandies;
            i = i + 1;
        }
        return ans;
    }
}
```