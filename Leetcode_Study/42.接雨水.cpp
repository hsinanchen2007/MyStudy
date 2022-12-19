/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

/*

https://leetcode.cn/problems/trapping-rain-water/

42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 
示例 1：

输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
 

提示：

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
通过次数531,756提交次数863,450

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0042.%E6%8E%A5%E9%9B%A8%E6%B0%B4.md
    // 接雨水问题在面试中还是常见题目的，有必要好好讲一讲。
    /*
       本文深度讲解如下三种方法：
       
       双指针法
       动态规划
       单调栈
       
       双指针解法
       这道题目使用双指针法并不简单，我们来看一下思路。
       
       首先要明确，要按照行来计算，还是按照列来计算。
       按照行来计算如图： 42.接雨水2
       按照列来计算如图： 42.接雨水1
      
       一些同学在实现的时候，很容易一会按照行来计算一会按照列来计算，这样就会越写越乱。
       我个人倾向于按照列来计算，比较容易理解，接下来看一下按照列如何计算。
      
       首先，如果按照列来计算的话，宽度一定是1了，我们再把每一列的雨水的高度求出来就可以了。
       可以看出每一列雨水的高度，取决于，该列 左侧最高的柱子和右侧最高的柱子中最矮的那个柱子的高度。
       这句话可以有点绕，来举一个理解，例如求列4的雨水高度，如图：
      
       42.接雨水3
      
       列4 左侧最高的柱子是列3，高度为2（以下用lHeight表示）。
       列4 右侧最高的柱子是列7，高度为3（以下用rHeight表示）。
       列4 柱子的高度为1（以下用height表示）
       
       那么列4的雨水高度为 列3和列7的高度最小值减列4高度，即： min(lHeight, rHeight) - height。
       列4的雨水高度求出来了，宽度为1，相乘就是列4的雨水体积了。
       此时求出了列4的雨水体积。

       一样的方法，只要从头遍历一遍所有的列，然后求出每一列雨水的体积，相加之后就是总雨水的体积了。
       首先从头遍历所有的列，并且要注意第一个柱子和最后一个柱子不接雨水，代码如下：
       
       for (int i = 0; i < height.size(); i++) {
             第一个柱子和最后一个柱子不接雨水
          if (i == 0 || i == height.size() - 1) continue;
       }
       在for循环中求左右两边最高柱子，代码如下：
       
       int rHeight = height[i];    记录右边柱子的最高高度
       int lHeight = height[i];    记录左边柱子的最高高度
       for (int r = i + 1; r < height.size(); r++) {
           if (height[r] > rHeight) rHeight = height[r];
       }
       for (int l = i - 1; l >= 0; l--) {
           if (height[l] > lHeight) lHeight = height[l];
       }
       最后，计算该列的雨水高度，代码如下：
       int h = min(lHeight, rHeight) - height[i];
       if (h > 0) sum += h;    注意只有h大于零的时候，在统计到总和中
       整体代码如下：
       因为每次遍历列的时候，还要向两边寻找最高的列，所以时间复杂度为O(n^2)。 空间复杂度为O(1)。
    */
    int trap(vector<int>& height) {
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            // 第一个柱子和最后一个柱子不接雨水
            if (i == 0 || i == height.size() - 1) continue;

            int rHeight = height[i]; // 记录右边柱子的最高高度
            int lHeight = height[i]; // 记录左边柱子的最高高度
            for (int r = i + 1; r < height.size(); r++) {
                if (height[r] > rHeight) rHeight = height[r];
            }
            for (int l = i - 1; l >= 0; l--) {
                if (height[l] > lHeight) lHeight = height[l];
            }
            int h = min(lHeight, rHeight) - height[i];
            if (h > 0) sum += h;
        }
        return sum;
    }
};


