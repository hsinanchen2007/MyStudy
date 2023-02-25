/*

https://leetcode.cn/problems/sort-transformed-array/

360. 有序转化数组
提示
中等
69
company
领英 LinkedIn

给你一个已经 排好序 的整数数组 nums 和整数 a 、 b 、 c 。对于数组中的每一个元素 nums[i] ，计算函数值 f(x) = ax2 + bx + c ，
请按升序返回数组 。

示例 1：

输入: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
输出: [3,9,15,33]

示例 2：

输入: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
输出: [-23,-5,1,7] 

提示：

1 <= nums.length <= 200
-100 <= nums[i], a, b, c <= 100
nums 按照 升序排列
 

进阶：你可以在时间复杂度为 O(n) 的情况下解决这个问题吗？

*/

class Solution100 {
public:
    // 2023.2.24, from https://github.com/grandyang/leetcode/issues/360
    /*
        这道题给了我们一个数组，又给了我们一个抛物线的三个系数，让我们求带入抛物线方程后求出的数组成的有序数组。那么我们首先来看
        O(nlgn)的解法，这个解法没啥可说的，就是每个算出来再排序，这里我们用了最小堆来帮助我们排序，参见代码如下：

        解法一：    
    */
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto d : nums) {
            q.push(a * d * d + b * d + c);
        }
        while (!q.empty()) {
            res.push_back(q.top()); q.pop();
        }
        return res;
    }
}; 


class Solution99 {
public:
    // 2023.2.24, from https://github.com/grandyang/leetcode/issues/360
    /*
        但是题目中的要求让我们在O(n)中实现，那么我们只能另辟蹊径。其实这道题用到了大量的高中所学的关于抛物线的数学知识，我们知道，
        对于一个方程f(x) = ax2 + bx + c 来说，如果a>0，则抛物线开口朝上，那么两端的值比中间的大，而如果a<0，则抛物线开口朝下，则
        两端的值比中间的小。而当a=0时，则为直线方法，是单调递增或递减的。那么我们可以利用这个性质来解题，题目中说明了给定数组nums
        是有序的，如果不是有序的，我想很难有O(n)的解法。正因为输入数组是有序的，我们可以根据a来分情况讨论：

        当a>0，说明两端的值比中间的值大，那么此时我们从结果res后往前填数，用两个指针分别指向nums数组的开头和结尾，指向的两个数就是
        抛物线两端的数，将它们之中较大的数先存入res的末尾，然后指针向中间移，重复比较过程，直到把res都填满。

        当a<0，说明两端的值比中间的小，那么我们从res的前面往后填，用两个指针分别指向nums数组的开头和结尾，指向的两个数就是抛物线两端
        的数，将它们之中较小的数先存入res的开头，然后指针向中间移，重复比较过程，直到把res都填满。

        当a=0，函数是单调递增或递减的，那么从前往后填和从后往前填都可以，我们可以将这种情况和a>0合并。

        解法二：    
    */
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size(), i = 0, j = n - 1;
        vector<int> res(n);
        int idx = a >= 0 ? n - 1 : 0;
        while (i <= j) {
            if (a >= 0) {
                res[idx--] = cal(nums[i], a, b, c) >= cal(nums[j], a, b, c) ? cal(nums[i++], a, b, c) : cal(nums[j--], a, b, c);
            } else {
                res[idx++] = cal(nums[i], a, b, c) >= cal(nums[j], a, b, c) ? cal(nums[j--], a, b, c) : cal(nums[i++], a, b, c);
            }
        }
        return res;
    }
    int cal(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
}; 


class Solution98 {
public:
    // 2023.2.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/sort-transformed-array.cpp
    // Time:  O(n)
    // Space: O(1)
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        const auto f = [](int x, int a, int b, int c) {
            return a * x * x + b * x + c;
        };

        vector<int> result;
        if (nums.empty()) {
            return result;
        }

        int left = 0, right = nums.size() - 1;
        int d = a > 0 ? -1 : 1;
        while (left <= right) {
            if (d * f(nums[left], a, b, c) < d * f(nums[right], a, b, c)) {
                result.emplace_back(f(nums[left++], a, b, c));
            } else {
                result.emplace_back(f(nums[right--], a, b, c));
            }
        }
        if (d == -1) {
            reverse(result.begin(), result.end());
        }

        return result;
    }
};


