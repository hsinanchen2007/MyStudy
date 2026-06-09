### 解题思路

第一步：求出map映射，即每种牌的个数
第二步：遍历map，求出pre和map[i]的最大公约数，pre为map[i-1]前的最大公约数；
如果pre<2,则分组不能完成
pre>=2返回true

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    let map=new Map();
    for(let i=0;i<deck.length;i++){
        if(map.has(deck[i])){
            map.set(deck[i],map.get(deck[i])+1);
        }
        else map.set(deck[i],1);
    }
   console.log(map);
   
    let pre;
    for(v of map.values()){
        console.log(v);
        if(v<2)return false;

        if(pre === undefined){
            pre=v;
        }
        else{
            
            if(pre !== v){
                let x = gcd(pre,v);
                //console.log(x);
                if(x<2)return false;
                pre = x;
            }
        }
        

    }
    return true;

    function gcd(a,b){
        //求最大公约数
        if(b === 0)return a;
        return gcd(b,a%b);
    }

};
```