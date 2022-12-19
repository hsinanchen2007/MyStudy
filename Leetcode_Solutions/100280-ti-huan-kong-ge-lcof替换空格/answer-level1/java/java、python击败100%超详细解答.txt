## 解题分析
这道题比较简单，但是有点意外的是，我做完之后竟然和标准答案一模一样，在力扣也是双100%；

这个是个替换字符串内容的题，显然，各种语言都提供了API，当然如果我们这么做就失去了算法的意义；

首先我们要选定一个容器来承载替换之后的字符，这个容器显然是一个字符数组，那么这个数组我们长度选择多少呢？这是个关键，我们可以看到，遇到一个空格之后要替换成%20，也就是一个字符替换成三个字符，那么就算题目中所有的字符都是空格，我们定义容器的长度为3倍后的长度，也完全够用了；

接下来就比较简单了，我们只需要遍历原字符串，如果遇到空格，就连续加入三个字符%、2、0，否则就把原来的字符加进去即可，这样我们会得到一个新的字符数组，但是这个数组有可能最后几位没有用到，我们用遍历时候的索引截取一下重新构建即可；

## 代码
ps：这里笔者使用的jdk为1.8、Python3.7版本

- java实现
	```java
	class Solution {
	    public String replaceSpace(String s) {
	        char[] arr = new char[3 * s.length()];
	        int index = 0;
	        for (char c : s.toCharArray()) {
	            if (' ' == c) {
	                arr[index++] = '%';
	                arr[index++] = '2';
	                arr[index] = '0';
	            } else {
	                arr[index] = c;
	            }
	            index++;
	        }
	        return new String(arr, 0, index);
	    }
	}
	```

- Python实现

	```python
	class Solution:
	    def replaceSpace(self, s: str) -> str:
	        arr = [0] * (3 * len(s))
	        index = 0
	        for i in s:
	            if i == ' ':
	                arr[index] = '%'
	                index += 1
	                arr[index] = '2'
	                index += 1
	                arr[index] = '0'
	            else:
	                arr[index] = i
	            index += 1
	
	        return ''.join(arr[:index])
	```