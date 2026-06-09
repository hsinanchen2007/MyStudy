### 解题思路
class Solution
private int [][] dp;
	public int strStr(String haystack, String needle) {
		int M = needle.length();
		//M为当前状态（M的状态个数取决于子字符串的长度)，256为将要遇到的字符(遇到的字符是未知的，所以要考虑所有情况)
		dp = new int [M][256];//dp数组的取值范围
		//初始化dp二维数组,即即将遇到的字符是haystack.charAt(0)是状态前进
		dp[0][needle.charAt(0)]=1;
		//初始化影子数组,更新影子数组
		int X = 0;
		//两个循环是用于更新二维数组，内循环更新遇到的字符，外循环更新当前匹配状态和影子状态
		//每找一个字母，内循环都要全部遍历一次
		for (int j = 1 ; j<needle.length() ; j++) {
			for(int c = 0 ; c<256 ; c++) {
				if (c == needle.charAt(j)) {
					dp[j][c] = j+1;
				}
				else {
					dp[j][c] = dp[X][c];
				}
			}
			X = dp[X][needle.charAt(j)];///影子状态的更新（影子状态的更新是根据子字符串来确定的）
		}
		
		int s = 0;
		for (int i = 0 ; i<haystack.length() ; i++) {
			s = dp[s][haystack.charAt(i)];
			if (s == M) 
				return i-M+1;
		}
		return -1;
		
		
		
		
	}
}

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
    /*
    一开始想利用栈方法来进行子字符串位置的查找，即先将子字符串压入到栈中，然后
    依次判断haystack每个字符是否与栈顶字符相等，相等则弹出栈顶字符，然后进行下次判断
    直到栈为空跳出循环，但是此方法运行时并没有通过，主要是因为有可能子字符串前面可能与haystack匹配，但是后面没有
    这就是造成了误差。
    第二种思路很简单，与前面一样，将haystack的每个字符与子字符串的第一个字符进行比较
    如果第一个字符相等，则从第一个字符开始截取与子字符串相同的字符串进行比较，若相等，则跳出循环
    否则则进行下一次循环。
    */
	int i = 0;
    if (haystack == needle||needle.isEmpty())
	{
		return 0;
	}
	if (!(haystack.contains(needle))){
        return -1;
    }
  else {
	for ( ; i<haystack.length() ; i++)
	{
		char c = haystack.charAt(i);
		if (c == needle.charAt(0)) {
			if (haystack.substring(i, i+needle.length()).equals(needle)) {
				break;
			}
			else {
				continue;
			}
		}
	}
	return i;
	}

    }
}
```