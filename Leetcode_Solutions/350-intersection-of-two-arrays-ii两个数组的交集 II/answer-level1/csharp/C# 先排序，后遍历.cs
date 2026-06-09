执行用时 : 292 ms, 在所有 C# 提交中击败了96.83%的用户
内存消耗 :29.8 MB, 在所有 C# 提交中击败了5.26%的用户
```
public class Solution {
    public int[] Intersect(int[] nums1, int[] nums2) {
        if(nums1.Length == 0 || nums2.Length == 0) return new int[0];
        
        Array.Sort(nums1);
        Array.Sort(nums2);
        int i = 0;
        int j = 0;
        List<int> intersectList = new List<int>();
        while(true)
        {
            if(nums1[i] < nums2[j])
                i++;
            else if(nums1[i] > nums2[j])
                j++;
            else
            {
                intersectList.Add(nums1[i]);
                i++;
                j++;
            }
            if(i == nums1.Length || j == nums2.Length) return intersectList.ToArray();
        }
    }
}
```
