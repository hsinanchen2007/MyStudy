/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

/*

https://leetcode.cn/problems/container-with-most-water/

11. 盛最多水的容器

提示
中等
4.1K
company
亚马逊
company
字节跳动
company
谷歌 Google

给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。

示例 1：

输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例 2：

输入：height = [1,1]
输出：1 

提示：

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.22, from https://www.acwing.com/solution/content/100/
    // 作者：yxc
    // 链接：https://www.acwing.com/solution/content/100/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。    
    /*
        算法
        (指针扫描) O(n)

        这题的思路比较精巧，我们先给出做法，再给出证明。

        做法：用两个指针 i,j,分别指向首尾，如果 ai>aj，则 j−−；否则 i++，直到 i=j 为止，每次迭代更新最大值。
        证明：假设最优解对应的两条线的下标是 i′,j′(i′<j′)，在 i,j不断靠近的过程中，不妨假设 i先走到 i′，则此时有 j′<j
        。反证，如果此时 ai≤aj，设 S表示 i,j能盛多少水,

        则：S=min(ai,aj)∗(j−i)
            =ai∗(j−i)
            >ai∗(j′−i)
            ≥min(ai,aj′)∗(j′−i)=S′

        与 S′是最优解矛盾，因此 ai>aj，所以 j会一直走到 j′，从而得到最优解。

        时间复杂度分析：两个指针总共扫描 n次，因此总时间复杂度是 O(n)
    */
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0, j = height.size() - 1; i < j; )
        {
            res = max(res, 
                min(height[i], height[j]) * (j - i));
            if (height[i] > height[j]) j -- ;
            else i ++ ;
        }
        return res;
    }
};


class Solution99 {
public:
    // 2023.2.22, from https://walkccc.me/LeetCode/problems/0011/
    // Time: O(1)
    // Space: O(1)
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;

        while (l < r) {
            const int minHeight = min(height[l], height[r]);
            ans = max(ans, minHeight * (r - l));
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }

        return ans;
    }
};


class Solution98 {
public:
    // OJ: https://leetcode.com/problems/container-with-most-water/
    // Author: github.com/lzl124631x
    // Time: O(N^2)
    // Space: O(1)
    // Solution 1. Brute Force
    int maxArea(vector<int>& A) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            if (!A[i]) continue;
            for (int j = i + 1 + ans / A[i]; j < N; ++j) {
                ans = max(ans, min(A[i], A[j]) * (j - i));
            }
        }
        return ans;
    }
};


class Solution97 {
public:
    // OJ: https://leetcode.com/problems/container-with-most-water/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Ref: https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm
    // Solution 2. Two Pointers
    /*
        Keep two pointers L = 0, R = N - 1 and move them inwards. They form two edges of the container and the 
        volumn is (R - L) * min(A[L], A[R]).

        We start from the container with the maximum width. Now we need to decrease the width and try to increase 
        the height if possible (compromising on width and looking forward to greater height).

        The strategy of moving the pointers is that we always move the smaller edge inwards.

        Reason: Assume A[L] > A[R], then all the pairs of A[R] with A[i] (L < i < R) can be discarded because the 
        width between A[i] and A[R] is less AND the height of the container won't be taller than A[R].

        Thus, to discardi all the pairs of A[R] with A[i] (L < i < R), we can simply --R.

        If the height of the two edges are the same, moving either one is fine because the change won't increase 
        the volumn either way. BUT, we shouldn't break here because the volumn might increase later. Example case [1, 100, 200, 1].    
    */
    int maxArea(vector<int>& A) {
        int ans = 0, L = 0, R = A.size() - 1;
        while (L < R) {
            ans = max(ans, (R - L) * min(A[L], A[R]));
            if (A[L] < A[R]) ++L; // Move the smaller edge
            else --R;
        }
        return ans;
    }
};


class Solution96 {
public:
    // 2023.2.22, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/container-with-most-water.cpp
    // Time:  O(n)
    // Space: O(1)
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, max_area = 0;
        while (i < j) {
            max_area = max(max_area, min(height[i], height[j]) * (j - i));
            if (height[i] > height[j]) {
                --j;
            } else if (height[i] < height[j]) {
                ++i;
            } else {  // height[i] == height[j].
                ++i, --j;
            }
        }
        return max_area;
    }
};


class Solution95 {
public:
    // 2023.2.22, from https://github.com/grandyang/leetcode/issues/11
    /*
        这道求装最多水的容器的题和那道 Trapping Rain Water 很类似，但又有些不同，那道题让求整个能收集雨水的量，这道只是让求最大
        的一个的装水量，而且还有一点不同的是，那道题容器边缘不能算在里面，而这道题却可以算，相比较来说还是这道题容易一些，这里需要
        定义i和j两个指针分别指向数组的左右两端，然后两个指针向中间搜索，每移动一次算一个值和结果比较取较大的，容器装水量的算法是
        找出左右两个边缘中较小的那个乘以两边缘的距离，代码如下：    
    */
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? ++i : --j;
        }
        return res;
    }
};


class Solution94 {
public:
    // 2023.2.22, from https://github.com/grandyang/leetcode/issues/11
    /*
        这里需要注意的是，由于 Java 中的三元运算符 A?B:C 必须须要有返回值，所以只能用 if..else.. 来替换，不知道 Java 对于三元运算符
        这么严格的限制的原因是什么。

        下面这种方法是对上面的方法进行了小幅度的优化，对于相同的高度们直接移动i和j就行了，不再进行计算容量了，参见代码如下：    
    */
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            while (i < j && h == height[i]) ++i;
            while (i < j && h == height[j]) --j;
        }
        return res;
    }
};


class Solution93 {
public:
    // 2023.2.22, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/011.Container-With-Most-Water/11-Container-With-Most-Water.cpp
    /*
        11. Container With Most Water
        算法：双指针。  
        让左指针指向0，右指针指向height.size()-1。每次考虑如果减少横向距离1，判断应该选择移左指针还是右指针，还是考察both？  

        事实上，只需要移动height[left]和height[right]中较矮的一个板子即可，这样才有使总面积增大的可能。否则移动较高的板子，
        不会使结果变得更好，因为面积受限于较矮的那块板子。

        if (height[left]>=height[right])
            right--;
        else
            left++;    
    */
    int maxArea(vector<int>& height) 
    {
        int left=0;
        int right=height.size()-1;
        
        int temp=0;
        int result=0;
        
        while (left<right)
        {
            int temp = (right-left)*min(height[left],height[right]);
            if (temp>result) result=temp;
            
            if (height[left]>=height[right])
                right--;
            else
                left++;
        }
        
        return result;
        
    }
};


class Solution92 {
public:
    // 2023.2.22, from https://zxi.mytechroad.com/blog/?s=LeetCode+11.
    // Author: Huahua
    // Runtime: 19 ms
    int maxArea(const vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            int h = min(height[l], height[r]);
            ans = max(ans, h * (r - l));
            if (height[l] < height[r]) 
                ++l;
            else
                --r;
        }
        return ans;
    }
};


class Solution {
public:
    // 作者：xzp
    // 链接：https://leetcode.cn/leetbook/read/sliding-window-and-two-pointers/od6y65/?discussion=jv1Cr0
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0 , right = n - 1 , res = 0;
        if(n < 2) return 0;
        while(left < right){
            int area = min(height[left] , height[right]) * (right - left);
            if(height[left] <= height[right]) left++;
            else right--;
            res = max(res , area);
        }
        return res;
    }
};


// @lc code=end

