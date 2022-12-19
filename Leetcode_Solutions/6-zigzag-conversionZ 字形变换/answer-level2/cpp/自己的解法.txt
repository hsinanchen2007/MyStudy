思想：寻找排列之后的字符串的字符和原位置的数值规律，用一个数组存储排列之后各个元素的位置。然后遍历再还原字符串即可。

结果：
执行用时 :8 ms, 在所有 cpp 提交中击败了96.89% 的用户
内存消耗 :10.9 MB, 在所有 cpp 提交中击败了83.88%的用户

```
string convert(string s, int numRows) {
		// 初始条件判断
		// s为空
		size_t length = s.size();
		if (!length)
			return s;
		// numRows等于length的时候，返回原s，大于s的时候，返回什么？
		if (numRows <= 1 || numRows > length)
			return s;

		unsigned int* temp_arr = new unsigned int [length];

		// may not need to fill temp_arr
		for (size_t i = 0; i < length; i++)
			temp_arr[i] = 0;

		// cost little space

		// 得出步进值->分解步进值->按照步进值取数组下标->存储到目标数组->遍历读取

		// 步进值 delta
		unsigned int delta = (numRows - 1) * 2;
		unsigned int index = 0;
		bool i_changed = false;
		// 分解步进值 -- 步进值分解之后只有两种形式，其之和等于步进值

		// process:
		// 需要两个循环，外层循环对 (i=0;i<numRows;i++)进行循环；
		// 内层循环填入数据，被填入的temp_arr的索引位置实时更新。
		for (size_t i = 0; i < numRows; i++)
		{
			unsigned int arr[] = { delta - (i * 2),delta - (delta - (i * 2)) };

			unsigned int backup = i;

			(!i) ? temp_arr[index] = i : (i_changed)?temp_arr[++index] = i:0;
			unsigned int pick = 0;
			while (true)
			{
				unsigned int value = i + arr[pick];
				if (value >= length)
					break;
				else
				{
					if (!arr[pick])
					{
						pick = (pick) ? 0 : 1;
						continue;
					}
					else
					{
						i = value;
						index++;
						temp_arr[index] = i;
						(!pick) ? pick = 1 : pick = 0;
					}
				}

			}
			i = backup;
			i_changed = true;
		}



		// at last

		string result = "";
		for (size_t i = 0; i < length; i++)
		{
			result += s[temp_arr[i]];
		}
		return result;
	}
```
