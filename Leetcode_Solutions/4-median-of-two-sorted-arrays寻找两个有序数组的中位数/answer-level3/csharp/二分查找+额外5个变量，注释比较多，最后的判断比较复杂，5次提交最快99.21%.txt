直接上代码
```
public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        // 先判断有空串的情况
        if (nums1 == null || nums1.Length == 0)
        {
            // 奇偶长度通用
            return (nums2[nums2.Length / 2] + nums2[(nums2.Length - 1) / 2]) / 2.0;
        }

        if (nums2 == null || nums2.Length == 0)
        {
            return (nums1[nums1.Length / 2] + nums1[(nums1.Length - 1) / 2]) / 2.0;
        }

        // 找出数组中较短的和较长的
        int[] numsShort = nums1, numsLong = nums2;
        if (nums1.Length > nums2.Length)
        {
            numsShort = nums2;
            numsLong = nums1;
        }

        // 对两个数组分别定义初始的中位数的下标，以短的作为基础，长的根据短的计算得来，整体而言，左侧数字不少于右侧
        // 4+6,1,3 -- OK -- 左右各4
        // 3+5,1,2 -- OK -- 左右各3
        // 3+4,1,2 -- OK -- 左3右2
        // 4+5,1,3 -- OK -- 左4右3
        int fullLength = numsShort.Length + numsLong.Length, indexS = (numsShort.Length - 1) / 2, indexL = (fullLength - 1) / 2 - indexS;
        int EdgeSL = 0, EdgeSR = numsShort.Length - 1;

        // 开始循环逼近中位数
        for(; ; )
        {
            if (numsShort[indexS] < numsLong[indexL])
            {
                // 如果短的小，则判断是否可以将短的下标右移
                if (indexS < EdgeSR)
                {
                    EdgeSL = Math.Max(indexS, EdgeSL + 1);
                    // 考虑到如果indexS和EdgeSR只差一个位置，那么indexS也需要右移一个位置
                    indexS = (indexS + EdgeSR + 1) / 2;
                    // 长数组的下标更新
                    indexL = (fullLength - 1) / 2 - indexS;
                    continue;
                }

                // 如果无法右移，则说明循环结束
                break;
            }
            else if (numsShort[indexS] > numsLong[indexL])
            {
                // 如果短的大，则判断是否可以将短的下标左移
                if (indexS > EdgeSL)
                {
                    EdgeSR = Math.Min(indexS, EdgeSR - 1);
                    // 考虑到如果indexS和EdgeSL只差一个位置，那么indexS也需要左移一个位置
                    indexS = (indexS + EdgeSL - 1) / 2;
                    // 长数组的下标更新
                    indexL = (fullLength - 1) / 2 - indexS;
                    continue;
                }

                // 如果无法左移，则说明循环结束
                break;
            }
            else
            {
                // 两个数字相等，则直接跳出循环
                break;
            }
        }

        // 开始判断取哪个或哪两个数作为中位数的计算依据，注意整体而言，左侧数字不少于右侧
        if (fullLength % 2 != 0)
        {
            // 整体长度是奇数，有两种情况
            // 1、两个数字中较小的那个（[1,3,5][0,2,4,6]）——下标是1,2，对应数字分别是3和4
            // 2、两个数字中较大的那个的左侧一个数字（[1,2,3][4,5,6,7]）——下标是2,1，对应数字分别是3和5
            // 不会出现两个数字中较小的那个的右侧一个数字的情况，因为此时较大的数字在整体而言就在较小数字的右侧，同时由于总长度为奇数时，两个下标左侧数字的总数比右侧数字的总数多一个，因此，抛弃较大那个数字就可以了
            if (numsShort[indexS] < numsLong[indexL])
            {
                // 短数组较小，indexL至少会是1，不可能为0
                if (numsShort[indexS] < numsLong[indexL-1])
                {
                    // 小的数字比大的数字的左侧还小，那么符合情况2
                    return numsLong[indexL - 1];
                }
                else
                {
                    // 不论是相等还是大于，都符合情况1
                    return numsShort[indexS];
                }
            }
            else if (numsShort[indexS] > numsLong[indexL])
            {
                // 短数组较大，需要考虑indexS为0的情况
                if (indexS == 0)
                {
                    // 不存在大数左侧的数字，符合情况1
                    return numsLong[indexL];
                }
                else if (numsShort[indexS-1] > numsLong[indexL])
                {
                    // 情况2
                    return numsShort[indexS - 1];
                }
                else
                {
                    // 情况1
                    return numsLong[indexL];
                }
            }
            else
            {
                // 两个数字相等，那中位数一定是这个数字
                return numsShort[indexS];
            }
        }
        else
        {
            // 整体长度是偶数，有四种情况
            // 1、小数大数都到各自边界，就是这两个数字
            // 2、小数到了边界，大数没到，额外判断小数和大数左侧数字，如果小数小于大数左侧，则取大数及其左侧数字
            // 3、大数到了边界小数没到，额外判断小数右侧数字和大数左侧数字，如果大数大于小数右侧，则取小数及其右侧数字
            // 4、都没到边界，额外判断小数与大数及其左侧数字的关系以及大数与小数及其右侧的关系
            if (numsShort[indexS] < numsLong[indexL])
            {
                // 短数较小，判断indexS是否还能加1，以及indexL是否还能减1
                if (indexS == numsShort.Length - 1 && indexL == 0)
                {
                    // 都不能，符合情况1
                    return (numsShort[indexS] + numsLong[indexL]) / 2.0;
                }
                else if (indexL == 0)
                {
                    // 小数有右侧数字，大数没有左侧数字
                    if (numsShort[indexS + 1] < numsLong[indexL])
                    {
                        // 情况3
                        return (numsShort[indexS] + numsShort[indexS + 1]) / 2.0;
                    }
                    else
                    {
                        // 情况1
                        return (numsShort[indexS] + numsLong[indexL]) / 2.0;
                    }
                }
                else if (indexS == numsShort.Length - 1)
                {
                    // 小数右侧没有数字，大数左侧有数字
                    if (numsShort[indexS] < numsLong[indexL - 1])
                    {
                        // 情况2
                        return (numsLong[indexL - 1] + numsLong[indexL]) / 2.0;
                    }
                    else
                    {
                        // 情况1
                        return (numsShort[indexS] + numsLong[indexL]) / 2.0;
                    }
                }
                else
                {
                    // 小数有右侧，大数有左侧，情况4
                    if (numsShort[indexS + 1] < numsLong[indexL])
                    {
                        if (numsShort[indexS] > numsLong[indexL - 1])
                        {
                            // 小数及其右侧被大数及其左侧包含，取小数及其右侧数字
                            return (numsShort[indexS] + numsShort[indexS + 1]) / 2.0;
                        }
                        else
                        {
                            // 交叉了，取小数的右侧与大数的左侧为中位数的两侧
                            return (numsShort[indexS + 1] + numsLong[indexL - 1]) / 2.0;
                        }
                    }
                    else if (numsShort[indexS] < numsLong[indexL - 1] )
                    {
                        if (numsShort[indexS + 1] > numsLong[indexL])
                        {
                            // 大数及其左侧被小数及其右侧包含，取大数及其左侧数字
                            return (numsLong[indexL - 1] + numsLong[indexL]) / 2.0;
                        }
                        else
                        {
                            // 交叉了，取小数的右侧与大数的左侧为中位数的两侧
                            return (numsShort[indexS + 1] + numsLong[indexL - 1]) / 2.0;
                        }
                    }
                    else
                    {
                        // 情况1
                        return (numsShort[indexS] + numsLong[indexL]) / 2.0;
                    }
                }
            }
            else if (numsShort[indexS] > numsLong[indexL])
            {
                // 短数较大，判断indexS是否还能减1，以及indexL是否还能加1
                if (indexS == 0 && indexL == numsLong.Length - 1)
                {
                    // 都不能，符合情况1
                    return (numsShort[indexS] + numsLong[indexL]) / 2.0;
                }
                else if (indexS == 0)
                {
                    // 小数有右侧数字，大数没有左侧数字
                    if (numsShort[indexS] > numsLong[indexL + 1])
                    {
                        // 情况3
                        return (numsLong[indexL] + numsLong[indexL + 1]) / 2.0;
                    }
                    else
                    {
                        // 情况1
                        return (numsShort[indexS] + numsLong[indexL]) / 2.0;
                    }
                }
                else if (indexL == numsLong.Length - 1)
                {
                    // 大数左侧有数字，小数没有右侧数字
                    if (numsShort[indexS-1] > numsLong[indexL])
                    {
                        // 情况2
                        return (numsShort[indexS - 1] + numsShort[indexS]) / 2.0;
                    }
                    else
                    {
                        // 情况1
                        return (numsShort[indexS] + numsLong[indexL]) / 2.0;
                    }
                }
                else
                {
                    // 小数有右侧，大数有左侧，情况4
                    if (numsShort[indexS - 1] > numsLong[indexL])
                    {
                        if (numsShort[indexS] < numsLong[indexL + 1])
                        {
                            // 大数及其左侧被小数及其右侧包含，取大数及其左侧数字
                            return (numsShort[indexS - 1] + numsShort[indexS]) / 2.0;
                        }
                        else
                        {
                            // 交叉了，取小数的右侧与大数的左侧为中位数的两侧
                            return (numsShort[indexS - 1] + numsLong[indexL + 1]) / 2.0;
                        }
                    }
                    else if (numsShort[indexS] > numsLong[indexL + 1])
                    {
                        if (numsShort[indexS-1] < numsLong[indexL])
                        {
                            // 小数及其右侧被大数及其左侧包含，取小数及其右侧数字
                            return (numsLong[indexL] + numsLong[indexL + 1]) / 2.0;
                        }
                        else
                        {
                            // 交叉了，取小数的右侧与大数的左侧为中位数的两侧
                            return (numsShort[indexS - 1] + numsLong[indexL + 1]) / 2.0;
                        }
                    }
                    else
                    {
                        // 情况1
                        return (numsShort[indexS] + numsLong[indexL]) / 2.0;
                    }
                }
            }
            else
            {
                // 两个相等，情况1，因为大数左侧不可能比小数大，小数右侧不可能比大数小
                return (numsShort[indexS] + numsLong[indexL]) / 2.0;
            }
        }
    }
}
```

最后这部分判断可以通过再定以一组变量使得代码量减少一半