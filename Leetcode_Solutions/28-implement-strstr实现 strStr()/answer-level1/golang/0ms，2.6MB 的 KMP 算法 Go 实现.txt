
![image.png](https://pic.leetcode-cn.com/03df8572083f9f2f45892c0f256f0342c952629073954cd691941afe6b3a0c16-image.png)

这题没什么意思，找了个 KMP 代码，改了改交上去了，代码懒得优化了，看看就好

代码：
```
//传统next数组
func getNext(p string) []int {
 
	pLen := len(p)
	next := make([]int, pLen, pLen)
	next[0] = -1
	next[1] = 0
	i := 0
	j := 1
	for j < pLen-1 { //因为next[pLen-1]由s[i] == s[pLen-2]算出
		if i == -1 || p[i] == p[j] { //-1代表了起始位不匹配，i=0,s[0]!=s[j]=>i=next[0]=-1
			i++
			j++
			next[j] = i
		} else {
			i = next[i]
		}
	}
	return next
}
 
//优化next数组
func getNextOptimize(p string) []int {
	pLen := len(p)
	next := make([]int, pLen, pLen)
	next[0] = -1
	next[1] = 0        
	i := 0
	j := 1
	for j < pLen-1 { //因为next[pLen-1]由s[i] == s[pLen-2]算出
		if i == -1 || p[i] == p[j] { //-1代表了起始位不匹配，i=0,s[0]!=s[j]=>i=next[0]=-1
			i++
			j++
			if p[i] != p[j] { //因为出现在j位置不匹配的话会跳到next[j]=i位置去匹配,p[i] == p[j]肯定又是不匹配（优化核心点）
				next[j] = i
			} else {
				next[j] = next[i]
			}
 
		} else {
			i = next[i]
		}
	}
	return next
}
 
func KmpSearch(s, p string) int {
	i, j := 0, 0
	pLen := len(p)
	sLen := len(s)
	next := getNext(p)
	for i < sLen && j < pLen {
		if j == -1 || s[i] == p[j] { //s[i]!=s[0]=>j=next[0]=-1,第0位不匹配所以i++，j++;j=0
			i++
			j++
		} else {
			j = next[j]
		}
	}
	if j == pLen {
		return i - j
	} else {
		return -1
	}
}

func strStr(haystack string, needle string) int {
    if len(needle) == 0 {
        return 0
    }
    if len(haystack) == 0 || len(haystack) < len(needle) {
        return -1
    }
    if len(needle) == 1 {   // 子串长度=0 时单独判断
        i:=0
        for ; i<len(haystack); i++ {
            if haystack[i] == needle[0] {
                break
            }
        }
        if i < len(haystack) {
            return i
        } else {
            return -1
        }
    }
    
    return KmpSearch(haystack, needle)
}
```

参考资料：[KMP算法golang实现](https://blog.csdn.net/anliayx/article/details/86495826)