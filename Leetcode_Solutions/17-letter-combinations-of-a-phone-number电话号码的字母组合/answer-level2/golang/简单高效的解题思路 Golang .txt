![{E0910922-36D8-46C6-B033-DA0687586848}_20200320002245.jpg](https://pic.leetcode-cn.com/bb307c8d7bfdc0e953f578fe973d9a27ac5b42ace609b579a601ee4e5098c062-%7BE0910922-36D8-46C6-B033-DA0687586848%7D_20200320002245.jpg)


大概说下思路：
1. 先深度递归 （按输入的数字，比如“239”）
2. 再广度递归  (数字所对应的字母，比如9对应的“wxyz")
3. 找临界点 （深度递归的长度不能大于输入字符串的字节长度或数字map字母串的长度）
4. 保存符合条件的返回值 （1. 输出的每个结果必须与digits长度一致 2. dMap的索引不等于0时，进行对位的替换）


func letterCombinations(digits string) []string {

	ans := []string{}
	dMap := map[byte]string{}
	dMap['2'] = "abc"
	dMap['3'] = "def"
	dMap['4'] = "ghi"
	dMap['5'] = "jkl"
	dMap['6'] = "mno"
	dMap['7'] = "pqrs"
	dMap['8'] = "tuv"
	dMap['9'] = "wxyz" 
	printLetters(digits, dMap, 0, 0, []byte{}, &ans)
	return ans
}

func printLetters(digits string, dMap map[byte]string, dcur int, dmcur int, tmp []byte, ans *[]string){

	ld := len(digits)
	if (dcur >= ld) || (dmcur >= len(dMap[digits[dcur]])) {
		return
	}

	if  dmcur!=0 {
		tmp[dcur] = dMap[digits[dcur]][dmcur]
	}else{
		tmp = append(tmp,dMap[digits[dcur]][dmcur])	
	}

	if (len(tmp) == len(digits)){
		*ans = append(*ans, string(tmp))
	}
	printLetters(digits, dMap, dcur+1, 0, tmp, ans)		
	printLetters(digits, dMap, dcur, dmcur+1, tmp, ans)	
	
}