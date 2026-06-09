### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public IList<IList<int>> Subsets(int[] nums) {
            
            int num = 1;

            for(int i=1;i<=nums.Length;i++){
                num*=2;
            }
            num-=1;
            IList<IList<int>> result = new List<IList<int>> ();
            for(int j=0; j<=num; j++){
                IList<int> once = new List<int>();
                for(int k=0; k<nums.Length; k++){
                    int bit = 1<<k;
                    if((j&bit)!=0){
                        once.Add(nums[k]);
                    }
                }
                result.Add(once);
            }

            return result;
    }
}
```