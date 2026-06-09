### 解题思路
此处撰写解题思路
1.我被恶心到了，思路很简单，不断替换字符串首个字符，计算长度增量的奇偶性；
2.若奇数的个数大于1，不是回文；

关键点在于：
1.js对于部分码点表示的字符不能正确识别，需要用codePointAt与codePointFrom才能正确读取到首个字符。
for of循环也能正确识别首字母；
2.js规定'\'不能直接出现在字符串中，例如在首字母出现的'\',在字符串中表示为'\\';
3.正则匹配时对'\'+char转义时，用'\'转义，'\'本身也需要转义，因此表示为'\\\\'；
4，java中共有五个字符必须转义才能使用，
U+005C：反斜杠（reverse solidus)
U+000D：回车（carriage return）
U+2028：行分隔符（line separator）
U+2029：段分隔符（paragraph separator）
U+000A：换行符（line feed）

因此均需要考虑进去，这里是回文，只有'\'需要考虑
```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var canPermutePalindrome = function(s) {
    let count=0,temp;
    while(s.length){
        if(s.charAt(0)=='\\'){
           temp = s.replace(new RegExp('\\\\','g'),'');  
        }else{
          temp = s.replace(new RegExp(s.charAt(0),'g'),'');
        }
        if((s.length-temp.length)%2==1){
           count++;
        }
        s=temp;
    }
    if(count>1)return false;
    return true;
};
```