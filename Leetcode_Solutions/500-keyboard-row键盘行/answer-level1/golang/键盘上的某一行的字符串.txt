### 解题思路
此处撰写解题思路

### 代码

```golang
func findWords(words []string) []string {
	res:=make([]string,0)
	for _,v:=range words{
		ori:=v
		v=strings.ToLower(v)
		flag:=0
		for _,m:=range v{
			fmt.Printf("%c",m)
			fmt.Println("      flag : ",flag)
			switch m{
			case 'q','w','e','r','t','y','u','i','o','p':
				if flag!=0&&flag!=1{
					flag=4//当 m 是属于这一行的字符，但是 falg的值 又不是这一行的标志时，将flag设置为4
					break
				}
				flag=1

			case 'a','s','d','f','g','h','j','k','l':
				if flag!=0&&flag!=2{
					flag=4
					break
				}
				flag=2
			case 'z','x','c','v','b','n','m':
				if flag!=0&&flag!=3{
					flag=4
					break
				}
				flag=3
			default:
				fmt.Println()
			}

		}
		if flag!=0&&flag!=4{
			res= append(res, ori)
		}
	}
	return res
}

```