```
执行用时 : 0 ms, 在Longest Substring Without Repeating Characters的Go提交中击败了100.00% 的用户
内存消耗 : 2.6 MB, 在Longest Substring Without Repeating Characters的Go提交中击败了90.85% 的用户
```

```
func lengthOfLongestSubstring(s string) int {
    var lens, head int
    for k, _ := range s {
        t := indexs(s[head: k], s[k])
        if t == -1 {
            if lens < k - head + 1 {
	        lens = k - head + 1
	    }else {
		head = head + t + 1
	    }
	}
    }
    return lens
}

func indexs(s string, b byte) int{
    for k, _ := range s {
        if s[k] == b {
	    return k
        }
    }
    return -1
}
```




