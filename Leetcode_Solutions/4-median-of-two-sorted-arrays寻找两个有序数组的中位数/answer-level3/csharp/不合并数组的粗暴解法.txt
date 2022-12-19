### 解题思路
因为是有序数组，遍历到中位数，比对两数组中对应位置的大小取值；
![微信图片_20200324121313.png](https://pic.leetcode-cn.com/e12699574bf95bb4cedbb254cfeb55e5ce4d7fd0bde6553d7633a61650a31209-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200324121313.png)

### 代码

```csharp
public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {

        var n1 = nums1.Length;
        var n2 = nums2.Length;

        var v1 = (n1 + n2) % 2;//判断奇数位还是偶数位
        var v2 = (n1 + n2) / 2 + 1;//两数组总长，需要遍历数据的最多次数

        int result = 0;
        int result2 = 0;
        int i1 = 0;//数组1角标
        int i2 = 0;//数组2角标
        for (int i = 0; i < v2; i++)
        {
            var r1 = 0;//对应位数组1值
            var r2 = 0;//对应位数组2值

            bool isTrue = false;//当前位置是否取数组1的值

            if (n1 > i1)
            {
                r1 = nums1[i1];
                isTrue = true;
            }
            if (n2 > i2)
            {
                r2 = nums2[i2];
            }
            else//当前位置数组2没值，取数组1
                isTrue = true;

            if (n1 > i1 && n2 > i2)//数组1和2都有值，取对应位数值小的数组值
            {
                if (r1 <= r2)
                    isTrue = true;
                else
                    isTrue = false;
            }

            if (isTrue)
            {
                if (v1.Equals(1))
                {
                    if (i.Equals(v2 - 1))//数组长度奇数时，只取最后一位数
                    {
                        result = r1;
                        break;
                    }
                }
                else//数组长度奇数时，只取一位数
                {
                    if (i == v2 - 2)
                    {
                        result = r1;
                    }
                    else if (i == v2 - 1)
                    {
                        result2 = r1;
                    }
                }

                i1++;
            }
            else
            {
                if (v1.Equals(1))
                {
                    if (i.Equals(v2 - 1))
                    {
                        result = r2;
                        break;
                    }
                }
                else
                {
                    if (i == v2 - 2)
                    {
                        result = r2;
                    }
                    else if (i == v2 - 1)
                    {
                        result2 = r2;
                    }
                }

                i2++;
            }

        }


        if (v1.Equals(1))
            return result;
        else
            return (result + result2) / Convert.ToDouble(2);
    }
}
```