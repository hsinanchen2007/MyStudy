*第一次写有诸多不正确的 望指正*
# 1.初步想法
第一时间想到的即是多次排列组合
换而言之，就是嵌套循环，此时想到此事无法避免的 但如何才能提高效率

# 2.着手书写
当读题后立刻发现，如果用手算，都是先将前两组合后再将其结果与下一个进行组合
因此立即想到将前两个分出来，将其组成第一份数组

# 3.总结收尾
1. 若还有下一个则直接将前一步生成的数组与下一个进行循环即可
2. 但要记得此时数组中已存在每次组合剩下的需要进行filter删除即可

```
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
  if(digits.length==0)
    return []
  var obj={
    '2':'abc',
    '3':'def',
    '4':'ghi',
    '5':'jkl',
    '6':'mno',
    '7':'pqrs',
    '8':'tuv',
    '9':'wxyz'
  }
  if(digits.length==1)
    return obj[digits].split("")
  var arr= digits.split("")
  var myarr=[]

  for(var i=0;i<obj[arr[0]].length;i++){
    for(var j=0;j<obj[arr[1]].length;j++)
      myarr.push(obj[arr[0]].charAt(i)+obj[arr[1]].charAt(j))
  }
  for(var i=2;i<arr.length;i++){
    var a1= obj[arr[i]]
    let smallarr=[]
    for(var j=0;j<myarr.length;j++){
      for(var k=0;k<a1.length;k++){
        smallarr.push(myarr[j]+a1[k])
      }
    }
    myarr.push(...smallarr)
  }

  return  myarr.filter(function(b){
    return b.length==digits.length
  })
};
```
