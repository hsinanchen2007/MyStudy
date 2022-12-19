#### 思路：
```
len(公共前缀) <= len(最短串)
故而可以先迭代数组找到最短串S，然后把数组中的每一个字符串Si依次拎出来，
让S的值更新成S与Si的公共前缀，最终S的值就是要返回的结果。

另外，如果是个空数组，就直接返回"",这种情况一定要提前预判！！！
数组只有一个元素，搞不搞特殊都可以。But，搞，耗时是0ms；不搞，耗时是1ms
                                                          ╮(╯▽╰)╭

```
#### 举个例子：
```
比如：["category","core","caffe","cat"]
一次迭代，得到最短串"cat"，保存下标2以及长度3
二次迭代：
1.截取"category"长度为3的前缀，"cat"与"cat"一致，向下进行；
2.截取"core"长度为3的前缀，"cor"与"cat"不一致，更新"cat"为"ca",更新长度为2；
  截取"core"长度为2的前缀，"co"与"ca"不一致，更新"ca"为"c",更新长度为1；
  截取"core"长度为1的前缀，"c"与"c"一致，向下进行；
3.截取"caffe"长度为1的前缀，"c"与"c"一致，向下进行；
4.截取"cat"长度为1的前缀，"c"与"c"一致，向下进行；

```
#### 代码：
```
public static String longestCommonPrefix(String[] strs) {
	if(strs.length==0) {
		return "";
	}
	
	if(strs.length==1) {
		return strs[0];
	}

	int st = 0;// 保存最短字符串的下标
	for (int i = 0; i < strs.length; i++) {
		st = strs[st].length() <= strs[i].length() ? st : i;
	}
	int e=strs[st].length();//最短串的长度

	//因为想少用点内存，所以就没有额外定义一个字符串变量，而是用[下标+长度]来代替
	for (int i = 0; i < strs.length; i++) {//把每一个元素都拎出来			
		while (!strs[i].substring(0,e).equals(strs[st].subSequence(0, e))&&e!=0) {
		//如果没有公共前缀，就短尾，接着找，直到尸骨无存
			e--;//更新长度，减到0就结束
		}
	}

	return strs[st].substring(0,e);
}
```
