### 解题思路
字符长度是1或者2的时候一定是回文子串，根据需求保存或者累计个数；
字串长度多于两个(比如三个),我们只需要判断两端是否一样即可，然后判断四个的时候一定会包含长度为3的(3的已经判断了)
那么这个判断这个新的只需要判断最左和最右是一样的，并且最左和最右之间的（之间的之前已经判断了）必须是回文
（有点啰嗦可以结合代码看注释）

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */

var countSubstrings = function(str) {
    let len = str.length,gap = '_';
    let i,j,L;
    let p ={};
    let total = 0;
    //把所有是回文子串的串的下标位置用i_j进行拼接存储到一个对象中，分别代表起始位置;
    // L代表间隔，其实就是回文串长度
    for(i=0;i<len;i++){ //单个字符一定是回文串
        p[i+gap+i] = true;
        total = total +1;
    }
    // L是i和j之间的间隔数（因为间隔数从小到大渐增，所以大的间隔数总能包含小的间隔数）
    for(L=2;L<=len;L++){
        // 从0开始  i代表左下标
        for(i=0;i<=len-L;i++){
            j = i+L-1;//j是左下标加上间隔在减去1，即右下标
            if(L === 2){//相邻的两个字符一定是回文串
                p[i+gap+j] = (str[i] === str[j]);
                if(str[i] === str[j]){
                    total = total +1;
                }
            }else{//判断i 到 j 是不是回文子串，只是需要判断之间的是不是，在判断str[i]是否等于str[j],相当于在回文串两端多添加两个字符。
                p[i+gap+j] = (str[i]===str[j]) && p[i+1+gap+(j-1)];
                if((str[i]===str[j]) && p[i+1+gap+(j-1)]){
                    total = total +1;
                }
            }
        }
    }
    return total;

};


//改编版本，因为把所有的字串也都存储起来了，所以时间空间复杂度很高，但是功能很全，
//相当于得到了所有的字串（true和false），所有的回文子串（true），回文子串个数（result.length）,
//最大的回文字串也可以在通过一个遍历得到
// var countSubstrings = function(s) {
//         function getStr(str) {
//         let len = str.length,gap = '_';
//         let i,j,L;
//         let p ={};
//         let result = [];//储存所有的字串
//         //把所有是回文子串的串的下标位置用i_j进行拼接存储到一个对象中，分别代表起始位置;
//         // L代表间隔，其实就是回文串长度
//         for(i=0;i<len;i++){ //单个字符一定是回文串
//             p[i+gap+i] = true;
//             result.push(str.slice(i,i+1))
//         }
//         // L是i和j之间的间隔数（因为间隔数从小到大渐增，所以大的间隔数总能包含小的间隔数）
//         for(L=2;L<=len;L++){
//             // 从0开始  i代表左下标
//             for(i=0;i<=len-L;i++){
//                 j = i+L-1;//j是左下标加上间隔在减去1，即右下标
//                 if(L === 2){//相邻的两个字符一定是回文串
//                     p[i+gap+j] = (str[i] === str[j]);
//                     if(str[i] === str[j]){
//                         result.push(str.slice(i,j+1))
//                     }
//                 }else{//判断i 到 j 是不是回文子串，只是需要判断之间的是不是，在判断str[i]是否等于str[j],相当于在回文串两端多添加两个字符。
//                     p[i+gap+j] = (str[i]===str[j]) && p[i+1+gap+(j-1)];
//                     if((str[i]===str[j]) && p[i+1+gap+(j-1)]){
//                         result.push(str.slice(i,j+1))
//                     }
//                 }
//             }
//         }
//         return result.length;
//     }
//     return  getStr(s)

// };

```