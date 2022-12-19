### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int[] GetLeastNumbers(int[] arr, int k) {
        HeapSort(arr,k);
        int[] ans = new int[k];
        for(int i = 0;i < k;i++){
            ans[i] = arr[arr.Length - i - 1];
        }
        return ans;
    }
    private void HeapSort(int[] nums,int k)
    {
        BuildHeap(nums);
        for (int i = nums.Length - 1; i > nums.Length - 1 - k; i--)
        {
            Swap(ref nums[0],ref nums[i]);
            Heapify(nums,0,i);
        }
    }
    
    private void BuildHeap(int[] nums)
    {
        for (int i = (nums.Length - 1) / 2; i >= 0; i--)
        {
            Heapify(nums,i,nums.Length);
        }
    }
    private void Heapify(int[] nums,int current,int heapsize)
    {
        int leftchild = current * 2 + 1;
        int rightchild = current * 2 + 2;
        int max = current;
        if (leftchild < heapsize && nums[leftchild] < nums[max])
        {
            max = leftchild;
        }

        if (rightchild < heapsize && nums[rightchild] < nums[max])
        {
            max = rightchild;
        }

        if (max != current)
        {
            Swap(ref nums[max],ref nums[current]);
            Heapify(nums,max,heapsize);
        }
    }

    private void Swap(ref int a, ref int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}
```