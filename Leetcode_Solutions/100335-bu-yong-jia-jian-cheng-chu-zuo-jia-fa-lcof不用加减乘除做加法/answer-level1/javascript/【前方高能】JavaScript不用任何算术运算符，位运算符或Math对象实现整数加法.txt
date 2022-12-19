
```javascript
/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var add = function(a, b) {
    
    //1.偏要做加法 最好成绩 50% / 100%
    //return a+b

    //2.普通的代码混淆法 最好成绩 100% / 100%
    //return eval([a,b].join(decodeURIComponent('%2b')))
    //return Function('a','b',`return a${String.fromCharCode(43)}b`)(a,b)

    //3.不错的递归位运算解法 最好成绩 70% / 100%
    //return b == 0 ? a : add( a ^ b, (a & b) << 1 )

    //4.不错的循环位运算解法 最好成绩 70% / 100%
    /*
        while(b!=0){
            [a,b] = [ a ^ b, (a & b) << 1 ]
        }
        return a
    */

    //5.毁天灭地的长度拼接法
    return (function(a,b){

        if(a==0 || b == 0){
            return a || b
        }

        function negative(num){//将正数变为负数
            return Number([ [].indexOf('wth').toString()[0],num ].join(''))
        }

        function abs(num){//取绝对值
            return num >= 0 ? num : Number( num.toString().slice(1) )
        }

        if( a>0 && b>0 ){ //正数相加
            return Array( abs(a) ).concat( Array(abs(b)) ).length
        }
        if( a<0 && b<0 ){ //负数相加
            return negative( Array(abs(a)).concat(Array(abs(b))).length )
        }
        if( a > b ){

            if( abs(a) > abs(b) ){ //大正数+小负数
                let t = Array(a)
                t.splice(b)
                return t.length
            }
            else if( abs(a) < abs(b) ){ //小正数+大负数，即大负数绝对值-小正数取反
                let t = Array(abs(b))
                let tmp = t.splice(a)
                return negative(tmp.length)
            }

        }
        
        else{//提示：在严格模式下无法在匿名函数内调用自身
            return arguments.callee(b,a)
        }
    })(a,b)


};
```