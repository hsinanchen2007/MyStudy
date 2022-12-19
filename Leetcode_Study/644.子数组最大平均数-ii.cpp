/*

https://leetcode.cn/problems/maximum-average-subarray-ii/

644. 子数组最大平均数 II
给你一个包含 n 个整数的数组 nums ，和一个整数 k 。

请你找出 长度大于等于 k 且含最大平均值的连续子数组。并输出这个最大平均值。任何计算误差小于 10-5 的结果
都将被视为正确答案。


示例 1：

输入：nums = [1,12,-5,-6,50,3], k = 4
输出：12.75000
解释：
- 当长度为 4 的时候，连续子数组平均值分别为 [0.5, 12.75, 10.5] ，其中最大平均值是 12.75 。
- 当长度为 5 的时候，连续子数组平均值分别为 [10.4, 10.8] ，其中最大平均值是 10.8 。
- 当长度为 6 的时候，连续子数组平均值分别为 [9.16667] ，其中最大平均值是 9.16667 。
当取长度为 4 的子数组（即，子数组 [12, -5, -6, 50]）的时候，可以得到最大的连续子数组平均值 12.75 ，所以返回 12.75 。
根据题目要求，无需考虑长度小于 4 的子数组。

示例 2：

输入：nums = [5], k = 1
输出：5.00000
 

提示：

n == nums.length
1 <= k <= n <= 104
-104 <= nums[i] <= 104
通过次数1,829提交次数4,214

*/

class Solution100 {
public:
    // 2022.8.13, from https://github.com/grandyang/leetcode/issues/644
    /*
        这道题是之前那道 Maximum Average Subarray I 的拓展，那道题说是要找长度为k的子数组的最大平均值，而这道题
        要找长度大于等于k的子数组的最大平均值。加了个大于k的条件，情况就复杂很多了，之前只要遍历所有长度为k的子数组就
        行了，现在还要包括所有长度大于k的子数组。我们首先来看 brute force 的方法，就是遍历所有的长度大于等于k的子数组
        ，并计算平均值并更新结 果res。那么先建立累加和数组 sums，结果 res 初始化为前k个数字的平均值，然后让i从 k+1 
        个数字开始遍历，此时的 sums[i] 就是前 k+1 个数组组成的子数组之和，我们用其平均数来更新结果 res，然后从开头
        开始去掉数字，直到子数组剩余k个数字为止，再用其平均值来更新解结果 res，通过这种方法，我们就遍历了所有长度大于
        等于k的子数组。这里需要注意的一点是，更新结果 res 的步骤不能写成 res = min(res, t / (i + 1)) 这种形式，
        会 TLE，必须要在if中判断 t > res * (i + 1) 才能 accept，写成 t / (i + 1) > res 也不行，必须要用乘法，
        这也说明了计算机不喜欢算除法吧，参见代码如下：
    */
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums = nums;
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        double res = (double)sums[k - 1] / k;
        for (int i = k; i < n; ++i) {
            double t = sums[i];
            if (t > res * (i + 1)) res = t / (i + 1);
            for (int j = i - k; j >= 0; --j) {
                t = sums[i] -  sums[j];
                if (t > res * (i - j)) res = t / (i - j);
            }
        }
        return res;
    }
};


class Solution99 {
public:
    // 2022.8.13, from https://github.com/grandyang/leetcode/issues/644
    /*
        我们再来看一种 O(n2) 时间复杂度的方法，这里对上面的解法进行了空间上的优化，并没有长度为n数组，而是使用了 
        preSum 和 sum 两个变量来代替，preSum 初始化为前k个数字之和，sum 初始化为 preSum，结果 res 初始化为
        前k个数字的平均值，然后从第 k+1 个数字开始遍历，首先 preSum 加上这个数字，sum 更新为 preSum，然后用
        当前 k+1 个数字的平均值来更新结果 res。和上面的方法一样，我们还是要从开头开始去掉数字，直到子数组剩余k个
        数字为止，然后用其平均值来更新解结果 res，那么每次就用 sum 减去 nums[j]，就可以不断的缩小子数组的长度了，
        用当前平均值更新结果 res，注意还是要用乘法来判断大小，参见代码如下：
    */
    double findMaxAverage(vector<int>& nums, int k) {
        double preSum = accumulate(nums.begin(), nums.begin() + k, 0);
        double sum = preSum, res = preSum / k;
        for (int i = k; i < nums.size(); ++i) {
            preSum += nums[i];
            sum = preSum;
            if (sum > res * (i + 1)) res = sum / (i + 1);
            for (int j = 0; j <= i - k; ++j) {
                sum -= nums[j];
                if (sum > res * (i - j)) res = sum / (i - j);
            }
        }
        return res;
    }
};


