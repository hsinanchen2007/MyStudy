**思路1：** 比较容易想到的暴力解法，遍历nums1中的元素，并在nums2中一个去找是否存在下一个最大值。
```
public int[] NextGreaterElement(int[] nums1, int[] nums2)
        {
            var result = new int[nums1.Length];

            for (int i = 0; i < nums1.Length; i++)
            {
                //初始化对应的result为-1
                result[i] = -1;
                //nums1中的目标值是否在nums2中找到
                bool IsTargetFinded = false;
                for (int j = 0; j < nums2.Length; j++)
                {
                    if (nums2[j] > nums1[i] && IsTargetFinded == true)
                    {
                        result[i] = nums2[j];
                        //找到第一个结果就可返回
                        break;
                    }
                    else if (nums2[j] == nums1[i])
                    {
                        IsTargetFinded = true;
                    }
                }
            }

            return result;
        }
```
**思路2：** 在思路1中做的重复劳动是：在内存循环中，nums2中的元素被访问了多次。如果我们每次能够知道nums1中的元素在nums2中的位置，就可以在内层循环中直接找到nums1目标值在nums2中的索引位置。所以一开始我们可以用Dictionary存储nums2中的值和索引的关系，然后内层遍历直接查找目标位置，并从目标位置开始往后遍历查找下一个更大元素。
```
public int[] NextGreaterElement2(int[] nums1, int[] nums2)
        {
            var result = new int[nums1.Length];
            var dict = new Dictionary<int, int>();

            for (int i = 0; i < nums2.Length; i++)
            {
                dict.Add(nums2[i], i);
            }

            for (int i = 0; i < nums1.Length; i++)
            {
                //初始化对应的result为-1
                result[i] = -1;
                //nums1中的目标值是否在nums2中找到
                for (int j = dict[nums1[i]]; j < nums2.Length; j++)
                {
                    if (nums2[j] > nums1[i])
                    {
                        result[i] = nums2[j];
                        //找到第一个结果就可返回
                        break;
                    }
                }
            }

            return result;
        }
```
![image.png](https://pic.leetcode-cn.com/ba1b5ec13351da385861e86fc3e323f2fcc4678937ecff0ef0cbedc212a30a27-image.png)

**思路3：** 思路2在一开始就将nums中的值和索引关系放到了Dictionary中，而这个过程可以在下面遍历过程中逐渐添加完成。但是不建议这样做，因为代码的可读性变差了很多，后面维护也比较容易出错。
```
public int[] NextGreaterElement3(int[] nums1, int[] nums2)
        {
            var result = new int[nums1.Length];
            var dict = new Dictionary<int, int>();

            for (int i = 0; i < nums1.Length; i++)
            {
                //初始化对应的result为-1
                result[i] = -1;
                //nums1中的目标值是否在nums2中找到
                if (dict.ContainsKey(nums1[i]))
                {
                    for (int j = dict[nums1[i]]; j < nums2.Length; j++)
                    {
                        if (!dict.ContainsKey(nums2[j]))
                        {
                            dict.Add(nums2[j], j);
                        }
                        if (nums2[j] > nums1[i])
                        {
                            result[i] = nums2[j];
                            //找到第一个结果就可返回
                            break;
                        }
                    }
                }
                else
                {
                    bool IsTargetFinded = false;
                    for (int j = 0; j < nums2.Length; j++)
                    {
                        if (!dict.ContainsKey(nums2[j]))
                        {
                            dict.Add(nums2[j], j);
                        }
                        if (nums2[j] > nums1[i] && IsTargetFinded == true)
                        {
                            result[i] = nums2[j];
                            //找到第一个结果就可返回
                            break;
                        }
                        else if (nums2[j] == nums1[i])
                        {
                            IsTargetFinded = true;
                        }
                    }
                }
            }

            return result;
        }
```