class Solution99 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0042.%E6%8E%A5%E9%9B%A8%E6%B0%B4.md
    /*
       动态规划解法
       在上一节的双指针解法中，我们可以看到只要记录左边柱子的最高高度 和 右边柱子的最高高度，就可以计算当前位置的雨水面积，
       这就是通过列来计算。
      
       当前列雨水面积：min(左边柱子的最高高度，记录右边柱子的最高高度) - 当前柱子高度。
       
       为了得到两边的最高高度，使用了双指针来遍历，每到一个柱子都向两边遍历一遍，这其实是有重复计算的。我们把每一个位置的
       左边最高高度记录在一个数组上（maxLeft），右边最高高度记录在一个数组上（maxRight）。这样就避免了重复计算，这就用
       到了动态规划。
      
       当前位置，左边的最高高度是前一个位置的左边最高高度和本高度的最大值。
       
       即从左向右遍历：maxLeft[i] = max(height[i], maxLeft[i - 1]);
       从右向左遍历：maxRight[i] = max(height[i], maxRight[i + 1]);
       
       这样就找到递推公式。
    */
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        int size = maxRight.size();

        // 记录每个柱子左边柱子最大高度
        maxLeft[0] = height[0];
        for (int i = 1; i < size; i++) {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }
        // 记录每个柱子右边柱子最大高度
        maxRight[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            maxRight[i] = max(height[i], maxRight[i + 1]);
        }
        // 求和
        int sum = 0;
        for (int i = 0; i < size; i++) {
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            if (count > 0) sum += count;
        }
        return sum;
    }
};


