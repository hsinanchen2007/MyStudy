### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {

        int[] ans = new int[num_people];

        for(int i = 0; candies > 0; i++){
            if(candies - i > 0){
                ans[i%num_people] = ans[i%num_people] + i + 1;
                candies = candies - i - 1;
            }
            else{
                ans[i%num_people] = ans[i%num_people] + candies;
                candies = 0;
            }
        }

        return ans;
    }
}
```