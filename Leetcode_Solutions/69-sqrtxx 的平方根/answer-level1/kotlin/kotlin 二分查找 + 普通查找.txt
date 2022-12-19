1、二分查找
```
        var flag = 0
        fun mySqrt(x: Int): Int {
            if ( x == 1) return 1
            if (x == 0) return 0
            halfSearch(1.0, (x.toDouble() / 2 + 0.5).toInt().toDouble()  , x.toDouble())
            return flag
        }
        fun halfSearch(L : Double,R : Double,obj : Double){
            if (L >R) return
            var x = ((L + R)/2).toInt().toDouble()

           if (x * x == obj){
               flag = x.toInt()
           }else if (x * x < obj){
               flag = x.toInt()
               halfSearch((x + 1).toInt().toDouble() ,R,obj)
           }else{
               halfSearch(L,(x - 1).toInt().toDouble() ,obj)
           }
            return
        }
```
执行用时 :252 ms, 在所有 Kotlin 提交中击败了77.27%的用户
内存消耗 :32.4 MB, 在所有 Kotlin 提交中击败了100.00%的用户

2、普通查找
```
fun mySqrt(x: Int): Int {
            var flag = 0.0
            var xx = x.toDouble()
            while (flag <= xx){
                if (flag * flag <= xx && (flag + 1)*(flag + 1) > xx){
                    break
                }else{
                    flag ++
                }
            }
            return flag.toInt()
        }
```


