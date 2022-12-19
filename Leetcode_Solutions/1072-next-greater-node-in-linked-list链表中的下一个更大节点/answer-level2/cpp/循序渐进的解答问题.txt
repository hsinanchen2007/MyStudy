本题暴力法是最容易想到的，即先把链表转换为数组，然后对于每个元素，都检查其后边的元素，以获得下一个更大元素值。
```
vector<int> nextLargerNodes(ListNode* head) 
{
	vector<int> nums;
	vector<int> result;
	for (ListNode *current = head; current != NULL; current = current->next)
	{
		nums.push_back(current->val);
	}
	for (int i = 0; i < nums.size(); i++)
	{
		bool flag = false;
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[j] > nums[i])
			{
				result.push_back(nums[j]);
				flag = true;
				break;
			}
		}
		if (!flag)
			result.push_back(0);
	}
	return result;
}
```

但是该做法不免有些复杂，只击败了15%的提交，我们知道暴力法相对于简单的算法，一定是进行了多余的计算，我们可以对暴力法进行剪枝，使其简便。那么如何进行呢？问题的矛盾在于从数组左侧开始时，我们不知道右边的情况，也就无法利用已有知识进行剪枝，那不妨从数组右侧开始，设数组为nums，最终的结果数组为result，此时对于i处的值，我们已经知道了i右侧的部分情况，比如最大值m、nums[i+1]的下一个更大元素result[i+1]，显然num[i+1]<result[i+1]<=m。若nums[i]<nums[i+1]，那么i处的下一个更大元素result[i]就是nums[i+1]；若nums[i+1]<nums[i]<result[i+1]，即虽然i处值大于i+1的值，但是i+1的下一个更大值result[i+1]比nums[i]大，此时result[i]就等于result[i+1];若nums[i]>=m，那么肯定不存在下一个更大元素，result[i]=0;若nums[i+1]<result[i+1]<nums[i]<m，此时我们无法根据i+1处的元素来判断，即我们掌握的信息不足以使我们进行判断了，此时进行暴力法即可。上述剪枝可大量减少不必要的计算，击败93%的提交。
```
vector<int> nextLargerNodes(ListNode* head) 
{
	vector<int> nums;
	for (ListNode *current = head; current != NULL; current = current->next)
	{
		nums.push_back(current->val);
	}
	vector<int> result(nums.size(), 0);
	int m = nums[nums.size()-1];
	for (int i = result.size() - 2; i >= 0; i--)
	{
		if (nums[i] < nums[i + 1])					//本值小于下一个值
		{
			result[i] = nums[i + 1];
		}
		else if(nums[i]<result[i+1])				//本值小于后一位的下一个更大值
		{
			result[i] = result[i + 1];
		}
		else
		{
			if (nums[i] >= m)						//本值大于右侧最大值
				result[i] = 0;
			else
			{
				for (int j = i + 1; j < nums.size(); j++)
				{
					if (nums[i] < nums[j])
					{

						result[i] = nums[j];
						break;
					}
				}
			}
		}
		if (m < nums[i])
			m = nums[i];
	}
	return result;
}
```

对上述问题继续分析，我们把找到每个i的下一个更大的值称为目标问题，然而关键就在于不知道i右边的信息，倘若我们能够将i处的目标问题进行保存，运行到j处时再进行解决，问题将迎刃而解。然而这仅是一个简单的思路，我们要考虑如何保存和何时进行解决，首先解决如何保存，我们要保存两个东西，一个是当前值，一个是当前值的索引，可以考虑使用pair进行封装，保存的方式有很多，如数组vector、队列queue、栈stack，但是我们这里应当选择栈进行保存，为什么呢？，在第二种解法的时候说过，若nums[i]>nums[i+1]时，一旦出现一个nums[j]大于nums[i]了，那么其必定大于nums[i+1],而出现一个nums[j]大于nums[i+1]了，其不一定大于nums[i]，这说明，一旦有两个以上的目标问题需要解决，必须先解决最后的那个目标问题，即用到了栈的后进先出原则。然后我们讨论什么时候
解决目标问题，也就是j满足什么样的条件，由于栈中已经保存了所有恣待解决的目标问题，我们只需要在遍历链表时，和栈顶元素进行比较即可，每到达一个新的节点，就和栈顶元素进行比较，若大于栈顶元素，则栈顶元素的目标问题得到解决，设置结果数组result对应索引处的值，然后出栈，继续和栈顶元素进行比较，直到本节点元素不大于栈顶元素为止，此时将本节点元素入栈，即本节点的目标问题成为了最优先解决的了，然后继续遍历下一个节点。当所有节点遍历完成后，栈中剩余元素就是没有下一个更大值的元素了，他们的结果数组result中，对应位置为0。该方法只需遍历一次链表，每次遍历时要处理栈，复杂度理论上来讲要比第二种低，但是在LeetCode-cn上运行要比第二种更慢，在LeetCode上运行时间和第二种相同，达到了94%，该方法代码量要少很多。
```
vector<int> nextLargerNodes(ListNode* head)
{
	stack<pair<int, int>> st;
	vector<int> result;
	int index = 0;
	for (ListNode *current = head; current != NULL; current = current->next)
	{
		result.push_back(0);			//扩容result，默认为0，最后没有下一个更大元素的位置刚好为0
		while (!st.empty() && current->val > st.top().second) //本处的值大于栈顶元素
		{
			result[st.top().first] = current->val;
			st.pop();
		}
		st.push(make_pair(index, current->val));
		index++;
	}
	return result;
}
```
