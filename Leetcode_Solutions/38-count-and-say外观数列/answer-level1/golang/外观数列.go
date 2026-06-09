### 解题思路
把1-30所有产生的数据都写进map[int]string中，然后直接return map

### 代码

```golang
func countAndSay(n int) string {

    var m1 map[int]string=map[int]string{1:"1",2:"11",3:"21",4:"1211",5:"111221"}   
    for i:=6;i<=30;i++{
        index:=1
        var str string
        for j:=0;j<len(m1[i-1]);j++{
            if j+1<len(m1[i-1]) && m1[i-1][j+1]==m1[i-1][j]{
                index++
            }else{
                // fmt.Println(string(m1[n-1][j]),index)
                str+=strconv.Itoa(index)+string(m1[i-1][j])
                index=1
            }

        }
        m1[i]=str
    }
    



    return m1[n]

    

}
```