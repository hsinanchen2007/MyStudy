执行用时 : 388 ms, 在Intersection of Two Arrays II的C#提交中击败了89.38% 的用户
内存消耗 : 29.1 MB, 在Intersection of Two Arrays II的C#提交中击败了28.95% 的用户

和两个数组的交集I 相比,这道题要求不去掉重复,而哈希表不能储存重复的key
上一题中哈希表key和value我们只用了一个key而已,所以这道题value再存个元素出现的次数就ojbk了
```
public int[] Intersect(int[] nums1, int[] nums2)
{
    if (nums1 == null || nums2 == null || nums1.Length == 0 || nums2.Length == 0)
    {
        return new int[] { };
    }
    //调整nums1为小数组
    if (nums1.Length > nums2.Length)
    {
        int[] temp = nums1;
        nums1 = nums2;
        nums2 = temp;
    }
    //存nums1所有不重复元素,与出现的次数
    Dictionary<int, int> dic = new Dictionary<int, int>();
    for (int i = 0; i < nums1.Length; i++)
    {
        if (!dic.ContainsKey(nums1[i]))
        {
            dic.Add(nums1[i], 0);//未出现过的元素,设置出现次数为0
        }
        else
        {
            dic[nums1[i]]++;//已经存在 增加出现次数
        }
    }
    //存nums2中含有nums1中的元素 也就是结果
    List<int> list = new List<int>();
    for (int i = 0; i < nums2.Length; i++)
    {
        //已经出现过的元素 并且出现的次数不小于0
        if (dic.ContainsKey(nums2[i]) && dic[nums2[i]] >= 0)
        {
            list.Add(nums2[i]);//向List中添加该元素
            dic[nums2[i]]--;//降低该元素的出现次数
        }
    }
    //转换结果为数组
    int[] result = new int[list.Count];
    int j = 0;
    foreach (var item in list)
    {
        result[j] = item;
        j++;
    }
    return result;
}
```