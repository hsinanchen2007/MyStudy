```
  public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int i = 0;
        int cur = 1;
        // 糖果的数量 >= 当前要分的糖果数
        while (candies >= cur) {
            ans[i] += cur;
            candies -= cur;
            cur++;
            i = (i + 1) % num_people;
        }
        // 如果还剩下糖果，要分掉
        if (i < num_people && candies > 0) {
            ans[i] += candies;
        }
        return ans;
    }
```
