### 解题思路
使用递归

### 代码

```javascript
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    //1.遍历整个board,找到word字符串第一个单词匹配的单词
    //2.找到单词后，我们将调用search函数遍历每种可能的组合（上，下，左，右）
    //3.如果该函数返回true，则 字符串存在
    //4.否者继续检查，直到退出循环为止。
    for(let c = 0 ,cLen=board.length; c<cLen;c++){
        for(let r = 0,rLen=board[c].length; r<rLen;r++){
            if(board[c][r] === word[0]){
                if(search(board,word,c,r)){
                    return true
                }     
            }
        }
    }

    function search(b,w,c,r){
        //过滤情况
        //如果字符串为空，我们已经找到它。
        if(w==="") return true;
        //边界拦截
        if(!(c>=0)|| !(c<b.length) ||!(r>=0) || !(r<b[c].length))  return false
        //再次检查第一个字母是否相同
        if(b[c][r] != w[0]) return false

        //我们需要把已遍历过的打上标记 “#”，
        //但考虑到其他遍历需要这个变量，用个变量存储它
        //我们将变量放到底部的递归调用之后的那个位置，以便其他递归调用拥有它
        let temp = b[c][r];
        b[c][r] = "#"

        //只要有一种可能成立就return true
        if(
        //下一列
        search(b,w.slice(1),c+1,r)||
        //上一列
        search(b,w.slice(1),c-1,r)||
        //向左
        search(b,w.slice(1),c,r+1)||
        //向右
        search(b,w.slice(1),c,r-1)
        
        ){
            b[c][r] = temp;
            return true
        }else{
            //还原
            b[c][r] = temp;
            return false
        }


    }

    return false;
};
```