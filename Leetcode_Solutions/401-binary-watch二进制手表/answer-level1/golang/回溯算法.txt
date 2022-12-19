### 解题思路
  * 按照回溯法的模板进行解题。
  * 这里用字符串不是很便利，用位运算比较便利

```alg
func tree(选择,路径){
   结束条件
   遍历分叉
     if 满足剪枝条件
        continue
     进入节点前干啥
     递归节点
     遍历节点后干啥
}
```

### 代码

```golang
func readBinaryWatch(num int) []string {
  if num == 0{return []string{"0:00"}}
  res := new([]string)
  var trace []byte
  backTrack(res, trace, num)
  return *res
}


func backTrack(res *[]string, trace []byte, num int){
  //fmt.Println(string(trace),len(trace),oneCnt(trace))
  if len(trace) == 10 && oneCnt(trace)==num{
    //fmt.Println(string(trace))
    t := convert(trace)
    if t != "nil" {
      *res = append(*res, t)
    }
  }
  for _,v := range []byte("01"){
    if len(trace) > 10 || oneCnt(trace)>num{
      continue
    }
    trace = append(trace,v)
    backTrack(res,trace,num)
    trace = trace[:len(trace)-1]
  }
}

func convert(trace []byte) string{
  hour,min:=0,0
  h,m := 8,32
  for i:=0;i<4;i++{
    hour += h * int(trace[i]-'0')
    h = h/2
  }
  for i:=4;i<10;i++{
    min += m * int(trace[i]-'0')
    m = m/2
  }
  if hour > 11 || min >59 {return "nil"}
  return fmt.Sprintf("%d:%02d",hour,min)
}

func oneCnt(trace []byte)int{
  cnt := 0
  for _,v := range trace{
    if v == '1'{
      cnt++
    }
  }
  return cnt
}
```