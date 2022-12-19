### 解法简介
相信大家已经知道了这题二分解法的思路了，但是这题的难点在于边界条件的处理，虽然知道原理却很难写对。
这里我翻阅了前几页的二分解法，大体上都是思路容易看懂，但是自己写却很难写对的题解。我觉得可能需要一个更容易写对的答案。
解法上和[@varyshare](/u/varyshare/)的一样。
dalao的解法链接：[从发明的角度看高效易懂题解：寻找两个有序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/cong-fa-ming-de-jiao-du-kan-gao-xiao-yi-dong-ti-ji/)
通过不断排除掉一段等于$\frac{k}{2}$的区间，达到二分查找的目的。
其中:
*唯一的判断标准就是“较小的那段一定是属于合并后数组中前k小”*
当然，dalao也给了一个很好的解法，然而本菜鸡还是觉得自己的实现更加简单易懂一点，当然可能时间常数上不占优势，但是渐进复杂度绝对是一样的。

### 解法详解
$dfs$的两个变量$i$，$j$分别代表$nums1$，$nums2$数组的起始位置，这个函数的返回值为$nums1[i:...]$子数组和$nums2[j:...]$子数组合并之后的第$k$个值。
1. 边界条件处理，当一个数组为空时，直接返回另一个数组的第k个数字
2. 当$k=1$时，返回两个数组开头元素中的较小值
3. 如果某个数组中所有元素都不够$\frac{k}{2}$个，那么排除掉的一定是另一个数组中的$\frac{k}{2}$个元素
4. 比较两数组中的第$\frac{k}{2}$个元素，排除掉小的那个

因为每次$k$减少$\frac{k}{2}$，所以最后是$log(n+m)$的时间复杂度。

```
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        function<int(int,int,int)> dfs = [&] (int i, int j, int k) {
            if(i==n) return nums2[j+k-1];
            if(j==m) return nums1[i+k-1];
            if(k==1) return min(nums1[i],nums2[j]);
            if(i+k/2-1 >= n) return dfs(i,j+k/2,k-k/2);
            if(j+k/2-1 >= m) return dfs(i+k/2,j,k-k/2);
            if(nums1[i+k/2-1] < nums2[j+k/2-1]) return dfs(i+k/2,j,k-k/2);
            else return dfs(i,j+k/2,k-k/2);
        };
        if((n+m)&1) return dfs(0,0,(n+m+1)/2);
        return 0.5*(dfs(0,0,(n+m)/2) + dfs(0,0,(n+m)/2+1));
    }
};
```