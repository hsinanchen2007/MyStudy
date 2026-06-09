这本质上是一道数学题，假设数组长度为Len，需要分成n行进行Z字排列，则如下：
1          
2 ----------2*n-2
. --------.
. --n+1
n

其中1至2*n-2为一组，则按照这种分法把数组从左到右分成大小为2*n-2的一个个分组，如例子中将”LEETCODEISHIRING”，按照3行进行Z字排列可以分成这些小组：
LEET  CODE  ISHI  RING

接下来的看Z字排列的最终效果图：
L------C------I------R
E--T--O--E--S--I--I--G
E------D------H----N
对于输出：
1  首先输出第1行，此时对应每个分组的第1个元素。
2  再输出第2行，此时对应每个分组的第2个和4个元素。
2  再输出第3行，此时对应每个分组的第3个元素。
从上述的描述可以抽象出输出每行时候的算法：
1 输出第x行时，首先输出每个分组中和行号对应位置x的元素，如果该元素不在数组中，则不输出。
2 再输出分组内位置为n*2-x的元素，如果该元素不在数组中，或者x=n*2-x，则不输出。

该算法的时间复杂度为O(Len),利用这个写法提交的go代码的耗时为0ms。

```
func convert(s string, numRows int) string {
	
	//处理简单情况
	if 1>=numRows || 0>=len(s){
		return s
	}
	
	//确定每组元素数目和分组数
	var NumForGroup int = numRows*2-2
	var GroupCount int = len(s)/NumForGroup
	if 0 != len(s)%NumForGroup{
		GroupCount ++
	}
	//依次打印每行
	var RetBuf []byte
	for i:=0;i<numRows;i++{
		for CurGp:=0;GroupCount>CurGp;CurGp++{
			CurPos := CurGp*NumForGroup+i
			if len(s)<=CurPos{
				continue
			}
			//添入开始位置
			RetBuf = append(RetBuf, s[CurPos])
			//添入对称位置
			MirPos := CurGp*NumForGroup+(numRows*2-(i+1)-1)
			if len(s)>MirPos && CurGp*NumForGroup+NumForGroup>MirPos && MirPos!=CurPos{
				RetBuf = append(RetBuf, s[MirPos])
			}
		} 
	}
	//返回
	return string(RetBuf)
}
```
