### 解题思路
当合并两个数组时，不需要对所有的元素归并，只需要对中间的部分进行归并,然后搬运回原数组即可

例如，1 1 2 **4 6** 与 **3 5** 7 8 9 的归并，只需要归并其中的**黑体部分**即可，其他部分放在原来的数组中不动就行。

![执行时间](https://pic.leetcode-cn.com/4de51253374af4a949e6db7c718560bf634596f7d434c267dca2cb1821e1d89d-%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_%E9%80%89%E6%8B%A9%E5%8C%BA%E5%9F%9F_20200101115015.png)

### 代码

```cpp
class Solution {
public:
    int mergeSort(vector<int>& arr1, vector<int>& arr2, int l, int r, bool top)
    {
        if(l == r) return 0;
        int m = (l + r) / 2;
        int sum = mergeSort(arr1,arr2,l,m,false) + mergeSort(arr1,arr2,m + 1,r,false);
        // 首先统计反转对数 [l~m] [m + 1 ~ r]
        // 在归并排序时, 所有"重要翻转对"右侧的数都会浮到左侧来,
        // 因此计算在上浮的过程中遇到的满足"重要翻转对"条件的个数即可。
        // 由于数据是有序的, 当左侧一个数据 > 2*右侧数据, 则后面的都大
        for(int i = l, j = m + 1; i <= m && j <= r;)
        {
            long long s = arr1[i], t = arr1[j]; t = 2*t;
            if(s <= t) ++i;
            else { ++j;  sum += m - i + 1; }
        }
        // 在顶层时, 再进行排序就没必要了
        if(top) return sum;
        if(arr1[m] <= arr1[m + 1]) return sum;
        // 然后进行排序 [l~m] [m + 1 ~ r]
        int i,ls = l, j = m + 1, k;
        while (ls <= m && arr1[ls] <= arr1[j]) ++ls; k = i = ls;
        while(i <= m && j <= r)
        {
            if(arr1[i] <= arr1[j]) arr2[k++] = arr1[i++];
            else arr2[k++] = arr1[j++];
        }
        while(i <= m) arr2[k++] = arr1[i++];
        // 搬运回去
        for(int x = ls; x < j; ++x)
            arr1[x] = arr2[x];
        return sum;
    }

    int reversePairs(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        vector<int> arr2(nums.size(),0);
        return mergeSort(nums,arr2,0,nums.size() - 1,true);
    }
};
```