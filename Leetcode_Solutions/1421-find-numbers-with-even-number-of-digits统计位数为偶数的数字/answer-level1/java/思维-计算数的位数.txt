### 解题思路
这道题本质上来讲，只能算是入门级的。但是这里也有些地方只得我们去揣摩的：
一：给你一个数找出其所占的位数(虽然转成String or List会很方便，但是这个思想很重要)：
```
    fun getDigits(num:Int):Int{
        var digit = 0
        while(num > 0){
            digit ++
            num = num / 10
        }
    }
```


### 代码

```kotlin
class Solution {
    fun findNumbers(nums: IntArray): Int {
          var count = 0
    for (num in nums){
       if(isDouble(num)){
           count ++
       }
    }
    return count
    }

    fun isDouble(num :Int):Boolean{
        var num = num
        var count = 0;
        while(num > 0){
            count ++
            num = num / 10
        }

       return count % 2 == 0
    }
}
```