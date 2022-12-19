简单的说就是 准备两个栈 table_back 和 law_back,分别记录以下信息：
vector<int> table; 记录 皇后Q 插入顺序的列表； 例如 {0,2,1,3} 的意思是指，第一行皇后位置在0，第二行皇后位置在2，以此类推
vector<bool> law_pos;  下一行的合法位置，其长度始终为 n 。 可以插入的位置 的bool值为1； 例如 当 第一行皇后  在 0 时， law_pos = {0,0,1,1}

然后将皇后问题的第一行 Q 在 0 的位置 一直到 Q 在 n-1 的位置，都PUSH进栈中，
并且把对应的下一行合法信息，push进 合法栈 中

然后循环判断，如果栈没有空：

1.根据 law_pos 的信息，遍历其中所有合法位置，并且在合法位置插入，生成新表 temp_table 并判断
  1-1：temp_table 如果 size==n 那么说明此处顺利 完成任务，记录即可
  1-2：根据temp_table 生成新的 temp_law，并将 temp_table 和 temp_law 都插入栈中（不需要判断）
  



```
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
    if (n == 0) return vector<vector<string>>();
	if (n == 1) return vector<vector<string>> { {"Q"}};


	vector<vector<int>> table_back;  // 所有表格的存储
	vector<vector<bool>> law_back;   // 所有下一行合法位置的存储

	// 插入第0行所有可能位置，以及位置的对应下一行合法位置
	for (int i = n-1; i >= 0; i--)
	{
		vector<int> temp_table{ i };
		table_back.push_back(temp_table);

		vector<bool> temp_law(n, 1);
		temp_law[i] = 0;
		if (i - 1 >= 0) temp_law[i - 1] = 0;
		if (i + 1 < n) temp_law[i + 1] = 0;

		law_back.push_back(temp_law);
	}

	vector<bool> law_pos;
	vector<int> table;

	vector<vector<string>> resault; // 存结果
	
	
	do {
		// 取出一个状态
		law_pos = law_back.back();
		table = table_back.back();

		law_back.pop_back();
		table_back.pop_back();
		
		// 检测下一行是否有合法位置，如果有，就 插入并且生成新的皇后，并且判断成功与否，没有成功就把这次 记录
		vector<bool>::iterator pos = find(law_pos.begin(), law_pos.end(), 1);

		while (pos != law_pos.end())
		{
			//说明下一行有合法插入位置，都找出来，并且插入
			int rank = pos - law_pos.begin();
			auto temp_table = table;
			auto temp_law = vector<bool>(n, 1);
			temp_table.push_back(rank);

			if (temp_table.size() == n)
			{
				// 说明这次插入成功，已经满了，那么记录
				vector<string> temp;
				for (int k = 0; k < temp_table.size(); k++)
				{
					string s(n, '.');
					s[temp_table[k]] = 'Q';
					temp.push_back(s);
				}
				resault.push_back(temp);
			}
			else
			{
				// 没有满，说明给还有下一行，将下一行的 数字状态及 合法位置统统记录
				for (int i = 0; i < temp_table.size(); i++)
				{
                    // 计算插入元素后的合法位置
					int offset = temp_table.size()-i;
					rank = temp_table[i];

					temp_law[rank] = 0;
					if (rank - offset >= 0) temp_law[rank - offset] = 0;
					if (rank + offset < temp_law.size()) temp_law[rank + offset] = 0;
				}
				// 将下一个表格和合法规则push进栈中
				table_back.push_back(temp_table);
				law_back.push_back(temp_law);
			}
			// 本行的下一个合法位置
			pos = find(pos + 1, law_pos.end(),1);
		}
		
	} while (!table_back.empty());

	return resault;
    }
};
```

