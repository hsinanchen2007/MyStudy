### 解题思路
根据题意，罗马数字的表示有且仅有M、CM、D、CD等13种符号。

### 代码

```java
class Solution {
    HashMap<String,Integer> map ;
    public int romanToInt(String s) {
        initializeMap() ;
        int res = 0 ;
        int i = 0 , n = s.length() ;
        while(i < n - 1){
            String temp = s.substring(i,i+2) ;
            if(map.containsKey(temp)){
                res += map.get(temp) ;
                i += 2 ;
                continue ;
            }else{
                temp = temp.substring(0,1) ;
                if(map.containsKey(temp)){
                    res += map.get(temp) ;
                }
                i += 1 ;
                continue ;
            }
        }
        if(i == n-1){
            res += map.get(s.substring(n-1,n)) ;
        }
        return res ;
    }
    public void initializeMap(){
        map = new HashMap<>() ;
        map.put("M",1000) ;
        map.put("CM",900) ;
        map.put("D",500) ;
        map.put("CD",400) ;
        map.put("C",100) ;
        map.put("XC",90) ;
        map.put("L",50) ;     
        map.put("XL",40) ;
        map.put("X",10) ;
        map.put("IX",9) ;
        map.put("V",5) ;
        map.put("IV",4) ;
        map.put("I",1) ;
    }
}
```