class Solution98 {
public:
    // 2022.8.13, from https://github.com/grandyang/leetcode/issues/644
    /*
        下面来看一种优化时间复杂度到 O(nlg(max - min)) 的解法，其中 max 和 min 分别是数组中的最大值和最小值，
        是利用了二分搜索法，博主之前写了一篇 LeetCode Binary Search Summary 二分搜索法小结 的博客，这里的二分法
        应该是小结的第四类，也是最难的那一类，因为判断折半的方向是一个子函数，这里我们没有用子函数，而是写到了一起，
        可以抽出来成为一个子函数，这一类的特点就是不再是简单的大小比较，而是需要一些复杂的操作来确定折半方向。
        这里主要借鉴了蔡文森特大神的帖子，所求的最大平均值一定是介于原数组的最大值和最小值之间，所以我们的目标是用
        二分法来快速的在这个范围内找到要求的最大平均值，初始化 left 为原数组的最小值，right 为原数组的最大值，
        然后 mid 就是 left 和 right 的中间值，难点就在于如何得到 mid 和要求的最大平均值之间的大小关系，从而判断
        折半方向。我们想，如果已经算出来了这个最大平均值 maxAvg，那么对于任意一个长度大于等于k的数组，如果让每个数字
        都减去 maxAvg，那么得到的累加差值一定是小于等于0的，这个不难理解，比如下面这个数组：

        [1, 2, 3, 4]   k = 2

        我们一眼就可以看出来最大平均值 maxAvg = 3.5，所以任何一个长度大于等于2的子数组每个数字都减去 maxAvg 的差值
        累加起来都小于等于0，只有产生这个最大平均值的子数组 [3, 4]，算出来才正好等于0，其他都是小于0的。那么可以根据
        这个特点来确定折半方向，我们通过 left 和 right 值算出来的 mid，可以看作是 maxAvg 的一个 candidate，所以
        就让数组中的每一个数字都减去 mid，然后算差值的累加和，一旦发现累加和大于0了，那么说明 mid 比 maxAvg 小，这样
        就可以判断方向了。

        我们建立一个累加和数组 sums，然后求出原数组中最小值赋给 left，最大值赋给 right，题目中说了误差是 1e-5，所以
        循环条件就是 right 比 left 大 1e-5，然后算出来 mid，定义一个 minSum 初始化为0，布尔型变量 check，初始化为 
        false。然后开始遍历数组，先更新累加和数组 sums，注意这个累加和数组不是原始数字的累加，而是它们和 mid 相减的
        差值累加。我们的目标是找长度大于等于k的子数组的平均值大于 mid，由于每个数组都减去了 mid，那么就转换为找长度大于
        等于k的子数组的差累积值大于0。建立差值累加数组的意义就在于通过 sums[i] - sums[j] 来快速算出j和i位置中间数字
        之和，那么只要j和i中间正好差k个数字即可，然后 minSum 就是用来保存j位置之前的子数组差累积的最小值，所以当 i >= k 
        时，我们用 sums[i - k] 来更新 minSum，这里的 i - k 就是j的位置，然后判断如果 sums[i] - minSum > 0了，
        说明找到了一段长度大于等k的子数组平均值大于 mid 了，就可以更新 left 为 mid 了，我们标记 check 为 true，并
        退出循环。在 for 循环外面，当 check 为 true 的时候，left 更新为 mid，否则 right 更新为 mid，参见代码如下：
    */
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> sums(n + 1, 0);
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (right - left > 1e-5) {
            double minSum = 0, mid = left + (right - left) / 2;
            bool check = false;
            for (int i = 1; i <= n; ++i) {
                sums[i] = sums[i - 1] + nums[i - 1] - mid;
                if (i >= k) {
                    minSum = min(minSum, sums[i - k]);
                }
                if (i >= k && sums[i] > minSum) {check = true; break;} 
            }
            if (check) left = mid;
            else right = mid;
        }
        return left;
    }
};


