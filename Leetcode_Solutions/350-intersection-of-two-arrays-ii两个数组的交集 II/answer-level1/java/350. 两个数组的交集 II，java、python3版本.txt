# 基本思路
1. 先找出更短的list，如果遇到第二个list特别长，甚至不能一次读入内存的情况下更好应用；
2. for循环长list中每一个元素，如果在短list中找到，则pop出去，形成新的数组，即我们需求的；
3. 如果短list没有任何元素了，则直接返回pop的list。

假设m为长list长度，n为短list长度，时间复杂度为O(m*n)，空间复杂度为O(1)
# 哈希表思路
获得短list后，将短list转化为map，这样将每次寻找短list内相同元素的时间省去了。


时间复杂度为O(m)，空间复杂度为O(n)。


# 优化思路
如果考虑到排序，则可以先将两个list进行排序后再进行计算，会节省一些时间。


# java代码，哈希表版本

```
package T350两个数组的交集2;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Solution {

    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> integerList = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        int []more;
        int []less;
//        保证数组less是数据更少的，作为基准数据
        if (nums1.length > nums2.length) {
            more = nums1;
            less = nums2;
        } else {
            more =nums2;
            less = nums1;
        }

        for (int i : less) {
            if (map.containsKey(i)) {
                map.put(i, map.get(i) + 1);
            } else {
                map.put(i, 1);
            }
        }

        for (int i : more) {
            if (!map.isEmpty() && map.containsKey(i)) {
                integerList.add(i);
                map.put(i, map.get(i) - 1);
                if (map.get(i) == 0) {
                    map.remove(i);
                }
            }
        }

        int[] result = new int[integerList.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = integerList.get(i);
        }

        return result;

    }



    public static void main(String args[]) {
        Solution s = new Solution();
        int[] nums1 = {1, 2, 2, 3, 3};
        int[] nums2 = {2, 2, 1, 4, 5};

        int[] nums3 = s.intersect(nums1, nums2);
        for (int i : nums3) {
            System.out.println(i);
        }
    }
}

```

# python代码，list、哈希表版本
```
class Solution:
    def intersect2(self, nums1, nums2):
        # 保证nums1是最短的，否则交换
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        same_list = list()
        for i in nums2:
            if len(nums1) > 0 and i in nums1:
                # 将i进行pop（index只会找到第一个数字为i的下标）
                same_list.append(nums1.pop(nums1.index(i)))
        return same_list

    def intersect(self,nums1,nums2):
        # 保证nums1是最短的，否则交换
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        # 将list数据存入dict，空间换时间
        nums1_d = dict()
        for i in nums1:
            if nums1_d.get(i) is None:
                nums1_d[i] = 1
            else:
                nums1_d[i] += 1

        same_list = list()

        for i in nums2:
            if len(nums1_d) is not 0 and nums1_d.get(i) is not None:
                same_list.append(i)
                nums1_d[i] -= 1
                if nums1_d[i] == 0:
                    nums1_d.pop(i)
        return same_list

if __name__ == '__main__':
    s = Solution()
    nums1 = [1, 2, 3]
    nums2 = [2, 3, 4]
    a = s.intersect2(nums1, nums2)



```