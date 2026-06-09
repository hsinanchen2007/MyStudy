### 解题思路
没啥技巧吧。双循环暴力减糖果，分配就行了。

### 代码

```csharp
public class Solution {
    public int[] DistributeCandies(int candies, int num_people) {
      int[] nums=new int[num_people];
      int sumSendCandies=0;
      int leftCandies=candies;
      int step=0;
      while(leftCandies>0)
      {

        for(int i=0;i<num_people;i++)
        {
          if(i+num_people*(step)+1<leftCandies)
          {
            nums[i]+=i+1+num_people*(step);
            sumSendCandies+=i+1+num_people*(step);
          }
          else
          {
              nums[i]+=leftCandies;
              sumSendCandies+=leftCandies;
          }
          
            leftCandies=candies-sumSendCandies;
        }
        step++;
      }
      return nums;
    }
}
```