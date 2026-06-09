
核心一点a[i][j] += n[i]*n2[j]，不过i,j是从右侧为0开始
最后在统一处理进位的情况
```
string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
			return "0";
		string res="";
		int len1, len2;
		len1 = num1.length();
		len2 = num2.length();
		vector<int>ans(len1+len2,0);
 		for (int i = 0, ci = len2 - 1; ci >= 0; ci--,i++) {
			for (int j = 0, cj = len1 - 1; cj >= 0; cj--, j++) {
				ans[i + j] += (num2[ci]-'0') *( num1[cj]-'0');
			}
		}
		int c = 0;
		for (int i = 0; i < ans.size();i++) {
			ans[i] += c;
			c = ans[i] / 10;
			ans[i] = ans[i] % 10;
		}
		if (c > 0)
			res += (c + '0');
		int index = ans.size() - 1;
		for (; ans[index] == 0; index--);  //跳过多余的0
		for (; index >= 0; index--)
			res += (ans[index] + '0');
		
		return res;
	}
```
