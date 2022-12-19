一个栈保存原子(name, count)

一个栈保存括号(left/right, idx)，idx是索引该括号对应原子栈的位置。

```C++
class Solution {
public:
	struct Atom
	{
		Atom(char c)
		{
			name.push_back(c);
		}

		string name;
		int count = 1;
	};

	struct Parenthesis
	{
		Parenthesis (bool left, int idx) : left(left), idx(idx) {}

		bool left = true;
		int idx = 0;	// 索引原子栈的位置
	};


	string countOfAtoms(string formula) {
		vector<Atom> atoms;	// 栈，从左向右保存原子
		vector<Parenthesis> pars;	// 栈，从左向右保存括号

		// 记录要乘以的原子数目，0表示隐式的数字1
		int number = 0;

		// 执行原子数目相乘
		auto handleNumber = [&]() {
			// 若数字恰好在右括号后面，对括号里的所有原子乘以数字
			if (!pars.empty() && pars.back().left == false && pars.back().idx == atoms.size())
			{
				// 对数字1直接将两个括号pop
				if (number == 0 || number == 1)
				{
					pars.pop_back();
					pars.pop_back();
				}
				else
				{
					Parenthesis right = pars.back();
					pars.pop_back();
					Parenthesis left = pars.back();
					pars.pop_back();

					for (int i = left.idx; i < right.idx; ++i)
					{
						atoms[i].count *= number;
					}

					number = 0;
				}
			}
			// 数字只在单个原子后面
			else
			{
				if (number != 0)
				{
					atoms.back().count *= number;
					number = 0;
				}
			}
		};

		for (int i = 0; i < formula.size(); ++i)
		{
			char c = formula[i];

			if (c == '(')
			{
				handleNumber();
				pars.emplace_back(true, atoms.size());
				continue;
			}
			else if (c == ')')
			{
				handleNumber();
				pars.emplace_back(false, atoms.size());
				continue;
			}


			if (atoms.empty())
			{
				atoms.emplace_back(c);
				continue;
			}

			Atom &topAtom = atoms.back();

			// 新的原子
			if ('A' <= c && c <= 'Z')
			{
				handleNumber();
				Atom atom(c);
				atoms.push_back(atom);
			}
			else if ('a' <= c && c <= 'z')	// 仍然是上一个原子
			{
				topAtom.name.push_back(c);
			}
			else if ('0' <= c && c <= '9')
			{
				if (number == 0)	// 新的数字
					number = c - '0';
				else    // 仍然是上一个数字
				{
					number = number * 10 + c - '0';
				}
			}
		}

		handleNumber();

		// 合并相同原子，字典序排列
		map<string, int> maps;
		for (auto &atom : atoms)
		{
			auto iter = maps.find(atom.name);
			if (iter == maps.end())
			{
				maps.emplace(atom.name, atom.count);
			}
			else
			{
				iter->second += atom.count;
			}
		}

		std::string ans;
		for (auto &e : maps)
		{
			ans.append(e.first);
			if (e.second != 1)
			{
				ans.append(to_string(e.second));
			}
		}
		return ans;
	}
};
```
