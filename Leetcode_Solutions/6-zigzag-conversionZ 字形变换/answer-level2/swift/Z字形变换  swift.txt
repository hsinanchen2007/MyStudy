![截屏2019-10-15下午2.13.19.png](https://pic.leetcode-cn.com/16af3d7f195c10edac95bc0f3065f7e81c7d51a2c833ce36b0d99a0fe3ff973f-%E6%88%AA%E5%B1%8F2019-10-15%E4%B8%8B%E5%8D%882.13.19.png)
每一行为一个字符串，对原始字符串枚举分别添加到对应的字符串，最后字符串合并。


```
func convert(_ s: String, _ numRows: Int) -> String {
    if numRows<2{
        return s
    }
    var strArr=Array<String>()
    for _ in 0..<numRows{
        strArr.append("")
    }
    for (index,char) in s.enumerated(){
        let num=index%(numRows*2-2)
        if num<numRows{
            strArr[num].append(char)
        }else{
            strArr[numRows*2-2-num].append(char)
        }
    }
    return strArr.joined()
}
```