class Solution98 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0042.%E6%8E%A5%E9%9B%A8%E6%B0%B4.md
    /*
       单调栈解法
       这个解法可以说是最不好理解的了，所以下面我花了大量的篇幅来介绍这种方法。
       单调栈就是保持栈内元素有序。和栈与队列：单调队列一样，需要我们自己维持顺序，没有现成的容器可以用。
      
       准备工作
       那么本题使用单调栈有如下几个问题：
      
       首先单调栈是按照行方向来计算雨水，如图：
       42.接雨水2
       
       知道这一点，后面的就可以理解了。
       
       使用单调栈内元素的顺序
       从大到小还是从小到大呢？
       
       从栈头（元素从栈头弹出）到栈底的顺序应该是从小到大的顺序。
       
       因为一旦发现添加的柱子高度大于栈头元素了，此时就出现凹槽了，栈头元素就是凹槽底部的柱子，栈头第二个元素就是凹槽左边的柱子，
       而添加的元素就是凹槽右边的柱子。
      
       如图：
      
       42.接雨水4
      
       遇到相同高度的柱子怎么办。
       遇到相同的元素，更新栈内下标，就是将栈里元素（旧下标）弹出，将新元素（新下标）加入栈中。
       
       例如 5 5 1 3 这种情况。如果添加第二个5的时候就应该将第一个5的下标弹出，把第二个5添加到栈中。
      
       因为我们要求宽度的时候 如果遇到相同高度的柱子，需要使用最右边的柱子来计算宽度。
      
       如图所示：
      
       42.接雨水5
      
       栈里要保存什么数值
       是用单调栈，其实是通过 长 * 宽 来计算雨水面积的。
      
       长就是通过柱子的高度来计算，宽是通过柱子之间的下标来计算，
      
       那么栈里有没有必要存一个pair<int, int>类型的元素，保存柱子的高度和下标呢。
       其实不用，栈里就存放int类型的元素就行了，表示下标，想要知道对应的高度，通过height[stack.top()] 就知道弹出的下标对应的高度了。
       
       所以栈的定义如下：
      
       stack<int> st;    存着下标，计算的时候用下标对应的柱子高度
       明确了如上几点，我们再来看处理逻辑。
       
       单调栈处理逻辑
       先将下标0的柱子加入到栈中，st.push(0);。
      
       然后开始从下标1开始遍历所有的柱子，for (int i = 1; i < height.size(); i++)。
      
       如果当前遍历的元素（柱子）高度小于栈顶元素的高度，就把这个元素加入栈中，因为栈里本来就要保持从小到大的顺序（从栈头到栈底）。
      
       代码如下：
      
       if (height[i] < height[st.top()])  st.push(i);
       如果当前遍历的元素（柱子）高度等于栈顶元素的高度，要跟更新栈顶元素，因为遇到相相同高度的柱子，需要使用最右边的柱子来计算宽度。
       
       代码如下：
       
       if (height[i] == height[st.top()]) {    例如 5 5 1 7 这种情况
            st.pop();
            st.push(i);
       }
       如果当前遍历的元素（柱子）高度大于栈顶元素的高度，此时就出现凹槽了，如图所示：
       
       42.接雨水4
       
       取栈顶元素，将栈顶元素弹出，这个就是凹槽的底部，也就是中间位置，下标记为mid，对应的高度为height[mid]（就是图中的高度1）。
      
       此时的栈顶元素st.top()，就是凹槽的左边位置，下标为st.top()，对应的高度为height[st.top()]（就是图中的高度2）。
      
       当前遍历的元素i，就是凹槽右边的位置，下标为i，对应的高度为height[i]（就是图中的高度3）。
       
       此时大家应该可以发现其实就是栈顶和栈顶的下一个元素以及要入栈的三个元素来接水！
      
       那么雨水高度是 min(凹槽左边高度, 凹槽右边高度) - 凹槽底部高度，代码为：int h = min(height[st.top()], height[i]) - 
       height[mid];
       
       雨水的宽度是 凹槽右边的下标 - 凹槽左边的下标 - 1（因为只求中间宽度），代码为：int w = i - st.top() - 1 ;
      
       当前凹槽雨水的体积就是：h * w。
      
       求当前凹槽雨水的体积代码如下：
       while (!st.empty() && height[i] > height[st.top()]) {    注意这里是while，持续跟新栈顶元素
          int mid = st.top();
          st.pop();
          if (!st.empty()) {
              int h = min(height[st.top()], height[i]) - height[mid];
              int w = i - st.top() - 1;    注意减一，只求中间宽度
              sum += h * w;
          }
       }
    */
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0; // 可以不加
        stack<int> st; // 存着下标，计算的时候用下标对应的柱子高度
        st.push(0);
        int sum = 0;
        for (int i = 1; i < height.size(); i++) {
            if (height[i] < height[st.top()]) {     // 情况一
                st.push(i);
            } if (height[i] == height[st.top()]) {  // 情况二
                st.pop(); // 其实这一句可以不加，效果是一样的，但处理相同的情况的思路却变了。
                st.push(i);
            } else {                                // 情况三
                while (!st.empty() && height[i] > height[st.top()]) { // 注意这里是while
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1; // 注意减一，只求中间宽度
                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};


class Solution97 {
public:
    // 2022.7.24, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0042.%E6%8E%A5%E9%9B%A8%E6%B0%B4.md
    // 精简之后的代码，大家就看不出去三种情况的处理了，貌似好像只处理的情况三，其实是把情况一和情况二融合了。 
    // 这样的代码不太利于理解。
    int trap(vector<int>& height) {
        stack<int> st;
        st.push(0);
        int sum = 0;
        for (int i = 1; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int mid = st.top();
                st.pop();
                if (!st.empty()) {
                    int h = min(height[st.top()], height[i]) - height[mid];
                    int w = i - st.top() - 1;
                    sum += h * w;
                }
            }
            st.push(i);
        }
        return sum;
    }
};


class Solution96 {
public:
    // 登录 AlgoMooc 官网获取更多算法图解
    // https://www.algomooc.com
    // 作者：程序员吴师兄
    // 代码有看不懂的地方一定要私聊咨询吴师兄呀
    // 接雨水（ LeetCode 42 ）:https://leetcode-cn.com/problems/trapping-rain-water/
    int trap(vector<int>& height) {
        // 只有两根柱子，必然无法形成一个凹槽，那么水的面积就是 0
        if (height.size() <= 2) return 0; 

        // 构建一个栈，用来存储对应的柱子的下标
        // 注意：stk 存储的是下标而非高度
        stack<int> stk ;

        // 一开始水的面积是 0
        int result = 0;
        
        // 从头开始遍历整个数组
        for (int i = 0; i < height.size(); i++) {
            // 如果栈为空，那么直接把当前索引加入到栈中
            if(stk.empty()){
                // 把当前索引加入到栈中
                stk.push(i);

             // 否则的话，栈里面是有值的，我们需要去判断此时的元素、栈顶元素、栈顶之前的元素能否形成一个凹槽
             // 情况一：此时的元素小于栈顶元素，凹槽的右侧不存在，无法形成凹槽
            }else if (height[i] < height[stk.top()]) {    
                // 把当前索引加入到栈中
                stk.push(i);
               
               // 情况二：此时的元素等于栈顶元素，也是无法形成凹槽
            } else if (height[i] == height[stk.top()]) {

                // 把当前索引加入到栈中
                stk.push(i);

               // 情况三：此时的的元素大于栈顶元素，有可能形成凹槽
               // 注意是有可能形成，因为比如栈中的元素是 2 、2 ，此时的元素是 3，那么是无法形成凹槽的
            } else {    

                // 由于栈中有可能存在多个元素，移除栈顶元素之后，剩下的元素和此时的元素也有可能形成凹槽
                // 因此，我们需要不断的比较此时的元素和栈顶元素
                // 此时的元素依旧大于栈顶元素时，我们去计算此时的凹槽面积
                // 借助 while 循环来实现这个操作
                while (!stk.empty() && height[i] > height[stk.top()]) {

                    // 1、获取栈顶的下标，bottom 为凹槽的底部位置
                    int bottom = stk.top();

                    // 将栈顶元素推出，去判断栈顶之前的元素是否存在，即凹槽的左侧是否存在
                    stk.pop();

                    // 2、如果栈不为空，即栈中有元素，即凹槽的左侧存在
                    if (!stk.empty()) {

                        // 凹槽左侧的高度 height[stk.top() 和 凹槽右侧的高度 height[i] 
                        // 这两者的最小值减去凹槽底部的高度就是凹槽的高度  
                        int h = min(height[stk.top()], height[i]) - height[bottom];

                        // 凹槽的宽度等于凹槽右侧的下标值 i 减去凹槽左侧的下标值 stk.top 再减去 1
                        int w = i - stk.top() - 1; 

                        // 将计算的结果累加到最终的结果上去
                        result += h * w;
                    }
                }

                // 栈中和此时的元素可以形成栈的情况在上述 while 循环中都已经判断了
                // 那么，此时栈中的元素必然不可能大于此时的元素，所以可以把此时的元素添加到栈中
                stk.push(i);
            }
        }

        // 最后返回结果即可
        return result;
    }
};


class Solution95 {
public:
    // 2022.7.24, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/42.%20Trapping%20Rain%20Water
    // OJ: https://leetcode.com/problems/trapping-rain-water/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(N)
    // The water that can be held at position i is max(0, min(left[i], right[i]) - A[i]) 
    // where left[i] is the maximum 
    // height to the left of i and right[i] is the maximum height to the right of i.
    int trap(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<int> left(N, 0), right(N, 0);
        for (int i = 1; i < N; ++i) left[i] = max(left[i - 1], A[i - 1]);
        for (int i = N - 2; i >= 0; --i) right[i] = max(right[i + 1], A[i + 1]);
        for (int i = 1; i < N - 1; ++i) ans += max(0, min(left[i], right[i]) - A[i]);
        return ans;
    }
};


class Solution94 {
public:
    // OJ: https://leetcode.com/problems/trapping-rain-water/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(N)
    int trap(vector<int>& A) {
        int N = A.size(), ans = 0, mx = 0, left = 0;
        vector<int> right(N);
        for (int i = N - 2; i >= 0; --i) right[i] = max(right[i + 1], A[i + 1]);
        for (int i = 0; i < N; ++i) {
            ans += max(0, min(left, right[i]) - A[i]);
            left = max(left, A[i]);
        }
        return ans;
    }
};


class Solution93 {
public:
    // OJ: https://leetcode.com/problems/trapping-rain-water/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(N)
    // This solution is similar to the Monotonic Stack solution to 84. Largest Rectangle in Histogram (Hard).
    // 
    // The intuition is that once we see a taller A[i], all A[j] <= A[i] (j < i) are no longer relevant because 
    // we will at most use A[i] as the left edge.
    // 
    // So, we maintain a monotonic stack s storing the relevant indices.
    // 
    // For each A[i], we pop indices <= A[i] from s. For each popped index mid, the index triple s.top(), mid, 
    // i forms a rectangle of water. The width is i - s.top() - 1, the height is min(A[s.top()], A[i]) - A[mid].
    int trap(vector<int>& A) {
        int N = A.size(), ans = 0;
        stack<int> s;
        for (int i = 0; i < N; ++i) {
            while (s.size() && A[i] >= A[s.top()]) {
                int mid = s.top();
                s.pop();
                if (s.size()) ans += (i - s.top() - 1) * (min(A[i], A[s.top()]) - A[mid]);
            }
            s.push(i);
        }
        return ans;
    }
};


class Solution92 {
public:
    // OJ: https://leetcode.com/problems/trapping-rain-water/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Can we save the O(N) space in solution 1? The space is taken by the right array storing the maximum heights. 
    // We can try using a single pointer instead.
    // 
    // Let's traverse i from 0 rightwards. For each A[i], instead of using right[i] -- the tallest height to the 
    // right of A[i], we use a pointer j = N-1. As long as A[j] >= A[i], the height of the water filled at index i 
    // is determined only by left -- left - A[i].
    // 
    // So, we keep incrementing i and fill left - A[i] at index i, until A[i] > A[j].
    // 
    // Now, the setup is reversed. Due to symmetry, now we should keep decrementing j and fill right - A[j] at index j, 
    // until A[j] >= A[i].
    int trap(vector<int>& A) {
        int i = 0, j = A.size() - 1, left = 0, right = 0, ans = 0;
        while (i < j) {
            if (A[i] < A[j]) {
                left = max(left, A[i]);
                ans += left - A[i++];
            } else {
                right = max(right, A[j]);
                ans += right - A[j--];
            }
        }
        return ans;
    }
};


class Solution91 {
public:
    // 2022.7.24, from https://walkccc.me/LeetCode/problems/0042/
    // Time: O(n)
    // Space: O(n)
    int trap(vector<int>& height) {
        const int n = height.size();
        int ans = 0;
        vector<int> l(n);  // l[i] := max(height[0..i])
        vector<int> r(n);  // r[i] := max(height[i..n))

        for (int i = 0; i < n; ++i)
        l[i] = i == 0 ? height[i] : max(height[i], l[i - 1]);

        for (int i = n - 1; i >= 0; --i)
        r[i] = i == n - 1 ? height[i] : max(height[i], r[i + 1]);

        for (int i = 0; i < n; ++i)
        ans += min(l[i], r[i]) - height[i];

        return ans;
    }
};


class Solution90 {
public:
    // 2022.7.24, from https://walkccc.me/LeetCode/problems/0042/
    // Time: O(n)
    // Space: O(1)
    int trap(vector<int>& height) {
        if (height.empty())
        return 0;

        int ans = 0;
        int l = 0;
        int r = height.size() - 1;
        int maxL = height[l];
        int maxR = height[r];

        while (l < r)
        if (maxL < maxR) {
            ans += maxL - height[l];
            maxL = max(maxL, height[++l]);
        } else {
            ans += maxR - height[r];
            maxR = max(maxR, height[--r]);
        }

        return ans;
    }
};


class Solution89 {
public:
    // 2022.7.24, from https://www.guozet.me/leetcode/Leetcode-42-Trapping-Rain-Water.html?h=trap
    int trap(vector<int>& height) {
        int res = 0, left_max = 0, right_max = 0;
        vector<int> diff(height.size(), 0);
        // Get the left max_hight
        // For i, the left heightes is the left_max;
        for (int i = 0; i < height.size(); ++i) {
        diff[i] = left_max;
        left_max = max(left_max, height[i]);
        }

        for (int i = height.size() - 1; i >= 0; --i) {
        // Find the min for the left_max and right_max, and
        // use this height as the diff value;
        diff[i] = min(right_max, diff[i]);
        right_max = max(right_max, height[i]);
        if (diff[i] > height[i]) res += diff[i] - height[i];
        }
        return res;
    }
};


class Solution88 {
public:
    // 2022.7.24, from https://github.com/MaskRay/LeetCode/blob/master/trapping-rain-water.cc
    // Trapping Rain Water
    int trap(vector<int> &h) {
        int hl = 0, hr = 0, i = 0, j = h.size(), s = 0;
        while (i < j) {
        if (hl < hr) {
            s += max(hl-h[i], 0);
            hl = max(hl, h[i++]);
        } else {
            s += max(hr-h[--j], 0);
            hr = max(hr, h[j]);
        }
        }
        return s;
    }
};


class Solution87 {
public:
    // 2022.7.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/trapping-rain-water.cpp
    // Time:  O(n)
    // Space: O(1)
    int trap(vector<int>& height) {
        int result = 0, left = 0, right = height.size() - 1, level = 0;
        while (left < right) {
            int lower = height[height[left] < height[right] ? left++ : right--];
            level = max(level, lower);
            result += level - lower;
        }
        return result;
    }
};


class Solution86 {
public:
    // 2022.7.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/trapping-rain-water.cpp
    // Time:  O(n)
    // Space: O(1)
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int i = 0, j = height.size() - 1;
        int left_height = height[0];
        int right_height = height[height.size() - 1];
        int trap = 0;

        while (i < j) {
            if (left_height < right_height) {
                ++i;
                // Fill in the gap.
                trap += max(0, left_height - height[i]);
                // Update current max height from left.
                left_height = max(left_height, height[i]);
            }
            else {
                --j;
                // Fill in the gap.
                trap += max(0, right_height - height[j]);
                // Update current max height from right.
                right_height = max(right_height, height[j]);
            }
        }

        return trap;
    }
};


