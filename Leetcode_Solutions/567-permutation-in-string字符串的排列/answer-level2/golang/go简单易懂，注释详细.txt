```
func checkInclusion(s1 string, s2 string) bool {
    if len(s1)==0{
        return true
    }
    if len(s1)>len(s2){
        return false
    }
    //包含这个排列的意思就是，在m1长度的窗口内，含有的字符类别以及相应数量都是相等的
    //可以构建两个数组
    var str1 = [26]int{}
    var str2 = [26]int{}
    //初始化m1的数组
    for i:=0;i<len(s1);i++{
        str1[s1[i]-'a']++
        str2[s2[i]-'a']++
    }
    //如果这里直接相等了，直接返回
    if str1==str2{
            return true
        }
    //开始滑动串口遍历s2
    for i:=len(s1);i<len(s2);i++{
         str2[s2[i]-'a']++
         str2[s2[i-len(s1)]-'a']--
        if str1==str2{
            return true
        }
    }
    
    return false
}
```
