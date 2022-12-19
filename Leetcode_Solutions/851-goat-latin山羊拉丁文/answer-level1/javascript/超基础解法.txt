
```
    var arrFirstWord=['a','e','i','o','u','A','E','I','O','U']
    var str=S
    var arr=str.split(' ')
     var strArr=[]
     var mark=0
     // 封装
     function strEnd(count){
         var arrCount=[]
         for(var i=0;i<count;i++){
             arrCount.push('a')
         }
         return arrCount.join('')
     }
    // 使用封装
     for(var i=0;i<arr.length;i++){
         mark++
         var aW=arr[i].slice(0,1)          
            if(arrFirstWord.includes(aW)){// 元音开头--得出结果
                var countStr=strEnd(mark)
                arr[i]=arr[i]+'ma'+countStr
                strArr.push(arr[i])
            }else{// 辅音开头--得出结果
                var countStr=strEnd(mark)
                var arrNew=[]
                var strNew1=arr[i].split('')
                var strNew2=strNew1.shift()
                var strNew3=strNew1.slice(0)
                strNew3.push(strNew2,'ma', countStr)
                strArr.push(strNew3.join(''))
             }    
    }
    return strArr.join(' ')
```
emmm，都不好意思说这题我花了多久了，哎。