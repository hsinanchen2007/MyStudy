### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int[] SortArray(int[] nums) {
        int[] arr  = new int[100001];
        for(int i = 0;i<nums.Length;i++){
            arr[nums[i]+50000]++;
        }
        int j = 0;
        for(int i = 0;i<arr.Length;i++){
            while(arr[i]!=0){
                nums[j] = i-50000;
                j++;
                arr[i]--;
            }
        }
        return nums;
    }
}

```