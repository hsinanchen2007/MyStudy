复杂度应该是O(m+n),这个可能与题目稍微有些不符合。
思路：
洋葱大家肯定都见过，把它的外衣一层一层剥开，就可以越来越靠近它的中心。（到这里相信很多大神已经知道怎么回事了）

没错，如果是一个排好序数组，那我们可以每次头尾各砍掉一个，最后剩下的一个或者两个数的均值，就是中位数了。
那么两个数组起也是一样，举个例子：
有这样一组数据
![0001.png](https://pic.leetcode-cn.com/3f2a75beb018d9c11caed10cb55bd95ea15b855cd4219ed6cdfc33b13f716b83-0001.png)

那么从两边开始剥，过程是这样的：
-> 砍掉1和13
![0002.png](https://pic.leetcode-cn.com/a327f5712661c3d25a76031d8cb725ca41357dd91ac8489837e16e20f544a8f5-0002.png)
-> 砍掉2和12
![0003.png](https://pic.leetcode-cn.com/4da3a73d2fb8b039a258aa09296c7e11186bb27469ee611908e6137801256bf9-0003.png)
-> 砍掉3和10
![0004.png](https://pic.leetcode-cn.com/ac6eaab014b1e947292407f403a4bceb4581b688d610b5a641ba0cf31c228ba4-0004.png)
-> 砍掉6和9
![0005.png](https://pic.leetcode-cn.com/a04333b44e6b9478efa0bc8e765286292e7658a69e50189beb9cc4633e5f369e-0005.png)

当然如果是数组长度是偶数，最后会剩下两个数字，那么这两个数字的均值就是我们要找的中位数了。
我的代码写得比较烂，但也贴上来,欢迎给我优化建议。
```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_size = nums1.size() + nums2.size();
        
        vector<int>::iterator it1 = nums1.begin();
        nums1.insert(it1, INT_MIN);
        nums1.push_back(INT_MAX);
        vector<int>::iterator it2 = nums2.begin();
        nums2.insert(it2, INT_MIN);
        nums2.push_back(INT_MAX);
        
        int n1_l=1,n1_r=nums1.size()-2;
        int n2_l=1,n2_r=nums2.size()-2;
        
        int times = (total_size - 1 ) / 2;
        for(int i=0; i<times; i++)
        {
            if(nums1[n1_l] <= nums2[n2_l] && n1_r >= n1_l)
            {
                n1_l ++;
            }
            else
            {
                n2_l ++;
            }
            if(nums1[n1_r] >= nums2[n2_r] && n1_r >= n1_l)
            {
                n1_r --;
            }
            else
            {
                n2_r --;
            }
        }
        
        double median = 0;
        double nums = (n1_r - n1_l)+(n2_r-n2_l) +2.0;
        if(n1_r >= n1_l)
        {
            for(int i=0; i<n1_r-n1_l+1; i++)
                median+=(nums1[i+n1_l] / nums);
        }
        if(n2_r >= n2_l)
        {
            for(int i=0; i<n2_r-n2_l+1; i++)
                median+=(nums2[i+n2_l]/nums);
        }
        return median;
    }
};
```





