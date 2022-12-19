遇到   '('   就递归，比较容易出错的是指针绝对位置和相对位置的处理
绝对位置的存储是为了在括号运算完成后能跳到   ')'   结束的位置

```
class Solution {
	public int calculate(String s) {
		return helper(s, 0)[0];
	}

	public int[] helper(String s, int begin) {
		// res[0]为计算的数字，res[1]为指针的绝对位置，绝对位置的存储是为了在括号运算完成后能跳到')'结束的位置
		int[] res = { 0, begin };
		// flag用来表示上一个符号是'+'还是'-'
		boolean flag = true;
		for (int i = 0; i < s.length(); i++) {
			char cur = s.charAt(i);
			if (cur == ' ')
				continue;
			else if (cur == '(') {
				// 因为这里用了substring,进入方法后的指针位置是相对位置，所以用begin + i + 1存下绝对位置
				int[] temp = helper(s.substring(i + 1), begin + i + 1); 
				if (flag)
					res[0] += temp[0];
				else
					res[0] -= temp[0];
				i = temp[1] - begin; // 因为之后的运算要以相对位置进行，所以要以绝对位置减去当前')'对应的'('的绝对位置，得到将要使用的相对位置
			} else if (cur == ')') {
				res[1] += i; // 在子运算结束的时候，更新一下绝对位置
				return res;
			} else if (cur == '+')
				flag = true;
			else if (cur == '-')
				flag = false;
			else {
				int num = 0;
				while (i < s.length() && (s.charAt(i) <= '9' && s.charAt(i) >= '0' || s.charAt(i) == ' ')) {
					if (s.charAt(i) == ' ') {
						i++;
						continue;
					}
					num = num * 10 + s.charAt(i) - '0';
					i++;
				}
				i--;

				if (flag)
					res[0] += num;
				else
					res[0] -= num;
			}
		}
		return res;
	}
}
```
