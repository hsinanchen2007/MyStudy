### 解题思路

容斥原理: 字典序介于 [s1, s2] 之间的 = 不超过 s2 的 - 不超过 s1 的 + 等于 s1 的

然后动态规划求解字典序不超过字符串 `str` 并且不包含子串 `evil` 的字符串的数量.

### 代码

```cpp
typedef long long int64;
class Solution {
private:
	const static int64 P = 1000000007L;
    bool calc = false;
    int next[51] = {0};

	// 计算在 str 的 suffix 后缀添加一个字符 c 之后
	// 最长的相等的前缀后缀长度
	int getNext(const string &str, int suffix, char c) {
        int n = str.size();
        if (!calc) {
            for (int i = 1, j = 0; i < n; next[++i] = j) {
                while (j && str[i] != str[j]) j = next[j];
                if (str[i] == str[j]) j++;
            }
            calc = true;
        }
        while (suffix && str[suffix] != c) suffix = next[suffix];
        return suffix + (str[suffix] == c);
	}

	// 计算字典序不超过 s 并且不包含 evil 子串的字符串的数量
	int64 findGoodStrings(const string &s, const string &evil) {
		// f[i][j][0] 表示长度为 i 的, 后缀与 evil 前缀 j 相同的, 字典序小于 s 的前缀 i 的字符串数量
		// f[i][j][1] 表示长度为 i 的, 后缀与 evil 前缀 j 相同的, 字典序等于 s 的前缀 i 的字符串数量
		static int64 f[501][50][2];
		memset(f, 0, sizeof f);
		// 初始化仅有 f[0][0][1] = 1
		f[0][0][1] = 1;
        int n = s.size();
        int m = evil.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// 不是考虑 f[i][j][k] 由谁转移/怎么计算
				// 而是考虑 f[i][j][k] 加上一个字符可以加到哪个状态上
				// f[i][j][k] 必然加到 f[i + 1][nj][nk] 上
				// nk 由 k 和加的字符决定
				// nj 比较复杂, 需要看加上那个字符后, 后缀和 evil 的前缀相同的部分最长变成了多少
				// 正好可以使用 KMP 的 next 数组来进行计算
				for (char c = 'a'; c <= 'z'; c++) {  // 枚举添加了哪个字符
					int nj = getNext(evil, j, c);	
					if (nj == m) continue;  // 加上字符 c 之后等于 evil 了, 就不能加, 跳过
                    // 分别考虑 f[i][j][0] 和 f[i][j][1] 加上字符 c 后会加到哪个状态上 (nj 已经计算好, 还需要看 nk)
                    // f[i][j][0] 字典序已经小于, 所以无论加上什么字符都可以加到 f[i + 1][nj][0] 上
                    f[i + 1][nj][0] = (f[i + 1][nj][0] + f[i][j][0]) % P;
                    // f[i][j][1] 字典序等于 s 的前缀 i
                    // 如果加的字符和 s[i] 相等, 那么仍然字典序相等, 即转移到 f[i + 1][nj][1]
                    // 如果加的字符小于 s[i], 那么加上后字典序小于 s 的前缀 i + 1, 即转移到 f[i + 1][nj][0]
                    // 而如果大于, 则无法从 f[i][j][1] 转移到其他状态
                    if (c == s[i]) {
                        f[i + 1][nj][1] = (f[i + 1][nj][1] + f[i][j][1]) % P;
                    } 
                    else if (c < s[i]) {
                        f[i + 1][nj][0] = (f[i + 1][nj][0] + f[i][j][1]) % P;
                    }
				}
			}
		}

		int64 res = 0;
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 2; k++) {
				res = (res + f[n][j][k]) % P;
			}
		}

		return res;
	}

public:
    int findGoodStrings(int n, const string &s1, const string &s2, const string &evil) {
    	int64 le2 = findGoodStrings(s2, evil);
    	int64 le1 = findGoodStrings(s1, evil);
    	int64 eq1 = s1.find(evil) == s1.npos;
		return (int) ((le2 - le1 + eq1 + P) % P);
    }
};
```