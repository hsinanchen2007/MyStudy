### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let arrS=S.split('');
    let stack=[arrS[0]];
    let count=1;
    let str=arrS[0]+'';
    for(let i=1;i<arrS.length;i++){
        if(arrS[i]===stack[stack.length-1]){
            count++;
            if(i==arrS.length-1){ //判断是否是最后出现的字母
                str=str+count;
            }
        }else{
            str=str+count+arrS[i];
            stack.push(arrS[i]);
            count=1;
            if(i==arrS.length-1){ //判断是否是最后且只出现一次的字母
                str=str+'1';
            }
        }
    }
    return str.length>=S.length?S:str  //选择短的输出
};
```
![image.png](https://pic.leetcode-cn.com/e2e29b490a28fff16046da709b97a4c20ea10317b57ba1a8134b51113fb6fe04-image.png)
