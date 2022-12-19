### 解题思路
Keep iterating until no more candies available.

### 代码

```csharp
public class Solution {
    public int[] DistributeCandies(int candies, int num_people) {
        int[] candiesDistribution = new int[num_people];
        int currentIndex = 0;
        
        while (candies != 0) {
            int currentIteration = currentIndex / num_people;
            int relativeIndex = currentIndex % num_people;
                        
            int expectedCandiesToDistribute = currentIteration * num_people + relativeIndex + 1;
            int candiesToDistribute = candies > expectedCandiesToDistribute ? expectedCandiesToDistribute : candies;
            candiesDistribution[relativeIndex] += candiesToDistribute;
            
            candies -= candiesToDistribute;
            currentIndex++;
        }

        return candiesDistribution;
    }
}
```