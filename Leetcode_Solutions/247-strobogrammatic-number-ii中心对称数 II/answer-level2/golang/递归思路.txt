### 解题思路
function fn(n) {     
    // 第一步：判断输入或者状态是否非法？     
    if (input/state is invalid) {
         return;
     }    
    // 第二步：判读递归是否应当结束?
     if (match condition) {
         return some value;
     }
     // 第三步：缩小问题规模
     result1 = fn(n1)
     result2 = fn(n2)
     ...
     // 第四步: 整合结果
     return combine(result1, result2)
 }
### 代码

```golang
func findStrobogrammatic(n int) []string {
	if n==2 {return []string{"69", "88", "11", "96"}}
	return helper(n,n)
}

func helper(n, m int) []string {
	if n < 0 || m < 0 || n > m {
		panic(errors.New("invalid input!"))
	}
	if n == 0 {
		return []string{}
	}
	if n == 1 {
		return []string{"0", "1", "8"}
	}
	if n ==2 {
		return []string{"00", "11", "69", "96", "88"}
	}
	strList := helper(n-2, m)
	res := make([]string, 0, len(strList))
	for _, str := range strList {
		if n != m {
			res = append(res, "0"+str+"0")
		}
		res = append(res, "1"+str+"1")
		res = append(res, "6"+str+"9")
		res = append(res, "8"+str+"8")
		res = append(res, "9"+str+"6")
	}
	fmt.Println(len(res))
	return res
}

```