class Solution97 {
private:
    int eval(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
public:
    // OJ: https://leetcode.com/problems/sort-transformed-array/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        float mid = (float)-b / (2 * a);
        int j = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
        int i = j - 1, N = nums.size(), nil = a > 0 ? INT_MAX : INT_MIN;
        vector<int> ans(N);
        for (int k = 0; k < N; ++k) {
            int m = i >= 0 ? eval(nums[i], a, b, c) : nil;
            int n = j < N ? eval(nums[j], a, b, c) : nil;
            if (a > 0 ? m < n : n < m) {
                ans[k] = m;
                --i;
            } else {
                ans[k] = n;
                ++j;
            }
        }
        if (a < 0) reverse(ans.begin(), ans.end());
        return ans;
    }
};


class Solution96 {
public:
    // 2023.2.24, from https://walkccc.me/LeetCode/problems/0360/
    // Time: O(N)
    // Space: O(1)
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        const int n = nums.size();
        const bool upward = a > 0;
        vector<int> ans(n);
        vector<int> quad;

        for (const int num : nums)
        quad.push_back(f(num, a, b, c));

        int i = upward ? n - 1 : 0;
        for (int l = 0, r = n - 1; l <= r;)
        if (upward)  // Maximum in both ends
            ans[i--] = quad[l] > quad[r] ? quad[l++] : quad[r--];
        else  // Minimum in both ends
            ans[i++] = quad[l] < quad[r] ? quad[l++] : quad[r--];

        return ans;
    }

private:
    // The concavity of f only depends on a's sign
    int f(int x, int a, int b, int c) {
        return (a * x + b) * x + c;
    }
};


class Solution95 {
public:
    // 2023.2.24, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/360.Sort-Transformed-Array/360.Sort%20Transformed%20Array.cpp
    /*
        360.Sort-Transformed-Array
        注意a等于零和正负情况，会影响结果。如果a==0时，函数结果本身就是单调的，但要根据b是否大于0来改变顺序。

        当a不等于零时，设置左右两个指针，可以根据nums[left]、num[right]离中轴线(-b/2a)的距离来移动较远的那个指针，特别注意细节，
        不是比较left/right和中轴线的距离。令两个指针不断靠近，直至left==right.

        也可以直接用比较两个指针对应的func[i]的大小来移动指针。当a>0时，优先移动二者之间较大的，最后结果反序；当a<0时，优先移动
        二者之间较小的。    
    */
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) 
    {
        vector<int>result;
        
        if (a==0)
        {
            for (int i=0; i<nums.size(); i++)
                result.push_back(b*nums[i]+c);
            if (b<0)
                reverse(result.begin(),result.end());
        }
        else 
        {
            int flag = (a>0);
            float mid=-b/2.0/a;
            
            int left=0;
            int right=nums.size()-1;
            while (left<=right)
            {
                if (abs(mid-nums[left])>abs(mid-nums[right]))
                {
                    result.push_back(a*nums[left]*nums[left]+b*nums[left]+c);
                    left++;
                }
                else
                {
                    result.push_back(a*nums[right]*nums[right]+b*nums[right]+c);
                    right--;
                }                
            }            
            if (flag==1) reverse(result.begin(),result.end());            
        }        
        return result;        
    }
};


class Solution {
public:
    // 作者：xzp
    // 链接：https://leetcode.cn/leetbook/read/sliding-window-and-two-pointers/rwpvnv/?discussion=L1Z52N
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> ans(n , 0);
        int leftval = 0 , rightval = 0 , left = 0 , right = n - 1;
        if(a > 0){
            for(int i = 0 ; i < n ; i++){
                leftval = leftval = fx(nums[left] , a , b , c);
                rightval = fx(nums[right] , a , b , c);
                if(leftval < rightval) {
                    ans[n - i - 1] = rightval;
                    right--;
                }
                else{
                    ans[n - i - 1] = leftval;
                    left++;
                }
            }
        }
        else{
            for(int i = 0 ; i < n ; i++){
                leftval = leftval = fx(nums[left] , a , b , c);
                rightval = fx(nums[right] , a , b , c);
                if(leftval < rightval) {
                    ans[i] = leftval;
                    left++;
                }
                else{
                    ans[i] = rightval;
                    right--;
                }
            }
        }
        return ans;
    }

    int fx(int x , int a , int b , int c){
        return a * x * x + b * x + c;
    }
};

