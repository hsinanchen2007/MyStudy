js用map解决，s,,t为异位词，t中的元素必定存在s中，只是位置不同而已，利用map进行遍历判断： 1.建立一个s字符串的Map,每一个元素设置键值1,重复出现的元素键值+1 2.遍历判断t中的元素在s中是否有且键值大于0（大于零表示存在的） 3.每找到一个元素，其键值-1（用于标记其已经被找过了，下次对比不找它了）

```
var isAnagram = function(s, t) {

    if(s.length!=t.length){  //长度不想的的直接返回false
        return false;
    }

     var map = new Map();   //新建map集合
     for (var n of s) {      //将s放入Map集合中，并标记他们出现的次数通过set
         if (map.has(n)) {
             map.set(n, map.get(n) + 1); //重复出现元素键值+1，用于计数标记
         } else {
             map.set(n, 1);         //键值设为1
         }
     }

     for (var n of t) {            
         if (map.has(n) && map.get(n) > 0) { //遍历判断t中元素在s中是否存在
               map.set(n, map.get(n) - 1);   //没找到一个，键值-1；
         }else{                     
             return false;
         }
     }                                     
    return true; //循环结束后为s与t异位,必定t中的元素在s的map中都能找到
     
};
```
