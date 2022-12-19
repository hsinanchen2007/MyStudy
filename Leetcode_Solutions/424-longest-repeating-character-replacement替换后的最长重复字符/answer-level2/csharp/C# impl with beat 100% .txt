
### 代码

```csharp
public class Solution
{
	public int CharacterReplacement(string s, int k)
	{
		if (s == null || s.Length == 0)
			return 0;

		int l = 0, r = 0;
		int[] letters = new int[26]; // a mapping for char -> char count
		int max_letter = 0; // the index of the max amount char.
		int res = 0;

		while (r < s.Length)
		{
			letters[s[r] - 'A']++;
			if (letters[s[r] - 'A'] > letters[max_letter])
				max_letter = s[r] - 'A';
			r++;

			if (r - l - letters[max_letter] > k)
			{
				letters[s[l] - 'A']--;
				l++;
			}
			res = Math.Max(res, r - l);
		}
		return res;
	}
}
```
![Snipaste_2019-12-26_22-20-54.jpg](https://pic.leetcode-cn.com/594a066b6a7bcccdf31441adf44c94e2dc2b7a9216f439512cb7ba40f066da8a-Snipaste_2019-12-26_22-20-54.jpg)
