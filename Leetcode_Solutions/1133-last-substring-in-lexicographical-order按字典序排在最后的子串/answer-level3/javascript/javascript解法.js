```
/**
 * @param {string} s
 * @return {string}
 */


var lastSubstring = function(s) {
 let temp = [];
   let max_char = s[0];
   let index = 0;//最大元素的索引值
   let max = "";
   //循环求得第一个字符是字典排序最大的元素
   for(let i=0;i<s.length;i++){
        if(max_char<s[i]){
            max_char  = s[i];
            index = i;
        }
   }
   //查找以最元素开头的字符串所有（即t1xxxxxt2uuuuu，即t1到最后与t2到最后比较）
 for(let i=index;i<s.length;i++){
     if(s[i] == max_char){
        if(max<s.substring(i)){
            max = s.substring(i);
        }
     }
  }
   

  
   return max;
};
```