class Solution97 {
public:
    // 2022.8.13, from https://github.com/grandyang/leetcode/issues/644
    /*
        下面这种解法对上面的方法优化了空间复杂度 ，使用 preSum 和 sum 来代替数组，思路和上面完全一样，可以参加上面的讲解，
        注意这里我们的第二个if中是判断 i >= k - 1，而上面的方法是判断 i >= k，这是因为上面的 sums 数组初始化了 n + 1 
        个元素，注意坐标的转换，而第一个 if 中 i >= k 不变是因为j和i之间就差了k个，所以不需要考虑坐标的转换，参见代码如下：
    */
    double findMaxAverage(vector<int>& nums, int k) {
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (right - left > 1e-5) {
            double minSum = 0, sum = 0, preSum = 0, mid = left + (right - left) / 2;
            bool check = false;
            for (int i = 0; i < nums.size(); ++i) {
                sum += nums[i] - mid;
                if (i >= k) {
                    preSum += nums[i - k] - mid;
                    minSum = min(minSum, preSum);
                }
                if (i >= k - 1 && sum > minSum) {check = true; break;}
            }
            if (check) left = mid;
            else right = mid;
        }
        return left;
    }
};


class Solution96 {
public:
    // 2022.8.13, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/maximum-average-subarray-ii.cpp
    // Time:  O(n)
    // Space: O(n)
    double findMaxAverage(vector<int>& nums, int k) {
        double left = *min_element(nums.begin(), nums.end());
        double delta = numeric_limits<double>::max();
        while (delta > 1e-5) {
            delta = getDelta(left, nums, k);
            left += delta;
        }
        return left;
    }

private:
    double getDelta(double avg, const vector<int>& nums, int k) {
        vector<double> accu(nums.size() + 1);
        int minval_pos = -1;
        double delta = 0.0;
        for (int i = 0; i < nums.size(); ++i) {
            accu[i + 1] = nums[i] + accu[i] - avg;
            if (i >= k - 1) {
                if (minval_pos == -1 || accu[i - k + 1] < accu[minval_pos]) {
                    minval_pos = i - k + 1;
                }
                if (accu[i+1] - accu[minval_pos] >= 0) {
                    delta = max(delta, (accu[i + 1] - accu[minval_pos]) / (i + 1 - minval_pos));
                }
            }
        }
        return delta;
    }
};


class Solution95 {
public:
    // 2022.8.13, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/maximum-average-subarray-ii.cpp
    // Time:  O(nlogm), m is (max_val - min_val)
    // Space: O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (right - left > 1e-5) {
            double mid = left + (right - left) / 2;
            if (isMidLargerOrEqualToTarget(mid, nums, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }

private:
    bool isMidLargerOrEqualToTarget(double mid, const vector<int>& nums, int k) {
        double sum = 0, prev = 0, min_sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i] - mid;
        }
        if (sum > 0) {
            return false;
        }
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - mid;
            prev += nums[i - k] - mid;
            min_sum = min(prev, min_sum);
            if (sum > min_sum) {
                return false;
            }
        }
        return true;  
    }
};


class Solution94 {
public:
    // 2022.8.13, from https://walkccc.me/LeetCode/problems/0644/
    // Time: O(nlog(max-min)/10^-5)
    // Space: O(1)O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        constexpr double kErr = 1e-5;
        double l = *min_element(begin(nums), end(nums));
        double r = *max_element(begin(nums), end(nums));

        while (r - l > kErr) {
        const double m = (l + r) / 2;
        if (check(nums, k, m))
            l = m;
        else
            r = m;
        }

        return l;
    }

private:
    // true if there's a subarray with length >= k and average sum >= m
    bool check(const vector<int>& nums, int k, double m) {
        double sum = 0;
        double prevSum = 0;
        double minPrevSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
        // trick: -m for each num so that we can check if the sum of the
        // subarray >= 0
        sum += nums[i] - m;
        if (i >= k) {
            prevSum += nums[i - k] - m;
            minPrevSum = min(minPrevSum, prevSum);
        }
        // if sum - minPrevSum >= 0,
        // we know there's a subarray with length >= k and average sum >= m
        if (i + 1 >= k && sum >= minPrevSum)
            return true;
        }

        return false;
    };
};


