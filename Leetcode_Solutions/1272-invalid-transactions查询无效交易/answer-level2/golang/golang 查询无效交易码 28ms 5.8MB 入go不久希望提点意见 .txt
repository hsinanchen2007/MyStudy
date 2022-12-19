### 解题思路
    //1、定义结构体数组以及返回字符串数组
    //2、循环给结构体数组
    //3、根据两种情况判断，其中第二种需要遍历之前的所有数据寻找
    //4、设定标识码，最后一锅端

### 代码

```golang
type Trans struct{
	Name string
	Min int
	Money int
	City string
	types int
}

func invalidTransactions(transactions []string) []string {
  //1、定义结构体数组以及返回字符串数组
	transarr:=[]Trans{}
	restring:=[]string{}
	var trans Trans
  //2、循环给结构体数组
	for _,v:=range transactions{
		strarr:=strings.Split(v,",")
		trans.Name=strarr[0]
		trans.Min, _ =strconv.Atoi(strarr[1])
		trans.Money,_=strconv.Atoi(strarr[2])
		trans.City=strarr[3]
		trans.types=200
  //3、根据两种情况判断，其中第二种需要遍历之前的所有数据寻找
		if trans.Money>1000{
			trans.types=500
		}
		for key,v:=range transarr{
			if v.Name==trans.Name&&v.City!=trans.City&&math.Abs(float64(trans.Min-v.Min))<=60{
				transarr[key].types=500
				trans.types=500
			}
		}
		transarr=append(transarr,trans)
	}
  //4、设定标识码，最后一锅端
	for _,valus:=range transarr{
      if valus.types==500{
      	str:=valus.Name+","+strconv.Itoa(valus.Min)+","+strconv.Itoa(valus.Money)+","+valus.City
      	restring=append(restring,str)
	  }
	}
	return restring
}
```