class Solution85 {
public:
    // 2022.7.24, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/356196/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < height.size(); i ++ ) {
            int last = 0;
            while (stk.size() && height[stk.top()] <= height[i]) {
                res += (height[stk.top()] - last) * (i - stk.top() - 1);
                last = height[stk.top()];
                stk.pop();
            }

            if (stk.size()) res += (i - stk.top() - 1) * (height[i] - last);
            stk.push(i);
        }

        return res;
    }
};


class Solution84 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/42
    /*
        这道收集雨水的题跟之前的那道 Largest Rectangle in Histogram 有些类似，但是又不太一样，先来看一种方法，
        这种方法是基于动态规划 Dynamic Programming 的，维护一个一维的 dp 数组，这个 DP 算法需要遍历两遍数组，
        第一遍在 dp[i] 中存入i位置左边的最大值，然后开始第二遍遍历数组，第二次遍历时找右边最大值，然后和左边最大值
        比较取其中的较小值，然后跟当前值 A[i] 相比，如果大于当前值，则将差值存入结果，参见代码如下：

        C++ 解法一：
    */
    int trap(vector<int>& height) {
        int res = 0, mx = 0, n = height.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = mx;
            mx = max(mx, height[i]);
        }
        mx = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = min(dp[i], mx);
            mx = max(mx, height[i]);
            if (dp[i] > height[i]) res += dp[i] - height[i];
        }
        return res;
    }
};


