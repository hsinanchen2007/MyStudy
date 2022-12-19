### 解题思路
1.将chars 存到map中
2.将words中的每一个字符串都存到一个map中
3.比较每个单词的个数是否满足条件
4.使用flag 标志符，为true是加上单词长度

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
var countCharacters = function(words, chars) {
    var map=new Map();
    var count=0;
    for(var i=0;i<chars.length;i++){    
        if(map.has(chars[i])){
            var n = map.get(chars[i]);
            map.set( chars[i] , n+1)
        }else{
            map.set(chars[i],1)
        }
    }
    for(i=0;i<words.length;i++){
        var temp = new Map();
        if(words[i].length>chars.length){//注意一定要判断长度
            continue;//注意一定要是continue，而不是return 0；
        }
        for(var j=0;j<words[i].length;j++){                   
            if(temp.has(words[i][j])){
                var m=temp.get(words[i][j]);
                temp.set(words[i][j],m+1);
            }else{
                temp.set(words[i][j],1);
            }
        }
        var flag=true;
        for(var k=0;k<words[i].length;k++){
            if(map.has(words[i][k])==false){
                flag=false;
                break;
            }
            if(map.get(words[i][k]) < temp.get(words[i][k])){
                flag=false;
                break;
            }
        }
        if(flag==true){
            count = count + words[i].length;
        }
    }
    return count;
};