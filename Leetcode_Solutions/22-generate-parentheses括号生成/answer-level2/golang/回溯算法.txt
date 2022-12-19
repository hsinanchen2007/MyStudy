### 解题思路
  * 回溯法模板套用，确定终止条件，剪枝条件
  * 使用new来创建res变量，来存储所有字符结果

### 代码

```golang

func generateParenthesis(n int) []string {
  res := new([]string)
  var trace []byte
  backTrace(res,trace,n)
  return *res
}


func backTrace(res *[]string, trace []byte, n int){
  if len(trace) == n*2 && isValid(trace,n){
    *res = append(*res,string(trace))
  }
  cand := []byte("()")
  for _,kh := range cand{
    // 剪枝条件
    if !isValid(trace,n){
      continue
    }
    //fmt.Println(string(trace))
    trace = append(trace,kh)
    backTrace(res, trace,n)
    trace = trace[:len(trace)-1]
  }
}

func isValid(trace []byte,n int)bool{
  left,right:=0,0
  for _,kh := range trace{
    if kh == '('{
      left++
      if left>n {return false}
    }else{
      right++
      if right > left{return false}
    }
  }
  return true
}
```