func reverseString(str0fByteArr []byte) string {
	if str0fByteArr == nil{
		return ""
	}else if len(str0fByteArr) == 1{
		return string(str0fByteArr)
	}
	
	var start = 0
	var end = len(str0fByteArr) - 1
	for i := 0; i < len(str0fByteArr) / 2; i++{
		str0fByteArr[start], str0fByteArr[end] = str0fByteArr[end], str0fByteArr[start]
		start++
		end--
	}

	return string(str0fByteArr)
}
