### 解题思路
此题可用动态规划写，从后往前遍历，前一个值受后一个值的影响。这版代码比较粗糙，是否有更优化的代码有时间再看吧。
### 代码

```golang
func addBinary(a string, b string) string {
//动态规划 res[k]=sliceA[k]+sliceB[k]+jinwei[k+1],jinwei[k]=1 if sliceA[k]=='1'&&sliceB[k]=='1' else 0
	var sliceA,sliceB []byte
	if len(a)>len(b){
		prexSlice:=make([]byte,len(a)-len(b))
		for i:=0; i<len(prexSlice);i++ {
			prexSlice[i]='0'
		}
		sliceB=append(prexSlice,[]byte(b)...)
		sliceA=[]byte(a)
	}else if len(a)<len(b) {
		prexSlice:=make([]byte,len(b)-len(a))
		for i:=0; i<len(prexSlice);i++ {
			prexSlice[i]='0'
		}
		sliceA=append(prexSlice,[]byte(a)...)
		sliceB=[]byte(b)
	}else{
		sliceA=[]byte(a)
		sliceB=[]byte(b)
	}
	//动态规划 res[k]=sliceA[k]+sliceB[k]+jinwei[k+1],jinwei[k]=1 if sliceA[k]=='1'&&sliceB[k]=='1' else 0
	resSlice:=make([]byte,len(sliceA))
	jinwei:=make([]byte,len(sliceA)+1)
	jinwei[len(jinwei)-1]='0'
	for i:=len(sliceA)-1;i>=0 ;i-- {
		if sliceA[i]=='1'&&sliceB[i]=='1'&&jinwei[i+1]=='1' {
			resSlice[i]='1'
			jinwei[i]='1'
		}else if sliceA[i]=='1'&&sliceB[i]=='1'&&jinwei[i+1]=='0'{
			resSlice[i]='0'
			jinwei[i]='1'
		}else if sliceA[i]=='1'&&sliceB[i]=='0'&&jinwei[i+1]=='1'{
			resSlice[i]='0'
			jinwei[i]='1'
		}else if sliceA[i]=='0'&&sliceB[i]=='1'&&jinwei[i+1]=='1'{
			resSlice[i]='0'
			jinwei[i]='1'
		}else if sliceA[i]=='1'&&sliceB[i]=='0'&&jinwei[i+1]=='0'{
			resSlice[i]='1'
			jinwei[i]='0'
		}else if sliceA[i]=='0'&&sliceB[i]=='1'&&jinwei[i+1]=='0'{
			resSlice[i]='1'
			jinwei[i]='0'
		}else if sliceA[i]=='0'&&sliceB[i]=='0'&&jinwei[i+1]=='1'{
			resSlice[i]='1'
			jinwei[i]='0'
		}else if sliceA[i]=='0'&&sliceB[i]=='0'&&jinwei[i+1]=='0'{
			resSlice[i]='0'
			jinwei[i]='0'
		}
	}
	if jinwei[0]=='1'{
		return string(append([]byte{'1'},resSlice...))
	}else {
		return string(resSlice)
	}
}

```