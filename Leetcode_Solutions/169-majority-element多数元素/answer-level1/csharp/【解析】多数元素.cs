### 解题思路
比较简单的遍历思路就可以解决本题。从头到尾遍历，检查每个元素重复的次数是否大于n/2，若大于则返回，否则将计数器置为1后继续重复。

### 代码

```csharp
public class Solution {
    public int MajorityElement(int[] nums) {
        Array.Sort(nums);
        for(int i=0; i<nums.Length; i++) {
            Console.Write(nums[i] + ", ");
        }

        int count = 1;
        int n = nums.Length;
        if(n == 1) return nums[0];
        for(int i=1; i<n; i++) {
            if(nums[i] == nums[i-1]) count++;
            else count = 1;
            if(count > n/2) return nums[i-1];
        }

        return 0;
    }
}
```