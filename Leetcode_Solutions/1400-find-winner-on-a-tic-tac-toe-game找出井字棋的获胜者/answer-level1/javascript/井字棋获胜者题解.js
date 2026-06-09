### 解题思路
由于情况很少，可以直接采用枚举的方法暴力破解，步骤如下：
1.数组长度少于5个不可能有胜利者，断定情况为进行中；
2.创建长度为9的数组conditions，储存moves中给出的对局情况，第一个for循环嵌套switch，根据出牌奇偶性（知道了是A先出牌）存储对应的 “X” 或者 “O”
3.第二个for循环嵌套 switch 用于比较conditions中的九种情况（三横三竖两交叉）是不是有胜出的，有一种符合就有人胜出
4.根据flag标识位存储的情况看看胜出的是 “A”  还是 “B”  还是 “Draw” 或 “Pending”

### 代码

```javascript
/**
 * @param {number[][]} moves
 * @return {string}
 */
var tictactoe = function (moves) {
    let res = null;
    let conditions = new Array(9);
    if (moves.length < 5) {
        res =  "Pending";
    } else {
        for (let i = 0; i < moves.length; i++) {
            switch (moves[i].join('')) {
                case '00' :
                    conditions[0] = i % 2 === 0 ? 'X' : 'O';
                    break;
                case '01' :
                    conditions[1] = i % 2 === 0 ? 'X' : 'O';
                    break;
                case '02' :
                    conditions[2] = i % 2 === 0 ? 'X' : 'O';
                    break;
                case '10' :
                    conditions[3] = i % 2 === 0 ? 'X' : 'O';
                    break;
                case '11' :
                    conditions[4] = i % 2 === 0 ? 'X' : 'O';
                    break;
                case '12' :
                    conditions[5] = i % 2 === 0 ? 'X' : 'O';
                    break;
                case '20' :
                    conditions[6] = i % 2 === 0 ? 'X' : 'O';
                    break;
                case '21' :
                    conditions[7] = i % 2 === 0 ? 'X' : 'O';
                    break;
                case '22' :
                    conditions[8] = i % 2 === 0 ? 'X' : 'O';
                    break;
                default :
                    break;
            }
        }
        let flag = [];
        for (let j = 0; j < 8; j++) {
            switch (j.toString()) {
                case '0' :
                    flag.push((conditions[0] === conditions [1] && conditions[1] === conditions[2]) ? conditions[0] : null);
                    break;
                case '1' :
                    flag.push((conditions[3] === conditions [4] && conditions[4] === conditions[5]) ? conditions[3] : null);
                    break;
                case '2' :
                    flag.push((conditions[6] === conditions [7] && conditions[7] === conditions[8]) ? conditions[6] : null);
                    break;
                case '3' :
                    flag.push((conditions[0] === conditions [3] && conditions[3] === conditions[6]) ? conditions[0] : null);
                    break;
                case '4' :
                    flag.push((conditions[1] === conditions [4] && conditions[4] === conditions[7]) ? conditions[1] : null);
                    break;
                case '5' :
                    flag.push((conditions[2] === conditions [5] && conditions[5] === conditions[8]) ? conditions[2] : null);
                    break;
                case '6' :
                    flag.push((conditions[0] === conditions [4] && conditions[4] === conditions[8]) ? conditions[0] : null);
                    break;
                case '7' :
                    flag.push((conditions[2] === conditions [4] && conditions[4] === conditions[6]) ? conditions[2] : null);
                    break;
                default:
                    break;
            }
        }
        //console.log(flag);
        if(flag.includes('X')){
            res = "A"
        }else if(flag.includes("O")){
            res = "B"
        }else {
            res =  moves.length ===9 ? "Draw" : "Pending"
        }
        //console.log(res);
    }
    return res;
};
```