没有用到栈结构
- 在遍历最小长度串的同时遍历最大长度串
- 遍历完最小长度串后，遍历最大串剩下未遍历的子串

算法(以S为例)：
- 遇到#时数组下标ai-1，为-1时置为0
- 最后比较在0~ai下，2个字符数组是否完全相同
**特殊情况**：ai != bi时必定不相等
```java
class Solution {
    public boolean backspaceCompare(String S, String T) {
		char[] s = S.toCharArray();
		char[] t = T.toCharArray();
		char[] a = new char[s.length];// 用于处理T退格后的字符数组
		char[] b = new char[t.length];// 用于处理T退格后的字符数组
		int ai = 0;
		int bi = 0;
        int i;
		// 在遍历最小串时一起遍历最大串
        for (i = 0; i < t.length && i < s.length; i++) {
            //处理S
            if (s[i] != '#') {
                a[ai++] = s[i];
            } else {
                ai = ai - 1 == -1 ? 0 : ai - 1;
            }
            //处理T
            if (t[i] != '#') {
                b[bi++] = t[i];
            } else {
                bi = bi - 1 == -1 ? 0 : bi - 1;
            }
        }
		//遍历完最小串，遍历最大串剩下的字串，因为最小串已经遍历结束，不会进入循环
        while (i < s.length) {
            if (s[i] != '#') {
                a[ai++] = s[i];
            } else {
                ai = ai - 1 == -1 ? 0 : ai - 1;
            }
            i++;
        }
        while (i < t.length) {
            if (t[i] != '#') {
                b[bi++] = t[i];
            } else {
                bi = bi - 1 == -1 ? 0 : bi - 1;
            }
            i++;
        }
        //处理后的字符串长度不同，结果必定不相同
        if (ai != bi) {
            return false;
        }
        for (int i = 0; i < ai; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
}
```
以下是抽取公共方法后的简化版：
```java
class Solution {
	public static boolean backspaceCompare(String S, String T) {
		char[] s = S.toCharArray();
		char[] t = T.toCharArray();
		int ai = 0;
		int bi = 0;

		char[] a = new char[s.length];// 用于处理S退格后的字符数组
		char[] b = new char[t.length];// 用于处理T退格后的字符数组
		// 在遍历最小串时一起遍历最大串
		int minLen = t.length < s.length ? t.length : s.length;
		for (int i = 0; i < minLen; i++) {
                        //处理S
			ai = handle(s, i, a, ai);
                        //处理T
			bi = handle(t, i, b, bi);
		}
		// 遍历完最小串，遍历最大串剩下的字串，因为最小串已经遍历结束，不会进入循环
		while (minLen < s.length) {
                         //处理S
			ai = handle(s, minLen, a, ai);
			minLen++;
		}

		while (minLen < t.length) {
                        //处理T
			bi = handle(t, minLen, b, bi);
			minLen++;
		}
		if (ai != bi) {
			return false;
		}
		for (int i = 0; i < ai; i++) {
			if (a[i] != b[i]) {
				return false;
			}
		}
		return true;
	}

    //返回处理后字符数组的新长度
	private int handle(char[] origin, int orgIndex, char[] dest, int destIndex) {
		if (origin[orgIndex] != '#') {
			dest[destIndex++] = origin[orgIndex];
		} else {
			destIndex = destIndex - 1 == -1 ? 0 : destIndex - 1;
		}
		return destIndex;
	}
}
```
