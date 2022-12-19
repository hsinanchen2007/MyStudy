### 解题思路
每個語言的寫法都差不多，如何讓時間更快才是重點。
第一眼看到題目就想到這個方法，結果因為才剛寫完一題位元運算，總覺得可以用位元解法
想了半天還是純實樸華的最快


### 代码

```csharp
public class Solution {
    public int FindMaxConsecutiveOnes(int[] nums) {
        int count=0, tmp=0;
        foreach(int n in nums)
        {
            if(n!=0)
                tmp+=1;
            else
                tmp=0;
            count=Math.Max(count,tmp);
        }
        return count;
    }
}
```