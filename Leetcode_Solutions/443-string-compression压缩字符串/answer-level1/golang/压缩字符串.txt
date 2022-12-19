### 解题思路
此处撰写解题思路
借鉴他人的思路，写一个自己比较好理解的方法

### 代码

```golang
func compress(chars []byte) int {

	write :=0
	read :=0
	pointer := chars[write]
	for read< len(chars){
		if pointer==chars[read]{
			if read== len(chars)-1{//此时已经读到了最后一位，不能再往后面读了
				sameCharNum:=read-write+1//先计算 重复的char的个数,此时 读到最后一位的时候 刚好 与pointer相同，所以这里的 相同字母的个数 在read-write上还要+1，因为循环 到此结束，再也找不到下一个不同的字母
				write++//从当前的pointer的后面一位开始写
				if sameCharNum>1{
					sameChar:=strconv.Itoa(sameCharNum)
					for i,_:=range sameChar{
						chars[write]=sameChar[i]
						write++
					}
					//写完之后write 指到了写完了相同数字之后的第一个索引
					chars=chars[:write]
				}
				fmt.Println(chars)
				return len(chars)
			}
			read++
		}else{
			sameCharNum:=read-write//先计算 重复的char的个数
			write++//从当前的pointer的后面一位开始写
			if sameCharNum>1{
				sameChar:=strconv.Itoa(sameCharNum)
				for i,_:=range sameChar{
					chars[write]=sameChar[i]
					write++
				}
				//写完之后write 指到了写完了相同字符数字之后的第一个索引
				chars=append(chars[:write],chars[read:]...)
			}
			read=write
			pointer=chars[write]
		}
	}
	
	return len(chars)
}
```