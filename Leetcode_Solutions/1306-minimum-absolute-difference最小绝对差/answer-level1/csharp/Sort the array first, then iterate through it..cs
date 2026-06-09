### 解题思路
1. Sort `arr` first.
2. Iterate the sorted array **once**, there is no need to use nested loop, as the value is distinct, and we already sort the array.
3. Record the min absolute difference, and the value combination whose difference equals to the min absolute difference.
4. If the difference value is smaller than the recorded one, update the recorded min absolute difference, and re-create the list storing the value combination.

### 代码

```csharp
public class Solution {
    public IList<IList<int>> MinimumAbsDifference(int[] arr) {
        int minAbsDiff = arr.Max();
        int[] sortedArray = arr;
        Array.Sort(sortedArray);
        
        IList<IList<int>> minCombo = new List<IList<int>>();

        for (int i = 0; i < sortedArray.Length-1; i++) {
            int iVal = sortedArray[i];
            int jVal = sortedArray[i+1];

            int currentDiff = Math.Abs(jVal - iVal);
            
            if (currentDiff == minAbsDiff) {
                minCombo.Add(new List<int>{iVal, jVal});
            } 
            
            if (currentDiff < minAbsDiff) {
                minAbsDiff = currentDiff;
                minCombo = new List<IList<int>>{ new List<int>{iVal, jVal}};
            }    
        }

        return minCombo;
    }
}
```