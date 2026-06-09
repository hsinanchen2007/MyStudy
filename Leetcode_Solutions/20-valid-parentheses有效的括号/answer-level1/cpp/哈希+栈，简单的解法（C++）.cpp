首先奇数永远无法匹配，排除奇数和空字符串情况

	if (s.length() <= 0) {
		return true;
	}

	//奇数一定不匹配
	if (s.length() % 2 != 0) {
		return false;
	}
括号为键,数字为值，大于0进栈，小于0匹配，和为0匹配成功，否则匹配失败
	map<char, int> maps;
	maps['('] = 1;
	maps['{'] = 2;
	maps['['] = 3;

	maps[')'] = -1;
	maps['}'] = -2;
	maps[']'] = -3;
    vector<char> stacks;

    例如 '(' 值为1，大于0进栈(stacks),当碰到')'（小于0）时,取出最后一个数进行相加，如果等于0匹配成功
    for (int i = 0; i < s.length(); i++) {
		char temp = s.at(i);
		if (maps[temp] > 0) {
			stacks.push_back(temp);
		}
		else {
            //如果没有数可以与之匹配 返回false
			if (stacks.size() <= 0) {
				return false;
			}

			char sec_temp = stacks[stacks.size() - 1];
            //匹配成功 弹出最后一个数
			if (maps[temp] + maps[sec_temp] == 0) {
				stacks.pop_back();
			}
			else {
				break;
			}
		}
	}
    //如果未匹配完成
	if (stacks.size() > 0)
		return false;

	return true;
}
完整代码如下:

bool isValid(string s) {

	if (s.length() <= 0) {
		return true;
	}

	//奇数一定不匹配
	if (s.length() % 2 != 0) {
		return false;
	}

	map<char, int> maps;
	maps['('] = 1;
	maps['{'] = 2;
	maps['['] = 3;

	maps[')'] = -1;
	maps['}'] = -2;
	maps[']'] = -3;

	vector<char> stacks;
	for (int i = 0; i < s.length(); i++) {
		char temp = s.at(i);
		if (maps[temp] > 0) {
			stacks.push_back(temp);
		}
		else {

			if (stacks.size() <= 0) {
				return false;
			}

			char sec_temp = stacks[stacks.size() - 1];
			if (maps[temp] + maps[sec_temp] == 0) {
				stacks.pop_back();
			}
			else {
				break;
			}
		}
	}

	//如果未匹配完成
	if (stacks.size() > 0)
		return false;

	return true;
}

执行用时 :0 ms, 
在所有 C++ 提交中击败了100.00%的用户
内存消耗 :
6.6 MB
, 在所有 C++ 提交中击败了100.00%的用户