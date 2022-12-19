### 解题思路
此处撰写解题思路

### 代码

```golang
type data struct{
	num int
	len int
}
func findLUSlength(strs []string) int {
	//如果所有的字符串 长度都相同，且 相同的字符串 都大于等于2个，则没有最大子序列，如果存在单个字符串，与其他任何字符串都不同，则该字符串就是最大特殊子序列
	//如果所有字符串的长度，并不是唯一的数字，则长度最大的字符串就是 最大 特殊子序列
	//重复出现多次的字符串 不能作为最大子序列
	//仅仅出现过一次的字符串可能是最大子序列，但是该字符串 不能是其他字符串的 子串

	if len(strs)==0{
		return -1
	}

	strMap:=make(map[string]data)
	for _,v:=range strs{
		if _,ok:=strMap[v];ok{
			tmp:=data{}
			tmp.len= len(v)
			tmp.num=strMap[v].num+1
			strMap[v]=tmp
            continue
		}
		d:=data{}
		d.num= 1
		d.len= len(v)
		strMap[v]=d
	}
    fmt.Println(strMap)
	//先把所有的num=1的字符串按照长度由大到小排列


	for len(maxStr(strMap))>0{
		x:=maxStr(strMap)
		v:=strMap[x]//只出现过1次的 字符串
		flag:=true
		for j,vv:=range strMap{
			if x==j{
				continue
			}
			if vv.len<=v.len{
				continue
			}else{
				if isChild(j,x){
					flag=false
					break
				}
			}
		}
		if flag{
			return v.len
		}else{//如果这个字符串 是 map中的某个字符串的子串，也就不满足条件，那么将map中的这个字符串为key的元素删掉
			delete(strMap,x)
		}



	}

	return -1
}

//返回 map中 num为1，也就是只出现过一次，并且 map中 v.len最大的字符串
func maxStr(x map[string]data) string{
	res :=""
	for i,v:=range x{
		if v.num==1&&len(i)> len(res){
			res =i
		}
	}
	return res
}

//判断 son 是不是 father的子串
func isChild(father string,son string)bool{
	//nums:=[len(son)]int{}
	k:=0
	//var flag bool
	for i:=0;i< len(son);i++{
		v:=son[i]//拿son中的每一个字符进入 father中遍历，遍历到了，就记下 下标k，下次再遍历从 k+1 开始遍历father
		flag:=false
		for j:=k;j< len(father);j++{
			if v==father[j]{
				flag=true
				k=j+1
				break
			}
		}
		if !flag{
			return false
		}
	}
	return true
}

```