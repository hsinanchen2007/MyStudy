### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int[] Exchange(int[] nums) {
        int count1=0,len=nums.Length;
        int count2=len-1;
        int[] arr = new int[len];
        for(int i=0;i<nums.Length;i++){
            if((nums[i]&1)==1){
                arr[count1]=nums[i];
                count1++;
            }
            else{
                
                arr[count2]=nums[i];
                count2--;
            }
        }
        return arr;
    }
}
```