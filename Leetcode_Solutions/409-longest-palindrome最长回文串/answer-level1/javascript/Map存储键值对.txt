### 解题思路
map存储字符串中元素和元素个数，元素偶数次则直接相加，出现奇数次则-1后相加。最后，判断若出现过奇数次则总数加一

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    var map=new Map();
    var num=0;
    if(s.length==0) return num;
    for(let i=0;i<s.length;i++){
        let char=s.charAt(i);
        if(!map.has(char)){
            map.set(char,1);
        }else{
            let newVal=map.get(char)+1;
            map.set(char,newVal);
        }          
    }
    var count=false;//判断是否包含奇数键
    map.forEach(function(value,key){
        if((value%2)==0) {
            num+=value;
        }else {
            num=num+value-1;
            count=true;
        }
    })
    if(count) return num+1;
    else return num;
};
```