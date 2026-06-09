

### 代码

```cpp
class Solution {
public:
	string getHint(string secret, string guess) 
	{
		unordered_map<char, int> solve;
		int a = 0, b = 0;
		for (int i = 0; i < secret.size(); i++)
		{
			if (secret[i] == guess[i])
				a++;
			solve[secret[i]]++;
			
		}
		for (int i = 0; i < guess.size(); i++)
		{
			if (solve[guess[i]] > 0)
			{
				b++;
				solve[guess[i]]--;
			}
		}
		if (a > 0)
			b = b - a;
		return to_string(a) + 'A' + to_string(b) + 'B';
	}
};
```