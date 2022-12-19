```
public int[] Intersect(int[] nums1, int[] nums2)
{
    if (nums1==null || nums2==null || nums1.Length==0 || nums2.Length==0)
    {
        return null;
    }
    //调整nums1为小数组
    if (nums1.Length > nums2.Length)
    {
        int[] temp = nums1;
        nums1 = nums2;
        nums2 = temp;
    }
    //存nums1所有不重复元素
    Dictionary<int, int> dic = new Dictionary<int, int>();
    for (int i = 0; i < nums1.Length; i++)
    {
        if (!dic.ContainsKey(nums1[i]))
        {
            dic.Add(nums1[i], i);
        }
    }
    //存nums2中含有nums1中的元素 也就是结果
    Dictionary<int, int> dic2 = new Dictionary<int, int>();
    for (int i = 0; i < nums2.Length; i++)
    {
        if (dic.ContainsKey(nums2[i]))
        {
            if (!dic2.ContainsKey(nums2[i]))
            {
                dic2.Add(nums2[i], i);
            }
        }
    }
    //转换结果为数组
    int[] result = new int[dic2.Count];
    int j = 0;
    foreach (var item in dic2.Keys)
    {
        result[j] = item;
        j++;
    }
    return result;
}
```