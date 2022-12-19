### 解题思路
这道题乍一看让人摸不着头脑，但是其实也就是一个匹配最长相同字符记录长度与该字符然后拼接成串的问题。我的代码可能复杂度还比较高，只是提供一个思路，不足之处希望各路大佬教教我orz

先构建一个字符串列表，然后填充前面的已知的四个*（我们观察到其实这个题，n最大只有30，那如果开心或许可以全部画出来填进去，复杂度O(1) hhhhhh）* 。于是我们就从第五个字符串开始遍历到第n个，每个都取i-1个字符串遍历。遍历的时候记录连续出现次数cnt和该字符，拼接在我们期待得到的第i个字符串（初始为空串）的最后。然后把这个字符串填进字符串列表里。最后返回第n个字符就好。

//Go没有像python那个简单的itoa表示方法，现场学习了一下，每天一点新知识~~

### 代码

```golang
func countAndSay(n int) string {
    strlist:=[30]string{"1","11","21","1211"}
	for i:=4;i<n;i++{
		cnt:=1
		string_temp := ""
		for j:=1;j<len(strlist[i-1]);j++{
			if strlist[i-1][j]==strlist[i-1][j-1]{
				cnt+=1
			}else{
				string_temp+=strconv.Itoa(cnt)+strlist[i-1][j-1:j]
				cnt=1
			}
		}
		string_temp+=strconv.Itoa(cnt)+strlist[i-1][len(strlist[i-1])-1:len(strlist[i-1])]
		strlist[i] = string_temp
	}
	return strlist[n-1]
}
```