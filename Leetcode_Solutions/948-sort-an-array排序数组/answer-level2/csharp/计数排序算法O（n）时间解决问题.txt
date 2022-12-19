### 解题思路
由于给出数据范围在-50000到50000，因而申请十万零一个数组空间来存储。把每一个nums数据的值当做索引来存储。

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