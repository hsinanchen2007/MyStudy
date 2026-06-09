### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
    var first=0,last=s.length-1;
    //var temp=''
    var map = new Map();
    var str=['a','e','i','o','u','A','E','I','O','U'];
    for(var i=0;i<10;i++){
        map.set(str[i],i);
    }
    var s=s.split('');
    while(first<last){
        if( map.has(s[first]) && map.has(s[last]) ){
            var temp=s[first];
            s[first]=s[last];
            s[last]=temp;
            first++;
            last--;
        }else if( map.has(s[first]) && (map.has(s[last])==false) ){
            last--;
        }else if( (map.has(s[first])==false) && map.has(s[last]) ){
            first++;
        }else if( (map.has(s[first])==false) && (map.has(s[last])==false) ){
            first++;
            last--;
        }
    }
    return s.join('');
};
```