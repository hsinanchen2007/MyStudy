### 解题思路
常规思路：列举所有情况条件判断
这道题目如果只是简单地字符串转整数的话，就是简单地ans = ans * 10 + digit。 但是注意这道题目可能会超过integer的最大表示！ 也就是说会在某一步 ans * 10 + digit > Integer.MAX_VALUE。 *10和+ digit 都有可能越界，那么只要把这些都移到右边去就可以了。 ans > (Integer.MAX_VALUE - digit) / 10 就是越界。
### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    var max=Math.pow(2,31)-1;
    var min=Math.pow(2,31)*(-1);
    //去除左侧空格
    str = str.replace(/^\s*/,"");
    if(str.length==0)return 0;
    var res=0;
    var i=0;
    var flag=1;//符号
    if(str[i]=='-'){
        flag=-1;
        i++;
    }else if(str[i]=='+'){
        flag=1;
        i++;
    }
    while(i<str.length && str[i]>='0'&&str[i]<='9'){
        var digit=str[i]-'0';
        if(res>(max-digit)/10){
            if(flag==1)return max;
            return min;
        }
        res=res*10+digit;
        i++;
    }
    return res*flag;
};
```
方法二：正则匹配
trim():用于删除字符串的头尾空格
match():在字符串内检索指定的值，或找到一个或多个正则表达式的匹配
使用正则表达式 
^：匹配字符串开头，
(\-|\+)：代表一个+字符或-字符，
?：前面一个字符可有可无，
\d：一个数字，
+：前面一个字符的一个或多个
g:执行全局匹配（查找所有匹配而非在找到第一个匹配后停止）
```
var myAtoi = function(str) {
     let res = str.trim().match(/^(\-|\+)?\d+/g)
    return res ? Math.max(Math.min(Number(res[0]),2**31-1),-(2**31)) : 0
};
```
