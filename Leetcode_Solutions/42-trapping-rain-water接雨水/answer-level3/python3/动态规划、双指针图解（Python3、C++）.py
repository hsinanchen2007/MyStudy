
# ### 方法一：暴力（Python 超时）
# 一开始拿到题目之后可能会有些手足无措，我们从最原始的暴力解法开始思考，对于每个下标 i，我们计算它上方可以接多少雨水，然后将所有下标上的雨水加起来即可。

# ![fig 1](https://pic.leetcode-cn.com/4e0f426907d4c96c80e97fdff3a26b3aeabee48eaea3843385cb0a77fba1b770-file_1580965518713)

# 具体来说，如图我们假设输入为 `[0,1,0,2]`，凭感觉，我们得到接完雨水后的结果如右图。可以看到，只有下标 2 的上方可以接到雨水，其他地方的水会向两边“流掉”，所以无法接到水。

# 为什么是这样呢？首先看下标 1 ，它左边最高的柱子是下标 0 ，右边最高的柱子是下标 3 ，因为这两个柱子的较小值比下标 1 要低，所以下标 1 的上方没有水。相反，我们看下标 2，它左边最高的柱子是下标 1 ，右边最高的柱子是下标 3 ，这两个柱子较矮的是下标 1 ，它比下标 2 本身要高，所以下标 2 可以接到水，接的水就是高度差。

# 因此，我们遍历每个下标，寻找它左边和右边最高的柱子，判断是否可以接到水，将可接水的结果累加即可。
# ### 代码
# 代码如下：
# ```python []
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        for i in range(len(height)):
            max_left, max_right = 0,0
            # 寻找 max_left
            for j in range(0,i):
                max_left = max(max_left,height[j])
            # 寻找 max_right
            for j in range(i,len(height)):
                max_right = max(max_right,height[j])
            if min(max_left,max_right) > height[i]:
                ans += min(max_left,max_right) - height[i]
        
        return ans
# ```
# ```C++ []
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int maxleft;
        int maxright;
        for (int i = 0;i < n;i++){
            maxleft = maxright = 0;
            for (int j = 0;j < i;j++){
                maxleft = max(maxleft,height[j]);
            }
            for (int k = i;k<n;k++){
                maxright = max(maxright,height[k]);
            }
            if (min(maxleft,maxright) > height[i]){
                ans += min(maxleft,maxright) - height[i];
            }
            
        }
        return ans;
    }
};
# ```
# ### 复杂度分析
# - 时间复杂度：$O(N^2)$。最坏情况下，我们对于每个下标，都要向左和向右遍历直到两端，复杂度是 N 的平方。
# - 空间复杂度：$O(1)$。使用了有限的 `n`, `ans`, `maxleft`, `maxright`。


# ### 方法二：动态规划
# 我们发现在寻找每个下标的左边和右边最高的柱子时，会对柱子进行反复搜索导致复杂度降低，假如我们使用两个数组 `maxleft` 和 `maxright`，`maxleft[i]` 表示下标 `i` 左边最高柱子的高度,`maxright[i]` 表示下标 `i` 右边最高柱子的高度，很明显，我们只需要一趟遍历就可以得到结果。这样由于避免了重复计算，时间复杂度会降低到 O(N)。
# ### 代码

# ```python []
class Solution:
    def trap(self, height: List[int]) -> int:
        # 边界条件
        if not height: return 0
        n = len(height)
        maxleft = [0] * n
        maxright = [0] * n
        ans = 0
        # 初始化
        maxleft[0] = height[0]
        maxright[n-1] = height[n-1]
        # 设置备忘录，分别存储左边和右边最高的柱子高度
        for i in range(1,n):
            maxleft[i] = max(height[i],maxleft[i-1])
        for j in range(n-2,-1,-1):
            maxright[j] = max(height[j],maxright[j+1])
        # 一趟遍历，比较每个位置可以存储多少水
        for i in range(n):
            if min(maxleft[i],maxright[i]) > height[i]:
                ans += min(maxleft[i],maxright[i]) - height[i]
        return ans
# ```

