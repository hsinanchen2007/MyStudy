### 解题思路
基本上是相当于把官方的C++方案改写了一下，思想其实还是枚举，这是C#的版本的第一种

### 代码

```csharp
public class Solution {
    public int[][] FindContinuousSequence(int target) {
        List<int> res = new List<int>();
        List<int[]> expandres = new List<int[]>();
        int sum = 0;
        int mid = target%2 == 0?target/2:(target+1)/2;
        for(int left = 1;left<=mid;++left){
            for(int right = left;;++right){
                sum += right;
                if(sum > target){
                    sum = 0;
                    break;
                }
                else if(sum == target){
                    res.Clear();
                    for(int addit = left;addit<=right;addit++){
                        res.Add(addit);
                    }
                    expandres.Add(res.ToArray());
                    sum = 0;
                    break;
                }
            }
        }
        return expandres.ToArray();
    }
}
```