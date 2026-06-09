### 解题思路
拿输入的字符串和名字经行比较，相符的话两个下标都+1，如果不相符分两种情况：
1、输入字符串当前位置与名字字符串的前一字符相同，对输入字符串的下标+1（这里可以用个循环一直判断，消除输入字符串多次重复的字符）
2、当前位置不相符，且不满足1情况，返回false
程序完整执行完，说明输入的符合要求返回true

### 代码

```c
bool isLongPressedName(char * name, char * typed){
	int i = 0;
	int n = strlen(name);
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (name[i] == typed[j])
        {
			j++;
        }
		else if (i != 0 && name[i - 1] == typed[j])
		{
			while (name[i - 1] == typed[j])
			{
				j++;
			}
            i--;//当前字符未匹配到，但是for循环i会+1.在这里减回去
		}
		else
		{
			return false;
		}
	}
	return true;
}

```