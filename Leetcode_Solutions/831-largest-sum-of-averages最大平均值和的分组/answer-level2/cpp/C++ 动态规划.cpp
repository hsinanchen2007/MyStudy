设 dp(i,j) 为将前i个元素划分为j组所能得到的最大分数。
设 sum(x,y) 为区间 [x, y] 内元素的累加和。
那么有：
* dp(i,j) = max(dp(p,j-1) + sum(p+1,i)/(i-p)), 1 <= p < i, j > 1。
* dp(i,1) = sum(1, i)/i

![关注HelloNebula及时获取更多知识~](https://pic.leetcode-cn.com/0a228b4a7c2170115727fe6e56100ef8d02beb86011a85e8626c530fcb8cc466-qrcode_for_gh_6e5f8557b1f8_258.jpg)
