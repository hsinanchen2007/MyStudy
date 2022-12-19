刚看到这道题的时候感觉应该是回溯，但是超时了… 于是考虑dp
这题其实就是判断组成s的各种可能性，所以我们需要确定的组合中的每一个子串是否在wordDic中 因此可以逐步考虑 从substring(0,1)的组合方式一直考虑到substring(0, s.length)的组合方式
我解dp一般都是先画图(感觉只在比较简单的题适用了) i为行 j为列
i表示以s[i - 1]结尾(即substring(0,i)) j表示分割点 将(0, i) 分割成(0, j)和(j, i)
![QQ图片20200224073604.png](https://pic.leetcode-cn.com/14e4a3d67999eb707fdb1c8b6e26404af94c74cb9d139a473cbf4eebadf36fc4-QQ%E5%9B%BE%E7%89%8720200224073604.png)

 
通过画图我发现 j = 0时是会用到其他状态的 dp[i]直接可以通过contains(substring(0, i))得到;
              1 <= j < i时 dp[i] = dp[j] + dp[j, i];
一旦dp[i]为true 我们就可以停止对当前i的计算 继续去计算dp[i + 1]
代码如下：
```
class Solution {
	public boolean wordBreak(String s, List<String> wordDict) {
		int len = s.length();
		boolean[] dp = new boolean[len + 1]; // 从(0, 0)到(0, len)一共len + 1个
		/** i表示以s[i - 1]结尾(第i - 1个字符结尾) j表示分割点 将(0, i) 分割成(0, j)和(j, i) 这么做是因为避免重复计算(0 , j) */
		for (int i = 1; i <= len; i ++) {
			dp[i] = wordDict.contains(s.substring(0, i)); // j = 0时是从(0, i) 不需要之前的结果 所以拿出来放在这
			if (dp[i]) // 如果dp[i]已经为true 无需在计算了 直接开始 i + 1
				continue;
			for (int j = 1; j < i; j ++) { // j = 0已经在上面计算过
				dp[i] = dp[j] && wordDict.contains(s.substring(j,i));
				if (dp[i])
					break;
			}
		}
		return dp[len];
    }
	
    public static void main(String[] args ) {
    	Solution solution = new Solution();
    	List<String> wordDict = new ArrayList<>();
		/** case 1 */
    	String s = "catsandog";
    	wordDict.add("cats");
    	wordDict.add("dog");
    	wordDict.add("sand");
    	wordDict.add("and");
    	wordDict.add("cat");
    	/** case 2 */
//    	String s = "applepenapple";
//    	wordDict.add("apple");
//    	wordDict.add("pen");
//    	/** case 3 */
//    	String s = "cars";
//    	wordDict.add("car");
//    	wordDict.add("ca");
//    	wordDict.add("rs");
    	boolean res = solution.wordBreak(s, wordDict);
    	System.out.print(res);
    }
}
```