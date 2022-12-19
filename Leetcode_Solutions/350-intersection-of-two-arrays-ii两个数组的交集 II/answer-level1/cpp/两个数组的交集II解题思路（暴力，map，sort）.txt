[题目描述](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/submissions/)
给定两个数组，编写一个函数来计算它们的交集。

>示例 1:
输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:
输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：
输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
进阶:
如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

思路解析：
这个题拿到之后，想到的第一个方法就是暴力破解，然后进行改进，有下面的三个方法：

#### 1. 暴力破解
这个应该是容易想到的，虽然一般不太很想用暴力方法解决问题，但是这个一时间没有想到好的，用暴力试了试，A了， 暴力的思路就是从数组短的开始遍历作为外循环，数组长的作为内循环找是否等于外面的，如果等于，加入最后的结果，然后把这两个数都置为不常见的数（这一步很关键）。这样，遍历完短的，就出答案。

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int lennum1 = nums1.size();
        int lennum2 = nums2.size();

        vector<int> res;

        if (lennum1 > lennum2)         // nums2短
        {
            for (int i=0; i<lennum2; i++)
            {
                for (int j=0; j<lennum1; j++)
                {
                    if (nums2[i] == nums1[j])
                    {
                        res.push_back(nums2[i]);
                        nums1[j] = -999999;
                        nums2[i] = -9999;
                    }
                }
            }
        }
        else
        {
            for (int i=0; i<lennum1; i++)
            {
                for (int j=0; j<lennum2; j++)
                {
                    if (nums1[i] == nums2[j])
                    {
                        res.push_back(nums1[i]);
                        nums2[j] = -99999;
                        nums1[i] = -9999;
                    }
                }
            }
        }

        return res;
    }
};

```
这个方法时间复杂度还是很高的，没有任何的优化。

#### 2. map哈希表
此题可以看成是一道传统的映射题（map映射），为什么可以这样看呢？因为我们需找出两个数组的交集元素，同时应与两个数组中出现的次数一致。
这样就导致了我们需要知道每个值出现的次数，所以映射关系就成了<元素,出现次数>,所以我们可以首先统计数组1中所有元素的出现次数。
然后再遍历数组2，如果数组2中的元素在map中存在（出现次数大于0），该元素就是一个交集元素，我们就将其存入返回数组中并且将map中该元素的出现次数减一即可.

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int lennum1 = nums1.size();
        int lennum2 = nums2.size();

        vector<int> res;

        map<int, int> m;
        if (lennum1 > lennum2)         // nums2短
        {
            for (int i=0; i<lennum2; i++)
            {
                m[nums2[i]]++;
            }

            for (int i=0; i<lennum1; i++)
            {
                if (m[nums1[i]] > 0)
                {
                    res.push_back(nums1[i]);
                    m[nums1[i]]--;
                }
            }
        }
        else
        {
            for (int i=0; i<lennum1; i++)
            {
                m[nums1[i]]++;
            }
            for (int i=0; i<lennum2; i++)
            {
                if (m[nums2[i]] > 0)
                {
                    res.push_back(nums2[i]);
                    m[nums2[i]]--;
                }
            }
        }

        return res;
    }
};
```
代码其实不长，我只不过是判断了一下哪个比较短，这个相对来说比暴力好了很多，毕竟map查找经过了优化。并且map神奇好用到哭。

#### 3. 先排序，然后查找
这个思路就是首先将两个数组排序，然后从前往后找，如果相等，加入最后结果，如果是a数组比b数组当前元素大，b元素指针后移，否则a元素指针后移，这样遍历完那个短的，就得到答案，感觉是目前发现的最好的方式。

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int lennum1 = nums1.size();
        int lennum2 = nums2.size();

        // 先排序
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;

        int i=0, j=0;

        while (i<lennum1 && j<lennum2)
        {
            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }

            else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }

        return res;
    }
};
```

