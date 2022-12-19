### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function(s, k) {
    var num = Math.floor(s.length/(2*k));
    var yu = s.length%(2*k);
    var temp=[];
    for(var i=0,j=0;i<num*2*k;j++){
        var str1 = s.substring(i,i+k).split('').reverse().join('');
        var str2 = s.substring(i+k,i+2*k);
        temp[j]=str1+str2;
        i=i+2*k;
    }
    var str5='';
    for(j=0;j<num;j++){
        str5 += temp[j];
    }
    if(yu < k){
        var str3 = s.substring(num*2*k).split('').reverse().join('');
        return str5+str3;
    }else {
        var str4 = s.substring(num*2*k,num*2*k+k).split('').reverse().join('') + s.substring(num*2*k+k);
        return str5+str4;
    }
};
```