### 解题思路
判断当前剩余糖果是否够分下一次，不够分则结束循环

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans=new int[num_people];
        int i=1;
        int index=0;
        while(candies>i)
        {
            ans[index]=i+ans[index];
            candies=candies-i;
            i=i+1;
            index=index+1;
            index=index%num_people;
        }
        ans[index]=candies+ans[index];
        return ans;
    }
}
```