### 解题思路
分别把他两个字符串存储在map中key为字符，value为该字符出现的次数.
再遍历map1中的key在map2中是否存在，且存在的时候value是否相等，不存在或者不相等则返回false

### 代码

```golang
func CheckPermutation(s1 string, s2 string) bool {
    if len(s1)<0||len(s1)>100||len(s2)<0||len(s2)>100{
        return false
    }
    if len(s1)!=len(s2){
        return false
    }
    array1:=[]rune(s1)
    array2:=[]rune(s2)
    map1:=make(map[rune]int，0)
    map2:=make(map[rune]int，0)
    for i:=0;i<len(array1);i++{
        if _,ok:=map1[array1[i]];ok{
            map1[array1[i]]+=1
        }else{
        map1[array1[i]]=1
        }
    }
     for i:=0;i<len(array2);i++{
        if _,ok:=map2[array2[i]];ok{
            map2[array2[i]]+=1
        }   else  {
        map2[array2[i]]=1
        }
    }
    for k1,v1:=range map1{
        v2,ok:=map2[k1]
        if !ok||v1!=v2{
            return false
        }
    }
    return true
}
```