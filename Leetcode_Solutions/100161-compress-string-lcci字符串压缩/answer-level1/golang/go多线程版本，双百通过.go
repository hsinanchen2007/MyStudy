### 解题思路
1. 数据的切分
2. 小数据的并发压缩(直接用“+”号对字符串的方式会导致大量的string创建、销毁和内存分配，可用strings.Builder进行优化)
3. 数据的合并(数据合并要注意边界的处理) 

### 实现代码
```go
var (
	wg sync.WaitGroup
	chs chan []string = make(chan []string, 10)
)

func compressString(S string) string {

	s_len := len(S)

	if s_len < 1 {
		return ""
	}
	//对应切割的数组
	spilt_arr := []string{}
	// 每个块期望的大小
	hope_block := 5000

	// 长度大于10000就使用多线程进行压缩
	if s_len > 10000 {
		i := 1
		for i*hope_block < s_len {
			spilt_arr = append(spilt_arr, S[(i-1)*hope_block:i*hope_block])
			i++
		}
		spilt_arr = append(spilt_arr, S[(i-1)*hope_block:])
	}else{
		spilt_arr = append(spilt_arr, S)
	}


	for id, item := range spilt_arr {
		wg.Add(1)
		go sigleCompress(item, id)
	}
	wg.Wait()

	hash_map := make(map[string]string, len(spilt_arr))
	for i:=0; i< len(spilt_arr); i++{
		item_data := <-chs
		hash_map[item_data[0]] = item_data[1]
	}

	ret_res,_ := hash_map["0"]
	//合并，并且头尾特殊处理
	for i := 1; i<len(hash_map); i++{
		current_item, _ := hash_map[strconv.Itoa(i)]

		//提取前面字符串的最后一个元素
		index_element := len(ret_res) - 3
		for ret_res[index_element] >= '0' && ret_res[index_element] <= '9'{
			index_element -= 1
		}

		if ret_res[index_element] == current_item[0] {

			before_num, err:= strconv.Atoi(string(ret_res[index_element+1:]))
			if err != nil {
				panic(err)
			}

			//提取后面一个元素的num
			last_index := 2
			//解决越界问题
			for last_index < len(current_item) && current_item[last_index] >= '0' && current_item[last_index] <= '9'{
				last_index += 1
			}

			after_num, err := strconv.Atoi(string(current_item[1:last_index]))
			if err != nil {
				panic(err)
			}

			ret_res = ret_res[:index_element+1] + strconv.Itoa(before_num+after_num) + current_item[last_index:]

		}else{
			//元素不同直接拼接
			ret_res = ret_res + current_item
		}

	}

	if len(ret_res) >= len(S) {
		return S
	}else{
		return ret_res
	}

}

func sigleCompress(S string, id int)  {
	defer wg.Done()

	var str_buffer strings.Builder
	c_len := 1

	//上一个字符的值
	c_char := S[0]

	for k := 1; k < len(S); k++ {
		if S[k] == c_char {
			c_len += 1
		}else{
			str_buffer.WriteByte(c_char)
			str_buffer.WriteString(strconv.Itoa(c_len))
			c_char = S[k]
			c_len = 1
		}
	}
	//处理最后的数据
	str_buffer.WriteByte(c_char)
	str_buffer.WriteString(strconv.Itoa(c_len))
	chs <- []string{strconv.Itoa(id), str_buffer.String()}
}
```
### 双百通过
![strcompress.png](https://pic.leetcode-cn.com/68b42495faccd0931b56ab73a089347c2e3aba252cd4d6ad85fa6b35d1ea38e4-strcompress.png)


