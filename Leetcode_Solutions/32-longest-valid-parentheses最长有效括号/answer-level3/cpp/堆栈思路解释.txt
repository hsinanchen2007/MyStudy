class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> myStack;
		myStack.push(-1);
		int sNum = s.size();
		int maxLen = 0;
		int thisLength = 0;
		for (int i = 0; i < sNum; i++)
		{
			if (s[i] == '(')
			{
				myStack.push(i);
			}
			else
			{
				if (myStack.size() == 1)
				{
					myStack.pop();
					myStack.push(i);
				}
				else
				{
					myStack.pop();
					int beforeNum = myStack.top();
					thisLength = i - beforeNum;
					if (thisLength > maxLen)
						maxLen = thisLength;
				}
			}
		}
		return maxLen;
	}
};



官方答案的PPT演示对的，但是文字解释有问题。给大家说一下。

stack的栈底元素的含义是，已经确定无法匹配最后一个“)”的位置。正因为已经确定了无法匹配，所以下一个有效括号序列的位置一定从该位置后面产生。不知道我说清楚没有，我们来看一个例子

举例：
())()
12345

我们来看这个，下面依次走这个流程：
1. 栈里面放-1，表示之前确认断掉的子序列在-1这个位置。（即还没发现）
2. 遇到“（”，将1位置压入栈，此时栈内元素是：-1，1
3. 遇到“）”，检查一下栈里面元素数量发现大于1。说明其中有可以跟自己匹配的“（”，于是取出该括号。同时用自己位置2，减去前一个确定断掉的位置-1。得到目前最大括号序列是2.
4. （关键步骤！）又看到一个“（”，检查栈里，发现只有一个元素。意味着栈里没有多余“（”能够和自己匹配，那么此时括号子序列断开。于是用自己的位置3，替换原来栈底元素-1。表示目前子序列在3的位置断开
5. 后面就是正常步骤


最近刷leetcode，我感觉是不是翻译出问题了。怎么答案解释很多都不对