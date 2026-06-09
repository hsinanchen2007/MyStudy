
先用正则表达式处理字符串，替换 /[^a-zA-Z0-9]/g 所有非字母和数字，/\s/g 所有空格为""，然后统一转为大写或者小写。
设2个指针i和j，一个从0开始，一个从处理后的字符串最后开始
用while迭代，一个增加一个减少，当他们碰头的时候结束迭代
s[i]!=s[j]就返回false跳出迭代，全部迭代完都相等返回true

```javascript []
var isPalindrome = function(s) {
   s=s.replace(/[^a-zA-Z0-9]/g,"").replace(/\s/g,"").toLowerCase();
    let i=0,j=s.length-1;
    while(i<j){
        if(s[i]!=s[j]){
           return false;
        }
        i++;
        j--;
    }
return true;
};
```


