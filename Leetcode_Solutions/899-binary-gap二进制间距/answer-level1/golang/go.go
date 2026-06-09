### 解题思路
此处撰写解题思路

### 代码

```golang
func binaryGap(N int) int {
    //判断 当前位置的前面 有没有 1，如果没有 就是false，出现过1就是true
	flag:=false
	start:=0
	index:=0
	res:=0
	for N>0{
		tmp:=N&1
		
		if tmp==1{
            //如果前面出现过1，那么当前位置也是1，两者之间的距离 跟前面的res比较
			if flag{
				if res<index-start{
					res=index-start
				}
				start=index
			}else{
                //如果前面没有出现过1，则 以当前为起点
				flag=true
				start=index
			}
		}
		N=N>>1
		index++
	}
	return res
}
```