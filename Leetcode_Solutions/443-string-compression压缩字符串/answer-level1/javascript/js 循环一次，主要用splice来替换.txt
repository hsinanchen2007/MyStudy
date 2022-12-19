### 解题思路
![image.png](https://pic.leetcode-cn.com/31301ca0d6b35aecf313df799f0da0409c20c99f27ef0b1bf164e5073941033c-image.png)
1、num：有多少个相同的数，初始值为1，默认该数有一个。对比后一个是否与前一个元素相同
2、splice(index,howmany,item1,.....,itemX)：此处易踩index的坑……因为删除重复的并且替换了元素，需要更新i的值。
3、若是相同的数大于9，那么还需要把数字拆分开

然而这一切是基于元素是按顺序排列的，若相同元素不靠在一起，那可就不得行了

### 代码

```javascript
/**
 * @param {character[]} chars
 * @return {number}
 */
var compress = function(chars) {
    let num = 1;
    for(let i=0; i<chars.length; i++){
        if(chars[i] == chars[i+1]) num++;
        else{
             if(num>1){ // num==1：该元素只有一个，不需要处理
                // 将数字转换成数组的形式
                let addArr = (num+'').split(''); 
                // 2.1(index)：比如['a','a','a','b','b']有3个a，那么此时对比到第一个b(此时i=2)的时候，需要将第二第三个a替换成3，因为i从0开始，所以此时i+1表示已经处理的元素，而此时有num个a，需要留一个在前面，就是需要处理掉num-1个a。那么此时index的i+1-(num-1)
                // 2.2(howmany)：有num个数，需要留一个在前面，所以需要删除的为num-1个数
                // 2.3：需要添加的数，用es6解构赋值，主要是为了防止相同的数超过9的情况，如b=12，需要添加'1','2'
                chars.splice(i+2-num,num-1,...addArr);
                // 2.4：splice之后chars的长度会改变，删除了num-1个，那么此时i应该处理到i-(num-1)，又添加了addArr到chars中，所以此时已经处理过的元素位置为i-(num-1)+addArr.length
                i = i+1-num+addArr.length;
                num = 1;
            }
        }
    }
    return chars.length;
};
```