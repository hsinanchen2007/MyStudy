### 解题思路
这题其实困扰我一个小时，虽然他是个简单题。
主要理解不清楚的地方就是：一个字符只能映射一种
什么意思呢，有个用力是这样的：
ab
aa
这个是false的。

但是
ab
bc就是true

对于用力ab，aa来说，s字符串的哈希映射是，HASHS[a] = 'a', HASHS[b] = 'a';
而t字符串的映射是hashT[a] = 'a', hashT[a] = 'b'，显然对于t字符串来说，a已经有值了，它却不等于已存的值，所以不对；
在这里我的判断是，如果hastT[x]不是-1，有值了，那么它就是唯一映射，此时hastT[x]与这时候的s[indexX]不相等，证明这个对不上，无法成为一对唯一映射，所以直接返回false。

由于直接用字符数组的值作为哈希表的下标，很容易混淆写错，还是推荐使用一个临时变量来存储字符串里的某个字符。

### 代码

```c
#define MAX 200
bool isIsomorphic(char *s, char *t)
{
	if (s == NULL && t == NULL) {
		return true;
	}

	if (s == NULL || t == NULL) {
		return false;
	}

	int sizeS = strlen(s);
	int sizeT = strlen(t);
	if (sizeS != sizeT) {
		return false;
	}

	int indexA = 0;
	int indexB = 0;
	char *hashMapS = (char *)malloc(sizeof(char) * MAX);
	char *hashMapT = (char *)malloc(sizeof(char) * MAX);
	memset(hashMapS, -1, sizeof(char) * MAX);
	memset(hashMapT, -1, sizeof(char) * MAX);

	while (indexA < sizeS) {
		if (hashMapS[(int)s[indexA]] == -1) {
			hashMapS[(int)s[indexA]] = t[indexB];
		} else if (hashMapS[(int)s[indexA]] != t[indexB]) {
			return false;
		}

		if (hashMapT[(int)t[indexB]] == -1) {
			char temp = s[indexA];
			if (hashMapS[(int)temp] != -1 && hashMapS[(int)temp] != t[indexB]) {
				return false;
			}
			hashMapT[(int)t[indexB]] = s[indexA];
		} else if (hashMapT[(int)t[indexB]] != s[indexA]) {
			return false;
		}
		indexA++;
		indexB++;
	}

	return true;
}
```