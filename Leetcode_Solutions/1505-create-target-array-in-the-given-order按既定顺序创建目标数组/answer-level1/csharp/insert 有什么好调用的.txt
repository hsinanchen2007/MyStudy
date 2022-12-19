### 解题思路

更新 index的位置信息 规则是后边又相同或者小于当前数字的 自动位置更新+1 同时用更新后的数继续比 

### 代码

```csharp
public class Solution {
    public int[] CreateTargetArray(int[] nums, int[] index) {
        int[] target = new int[nums.Length];
        
        for(int i = 0; i < index.Length; i++)
        {
            target[Time(i, index)] = nums[i];
        }

        return target;
    }

    public int Time(int point, int[] index){
        int cur = index[point];
        for(int i = point + 1; i < index.Length; i++)
        {
            if(index[i] <= cur)
            {
                cur++;        
            }
        }
        return cur;
    }
}
```