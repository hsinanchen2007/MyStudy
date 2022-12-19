### 解题思路
## 贪心算法
当轮到参议员使用权力（前提是他拥有投票权）的时候，先不使用权利，而是把权利 “存储” 起来，Power++，用于下一次出现对方参议员的时候，禁止对方参议院的权利。
```
if senate[i] =="R"{
	if(DPower > 0){
        senate[i] == "X";
        Runit --; //R参议员 --；
        DPower--; 权利使用过后，就没有了，减去一
    }else{
        RPower++;;
    }
}
```

### 代码

```javascript
/**
 * @param {string} senate
 * @return {string}
 */

var predictPartyVictory = function(senate) {
    let RUnit = 0;
    let DUnit = 0;
    let RPower = 0;
    let DPower = 0;
    senate = Array.from(senate);
    let isR = senate[0] == "R" ? true : false;
    let len = senate.length;
    for(let i = 0; i < len; i++){
        if(senate[i] == "R"){
            RUnit++;
        }else{
            DUnit++;
        }
    }
    while(RUnit > 0 && DUnit > 0){
        //优先限制后面的参议员，如果后面没有参议员了，就限制对方的所剩下的第一个参议员;
        for(let i = 0; i < len; i++){
            if(senate[i] == "R"){
                if(DPower > 0){
                    //如果之前存在没有使用权利的 D 参议员
                    senate[i] = "X"; //这个参议员的权利被禁止了。
                    RUnit--;//R参议员减少一位
                    DPower--;//D参议员的权利减少一个
                }else{
                    RPower++;
                }
            }else if(senate[i] == "D"){
                if(RPower > 0){
                    senate[i] = "X";
                    DUnit--;
                    RPower--;
                }else{
                    DPower++;
                }
            }
        }
    }
    return RUnit > 0 ? "Radiant" : "Dire";
};
```