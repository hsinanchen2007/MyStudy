### 解题思路
为了规避给定的数组里面的重复元素，而且仍然保持只用一次for loop, 用一个List来存储每个值对应的序号。这样虽然快但是很耗内存，在内存不敏感的情况下可用。第二个for loop只是在一个值的重复的序号中递归，如果重复不多基本可以忽略。

### 代码

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int,List<int>> dic=new Dictionary<int,List<int>>();

        for(int i=0; i<nums.Length; i++){
            int x=target-nums[i];
            if(dic.ContainsKey(x)){
                dic[x].Add(i);
            }else{
                var l=new List<int>();
                l.Add(i);
                dic.Add(x,l);
            }
            
            if(dic.ContainsKey(nums[i])){
                for(int j=0; j<dic[nums[i]].Count; j++){
                    if(dic[nums[i]][j]!=i){
                    return new int[2]{dic[nums[i]][j],i};
                    }
                }
                
                
            }
        }
        return null;
    }
}
```