class Solution93 {
public:
    // 2022.8.13, from https://github.com/wisdompeak/LeetCode/blob/master/Dynamic_Programming/644.Maximum-Average-Subarray-II/644.Maximum-Average-Subarray-II.cpp
    /*
        解法1
        首先最基本o(N^2)的思路要搞清楚。设置两层循环，第一层控制subarray的尾元素位置，第二层控制subarray的首元素位置

        for (int i=k; i<nums.size(); i++)
        for (int j=0; j<=i-k+1; j++)
        {
            考察 nums[j]~nums[i]这个subarray的平均值，更新全局最大。
        }
        可见第二重循环有点大，把所有大于等于K程度的subarray都遍历了一遍。能否利用之前的信息呢？比如，若知道了nums[i-1]
        的最优解，对于解nums[i]的最优解有什么帮助呢？这种思想很像是DP了。

        我们考虑如果已经找到了nums[i-1]的最优解：即以nums[i-1]为尾元素、长度为len的subarray，是所有这种这种subarray
        里均值最大的情况。这说明什么？说明处于len长度之前的那些元素是拖后腿的！它们会拉低以nums[i-1]为尾元素的subarray
        的均值，同样也会拉低以nums[i]为尾元素的subarray的均值。所以说，第二重循环我么不需要从0开始找。根据nums[i-1]
        最优解对应的subarray队首开始找就行了。

        for (int i=k; i<nums.size(); i++)
        {
            for (int j=i-dp[i-1]; j<=i-k+1; j++)
            {
                考察 nums[j]~nums[i]这个subarray的平均值，更新全局最大。
            }
            dp[i] = ...
        }
    */
    double findMaxAverage(vector<int>& nums, int k) 
    {
        
        vector<int>cumSum(nums.size()+1);
        cumSum[0]=0;
        for (int i=1; i<=nums.size(); i++)
            cumSum[i]=cumSum[i-1]+nums[i-1];

        vector<int>dp(nums.size()+1);
        dp[k]=1;               
        double result=(cumSum[k]-cumSum[0])*1.0/k;
        
        for (int i=k+1; i<=nums.size(); i++)
        {
            double maxAvg=INT_MIN;
            
            for (int j=dp[i-1]; j<=i-k+1; j++)
            {
                double avg= (cumSum[i]-cumSum[j-1])*1.0/(i-j+1);
                if (avg>maxAvg)
                {
                    maxAvg=avg;
                    dp[i]=j;
                }
                if (avg>result)
                    result=avg;
                
                // cout<<avg<<endl;
            }
        }
        
        return result;
    }
};


class Solution92 {
public:
    // 2022.8.13, from https://github.com/wisdompeak/LeetCode/blob/master/Dynamic_Programming/644.Maximum-Average-Subarray-II/644.Maximum-Average-Subarray-II.cpp
    /*
        解法2
        上述的解法在lintcode中仍然会超时。下面介绍一个非常巧妙的二分搜索法。

        显然二分搜索的上限就是nums里的最大值，下限就是nums里的最小值。我们每次通过low和high确定一个mid，查找nums里是否存在
        一个子数组是的其平均值大于mid。如果有，那么我们就调高下限至mid；如果没有，我们就降低上限至mid

        但是我们如何知道是否存在一个子数组，其平均值大于mid呢？如果我们将这个数组整体都减去mid，那么任务就等价于找到一个平均值
        大于零的子数组，也就是是说，找到一个和为正数的子数组。

        如何确认一个数组里有一段子数组的和为正数呢？我们只要遍历一遍前缀和，发现curSum[i]>preMin即说明存在。这里的preMin就是
        在i之前的最小的前缀和。可见只要o(n)的搜索就可以完成判断。总体的时间长度就是o(NlogK)，其中K是nums最大最小值之差。
    */
    double findMaxAverage(vector<int>& nums, int k) 
    {
        double low = INT_MAX, high = INT_MIN;
        for (int i:nums)
        {
            low = min((int)low,i);
            high = max((int)high,i);
        }
    
        while (high-low>1e-6)
        {
            double mid = (high-low)/2+low;
            
            if (check(nums,mid,k))
                low = mid;
            else
                high = mid;            
        }
        
        return high;
    }
    
    bool check(vector<int>&nums, double avg, int k)
    {
        int N = nums.size();
        vector<double> prefixSum(N+1,0);
        
        for (int i=1; i<k; i++)
            prefixSum[i] = prefixSum[i-1]+nums[i-1]-avg;

        double preMin = 0;
        
        for (int i=k; i<=N; i++)
        {
            prefixSum[i] = prefixSum[i-1]+nums[i-1]-avg;
            
            if(prefixSum[i] > preMin) 
                return true;
            preMin = min(preMin, prefixSum[i-k+1]);
        }
        return false;
    }
};


