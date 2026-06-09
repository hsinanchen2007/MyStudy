### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */
var getHint = function(secret, guess) {
    var bull=0,cow=0;
    var map = new Map();
    var resguess='';
    //第一个循环先统计数字相同并且索引位置相同的字符
    //把剩余的不是公牛的字符放到哈希表中，同时吧guess中的剩余字符连接起来
    for(var i=0;i<secret.length;i++){
        if(secret[i] == guess[i]){
                bull++;
        }else{
            if(map.has(secret[i]) == false){
                map.set(secret[i],1)
            }else{
                map.set(secret[i],map.get(secret[i])+1);
            }
            resguess += guess[i];
        }
    }
    //第二个字符在resguess中查找secret中含有这些字符但是索引不对的字符
    //判断条件是：map中有这些字符，同时对应字符的数量大于零
    for(i=0;i<resguess.length;i++){
        if(map.has(resguess[i]) && map.get(resguess[i]) > 0){
            map.set(resguess[i],map.get(resguess[i])-1);
            cow++;
        }
    }
    return bull + 'A' + cow + 'B';
};

```