# ```C++ []
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0){
            return 0;
        }
        int n = height.size();
        vector<int> maxleft (n);
        vector<int> maxright (n);
        int ans = 0;
        maxleft[0] = height[0];
        maxright[n-1] = height[n-1];

        for (int i=1;i<n;i++){
            maxleft[i] = max(height[i], maxleft[i-1]);
        }
        for (int j=n-2;j>-1;j--){
            maxright[j] = max(height[j],maxright[j+1]);
        }
        for (int k=0;k<n;k++){
            if (min(maxleft[k],maxright[k]) > height[k]){
                ans += min(maxleft[k],maxright[k]) - height[k];
            } 
        }
        return ans;
    }
};
# ```

# 由于使用了数组，我们的空间复杂度会增加到 O(N),如何能把空间复杂度也降低呢？我们可以使用双指针法。

# ### 方法三：双指针法

# 双指针法就是将上边的一个下标 `i`，变为两个下标 `left`，`right`，分别位于输入数组的两端。向中间移动时，边移动边计算。

# 除此之外，我们使用 `maxleft` 作为 `0...left` 的最大值，`maxright` 作为 `right...结尾` 的最大值。代码看不懂的地方可以看幻灯片帮助理解~

# <![幻灯片1.JPG](https://pic.leetcode-cn.com/a19052580f3523c215b7944d750ff0c034cfcfe583e1873dca500267e870203b-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/c15d169c19342138b709913a58f6bab3b6d4895b6815f77e10a8c4577d703412-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/c2f42aa934e899f231d1d60a5dc6a464d3a6ab69ab6ebecdd7511e5ea2503a64-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/fac95617d0414add81a235da1d5015f47d20956670e1d87e4e595598e3292b3c-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/fc3cb0eb73cabdc82e7201c98bcfb537f175fb662ba2cc63f9f112d3e2faee0a-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/31a68d7aa5516d87b558dde9235e7e474759fa5453e631de64a4e773c76080c4-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/da480e642a313768df8ca2371903b26845f2195f31cdf7e8499885e896f95182-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/168ceeaa3317c53e3a3b8c8746a9af5de0cc0c4f886f6ed56b2a3fa05e0b0986-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/4e7e48716408f0dc95501b03d4944da3c2948f402bdbb983ca697866a1ceaa2e-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/ce18c172ec3ff615e93898331ac016d636e8e13b5ea1c919285f7db1eed0f565-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG),![幻灯片11.JPG](https://pic.leetcode-cn.com/297edf34e9414d894a3d6f9262227529a2e01eab30351b73ec15b236c9840404-%E5%B9%BB%E7%81%AF%E7%89%8711.JPG)>


# ### 代码
# ```python []
class Solution:
    def trap(self, height: List[int]) -> int:
        # 边界条件
        if not height: return 0
        n = len(height)

        left,right = 0, n - 1  # 分别位于输入数组的两端
        maxleft,maxright = height[0],height[n - 1]
        ans = 0

        while left <= right:
            maxleft = max(height[left],maxleft)
            maxright = max(height[right],maxright)
            if maxleft < maxright:
                ans += maxleft - height[left]
                left += 1
            else:
                ans += maxright - height[right]
                right -= 1

        return ans
# ```
# ```C++ []
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0){
            return 0;
        }
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxleft = height[0];
        int maxright = height[n-1];
        int ans = 0;

        while (left <= right){
            maxleft = max(height[left],maxleft);
            maxright = max(height[right],maxright);
            if(maxleft < maxright){
                ans += maxleft - height[left];
                left++;
            }
            else{
                ans += maxright - height[right];
                right--;
            }
        }
        return ans;
    }
};
# ```
# ### 复杂度分析
# - 时间复杂度：$O(N)$。遍历了一遍数组。
# - 空间复杂度：$O(1)$。使用了有限的 `left`, `right`, `ans`, `maxleft`, `maxright`。

# 如有疑问，欢迎批评指正~


# PS：想要一起努力的童鞋们可以关注我创办的公众号：腐烂的橘子🍊，致力于摆脱算法的抽象思维，彻底搞懂算法，同时公众号还会发布面试中的高频知识点，一起努力吧！😋