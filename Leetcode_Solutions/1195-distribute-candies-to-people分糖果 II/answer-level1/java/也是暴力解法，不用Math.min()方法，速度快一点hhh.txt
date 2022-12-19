### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int count = 0;
        while(candies > 0){
            for(int i = 0;i < ans.length; i++){
                if(candies < (count * num_people + i + 1)){
                    ans[i] = ans[i] + candies;
                    candies = 0;
                    break;
                }
                candies = candies - (count * num_people + i + 1);
                ans[i] = ans[i] + count * num_people + i + 1;
                if(candies == 0)
                    break;
            }
            count++;
        }
        return ans;
    }
}
```