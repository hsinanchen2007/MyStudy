### 解题思路
单独的只是个人思维，我再会看看大佬的思路。

####1、我就是判断是不是横列，不是横列就是逐个获取到第几行然后push进去，是横列就单独循环逐个push进去。
####2、判断是不是只有一行


### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    // 创建二维数组
    const dp = Array.from(new Array(numRows),() => new Array())

    // ----------- 
    const len = s.length;
    let i = 0;
    let j = 0;//第几列
    // 判断如果只有一列
    if(numRows == 1){
        return s;
    }
    while (i<len){
        // 如是是横列
        if (j%(numRows - 1) == 0 ){
            for(let m =0;m<numRows;m++){
                dp[m].push(s.charAt(i));
                i++
            }
            j++;
        }else{
            // 如果不是横列
        
            let n =numRows - 1 -(j%(numRows - 1));
            dp[n].push(s.charAt(i))
            i++;
            j++;
        }
    }
    // ---------- 其他题解思路 向下向右控制坐标  比我上面强行获取坐标强了，然后也可以不用数组，直接用字符串+就行了
    // ---------- 不过我只是基于另外一种改一下而已，无关紧要了，思路到位就行
    let index = 0;//数组下表
    let down = true;//是否往下
    for (let i = 0; i < s.length; i++) {
        dp[index].push(s.charAt(i));
        // 如果向下 下标增加，如果向右，下标逐减往上走
        index = down? ++index:--index;
        if (index === 0) {
            down = true
        } else if (index === numRows - 1) {
             down = false
        }
    }
    // -----------   

    let res = '';
    dp.forEach(item=>{
        item.forEach(item1=>{
            res +=item1
        })
    })
    return res;
       
};
```