![image.png](https://pic.leetcode-cn.com/4e7d95851e30715a82f882679c8687673bc9da718b424f9e27b5ef15fe6bc50d-image.png)

```
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        
        int [] ans = new int[num_people];
        int index = 0;int counts = 1;
        while (candies - counts >= 0){
            ans[index++%num_people] += counts;
            candies -= counts++;
        }
        ans[index%num_people] += candies;
        return ans;
    }
}
```
