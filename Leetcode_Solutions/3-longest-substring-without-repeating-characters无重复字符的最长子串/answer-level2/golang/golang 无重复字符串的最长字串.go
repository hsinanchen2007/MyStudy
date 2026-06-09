```
func lengthOfLongestSubstring(s string) int {
	max_len_res := make(chan int)

	b:=[]byte(s)
	fmt.Println(b)
	max_len:=0
	for k,v:=range b {
		go getLenth(v,b[k:],max_len_res)
	}

	for range b {
		x := <-max_len_res
		if max_len < x{
			max_len =x
		}
	}

	return  max_len
}

func getLenth(m byte,c []byte,r chan int){
	var res []byte
	for _,v:=range c {
		//判断值是否存在
		exist_res:=exist(res,v)
		if exist_res ==false{
			res= append(res,v)
		}else {
			break
		}
	}
	r <- len(res)
}

func exist(res []byte,m byte)bool{
		for _,v:=range res  {
			if 	v == m{
				return  true
			}
		}
	return  false
}

```