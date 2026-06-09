```
func longestPalindrome(s string) string {
	str := []byte(s)
	if len(str) == 0 {
		return s
	}
	if len(str) == 1 {
		return s
	}
	//去重
	duplicates := RemoveDuplicatesAndEmpty(str)
	if len(duplicates) == 1 {
		return s
	}

	//数组的组合可能性
	str_group := make(map[int][][]byte)

	istart := 0
	for k, _ := range str {
		res := getArr(str[k:])
		if len(res) > 0 {
			str_group[istart] = res
			istart++
		}
	}

	max_len := 0
	max_value := []byte{}
	
	
	//当前已经计算过的数据
	exist_value := []byte{}
	for i := 0; i < len(str_group); i++ {
		tmp := str_group[i]

		for j := 0; j < len(tmp); j++ {
			tmp2 := tmp[j]
			for m := 0; m < len(tmp2); m++ {

				if bytes.Equal(exist_value, tmp2) == true {
					continue
				}
				exist_value = tmp2
				
				//当前计算的长度需要大于已经计算出的长度
				if len(tmp2) > max_len {

					//中心扩展算法
					
					//奇数
					if len(tmp2)%2 != 0 {
						center := len(tmp2) / 2
						left := 0
						right := 0

						for i := 0; i < len(tmp2)/2; i++ {
							left++
							right++
							if tmp2[center-left] == tmp2[center+right] {
								if center-left == 0 {
									if len(tmp2) > max_len {
										max_len = len(tmp2)
										max_value = tmp2
									}
								}
							} else {
								break
							}
						}
					} else {
						//偶数
						center := len(tmp2) / 2
						left := 0
						right := 0
						for i := 0; i < len(tmp2)/2; i++ {
							right++
							if tmp2[center-left-1] == tmp2[center+right-1] {
								if center-left-1 == 0 {
									if len(tmp2) > max_len {
										max_len = len(tmp2)
										max_value = tmp2
									}
								}
							} else {
								break
							}
							left++
						}
					}
				}

			}

		}
	}

	fmt.Println("max_len", max_len)
	fmt.Println("max_value", max_value)
	if max_len == 0 {
		return string(str[0])
	}
	return string(max_value)
}

//去重
func RemoveDuplicatesAndEmpty(a []byte) (ret []byte) {
	a_len := len(a)
	for i := 0; i < a_len; i++ {
		if i > 0 && a[i-1] == a[i] {
			continue
		}
		ret = append(ret, a[i])
	}
	return
}

func getArr(arr []byte) [][]byte {
	var group [][]byte
	for k, _ := range arr {
		tmp_arr := arr[:k+1]
		if len(tmp_arr) > 1 {
			if tmp_arr[0] == tmp_arr[len(tmp_arr)-1] {
				group = append(group, arr[:k+1])
			}
		}
	}
	return group
}

```