class Solution91 {
public:
    // 2022.8.13, from https://leetcode.com/problems/maximum-average-subarray-ii/discuss/2338199/C%2B%2B-Binary-Search-O(nlogm)-time-O(1)-space!
    /*
        The idea behind binary search is that we can reduce the problem from finding
        average subarray to the sum subarray. For the sum subarray there is an easier
        two pointer solution. The way to convert it into sum subarray is to remove the guess
        average from the array. If the sum in some subarray is ever equal to zero,
        it means that average in this subarray is our guess average.
    */
    int check(vector <int> &a, double t, int k) {
        double lsum = 0, rsum = 0, curmin = 0;
        for (int i = 0; i < a.size(); i++) {
            rsum += (a[i] - t); 
            if (i >= k) {
                lsum += (a[i - k] - t);
                curmin = min(curmin, lsum);
            }
            if (i >= k - 1 && rsum >= curmin) 
                return 1;
        }
        return 0;
    }
    double findMaxAverage(vector<int>& a, int k) {
        double l = accumulate(a.begin(), a.begin() + k, 0.0) / k;
        double r = *max_element(a.begin(), a.end());
        while (r - l > 1e-5) {
            double m = (l + r) / 2;
            if (check(a, m, k))
                l = m;
            else r = m;
        }
        return l;
    }
};


class Solution90 {
public:
    // 2022.8.13, from https://leetcode.com/problems/maximum-average-subarray-ii/discuss/1737673/C%2B%2B-prefix-sum-%2B-queue-solution
    /*
        I like the idea of keeping tails that don't reduce the average. It's in a way idea of prunning. 
        I would recommend to change (1.0*pre[i-k+1]-pre[x])/(i-k-x+1) >= res to (1.0*pre[i-k+1]-pre[x])/(i-k-x+1) 
        > res (change >= to >). >= will definitely die on future testcases. With that change I can't 
        quite come up with a testcase that dies here, but who knows.
    */
	double findMaxAverage(vector<int>& nums, int k) {
        vector<int> pre(nums.size()+1);
        for(int i= 0;i < nums.size(); i++)
            pre[i+1] = pre[i] + nums[i];
        double res = 1.0*pre[k] / k;
        queue<int> q;
        for(int i = k; i < nums.size(); i++){
            q.push(i-k);
            res = max(res, (1.0*pre[i+1]-pre[i+1-k])/k);
            int sz = q.size();
            while(sz--){
                auto x = q.front();
                q.pop();
                res = max(res, (1.0*pre[i+1]-pre[x])/(i+1-x));
                if((1.0*pre[i-k+1]-pre[x])/(i-k-x+1) >= res)
                    q.push(x);
            }
        }
        return res;
    }
};


class Solution { //binary search
public: 
    // 2022.8.13, from https://leetcode.com/problems/maximum-average-subarray-ii/discuss/953784/C%2B%2B-Binary-Search-(modification-based-on-official-solution)
    // Time/Space: O(nlogM); O(1); M: max_val - minVal
    double findMaxAverage(vector<int>& nums, int k) {
        double min_val = *min_element(nums.begin(), nums.end());
        double max_val = *max_element(nums.begin(), nums.end());
        double error = INT_MAX, pre_mid = max_val;
        while(error > 0.000001){
            auto mid = (min_val + max_val) / 2;
            if(check(nums, k, mid)) min_val = mid;
            else max_val = mid;
            error = abs(pre_mid - mid); // trick: update the error between latest two iterations
            pre_mid = mid;
        }
        return min_val;        
    }
    
private:
    // to check if a subarray with length greater than or equal to k is possible with an average sum greater than the mid value, i.e., check:
    // (a_1+a_2+ a_3...+a_j)/j ≥ mid
    // Time/Space: O(N); O(1)
    bool check(const vector<int>& nums, int k, double mid) {
        double sums = 0, pre_sums = 0;
        double min_pre_sums = 0; // trick: to accomodate the case pre_sums include no elements.
        for(int i = 0; i < k; i++) sums += nums[i] - mid;
        if( sums >= 0) return true;
        for(int i = k; i < nums.size(); i++) {
            sums += nums[i] - mid;
            pre_sums += nums[i - k] - mid;
            min_pre_sums = min(min_pre_sums, pre_sums);
            if(sums - min_pre_sums >= 0) return true;
        }
        return false;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/