class Solution83 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/42
    /*
        再看一种只需要遍历一次即可的解法，这个算法需要 left 和 right 两个指针分别指向数组的首尾位置，从两边向中间扫描，
        在当前两指针确定的范围内，先比较两头找出较小值，如果较小值是 left 指向的值，则从左向右扫描，如果较小值是 right 
        指向的值，则从右向左扫描，若遇到的值比当较小值小，则将差值存入结果，如遇到的值大，则重新确定新的窗口范围，以此类
        推直至 left 和 right 指针重合，参见代码如下：

        C++ 解法二：
    */
    int trap(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            int mn = min(height[l], height[r]);
            if (mn == height[l]) {
                ++l;
                while (l < r && height[l] < mn) {
                    res += mn - height[l++];
                }
            } else {
                --r;
                while (l < r && height[r] < mn) {
                    res += mn - height[r--];
                }
            }
        }
        return res;
    }
};


class Solution82 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/42
    /*
        我们可以对上面的解法进行进一步优化，使其更加简洁：

        C++ 解法三：
    */
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, level = 0, res = 0;
        while (l < r) {
            int lower = height[(height[l] < height[r]) ? l++ : r--];
            level = max(level, lower);
            res += level - lower;
        }
        return res;
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/42
    /*
        下面这种解法是用 stack 来做的，博主一开始都没有注意到这道题的 tag 还有 stack，所以以后在总结
        的时候还是要多多留意一下标签啊。其实用 stack 的方法博主感觉更容易理解，思路是，遍历高度，如果此
        时栈为空，或者当前高度小于等于栈顶高度，则把当前高度的坐标压入栈，注意这里不直接把高度压入栈，而
        是把坐标压入栈，这样方便在后来算水平距离。当遇到比栈顶高度大的时候，就说明有可能会有坑存在，可以
        装雨水。此时栈里至少有一个高度，如果只有一个的话，那么不能形成坑，直接跳过，如果多余一个的话，那
        么此时把栈顶元素取出来当作坑，新的栈顶元素就是左边界，当前高度是右边界，只要取二者较小的，减去坑
        的高度，长度就是右边界坐标减去左边界坐标再减1，二者相乘就是盛水量啦，参见代码如下：

        C++ 解法四：
    */
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while (i < n) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            } else {
                int t = st.top(); st.pop();
                if (st.empty()) continue;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

