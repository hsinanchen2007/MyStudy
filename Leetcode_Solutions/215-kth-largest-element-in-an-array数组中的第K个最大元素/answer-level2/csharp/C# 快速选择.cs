### 解题思路
使用快速选择法，因此首先需要理解快速排序中的分区操作

### 代码

```csharp
public class Solution {
    public int FindKthLargest(int[] nums, int k) {
        int lowestItem=nums.Length-k;
        return QuickSelect(nums,0,nums.Length-1,lowestItem);
    }

    private int QuickSelect(int[]nums, int left,int right,int k)
    {
        if(right<=left)
        {
            return nums[left];
        }

        int pivotIndex= Partition(nums,left,right);
        if(pivotIndex==k)
        {
            return nums[k];
        }
        else if(pivotIndex>k)
        {
            return QuickSelect(nums,left,pivotIndex-1,k);
        }
        else
        {
            return QuickSelect(nums,pivotIndex+1,right,k);
        }
    }


    private int Partition(int[] nums, int left, int right)
    {
        int pivot=nums[left];
        int i=left+1;int j=right;
        while(true)
        {
            while(i<=right && nums[i]<pivot) i++;
            while(j>=left + 1 && nums[j]>pivot) j--;
            if(i>j)
            {
                break;
            }
            else
            {
                Swap(nums,i,j);
                i++;j--;
            }
        }

        Swap(nums,left,j);
        return j;
    }

    private void Swap(int[] nums, int a,int b)
    {
        if(nums.Length-1>=a && nums.Length-1>=b)
        {
            int tmp = nums[a];
            nums[a] = nums[b];
            nums[b] = tmp;
        }
    }
}
```