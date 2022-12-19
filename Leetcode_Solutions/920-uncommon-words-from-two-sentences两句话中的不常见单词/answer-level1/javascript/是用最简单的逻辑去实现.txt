### 解题思路
1. 首先将两个字符串全部**转换成数组**，并且**合并**在一起，这个时候，**重复的单词**就会出现**两次**
2. **排序**一下这个数组，这样做**相同**的单词会排列在**相邻**的位置
3. 下一步我们将排序好的数组遍历，并且同时**比对相邻单词**是否相同，将**相同位置的单词的下标**提取出来生成一个**下标数组**
1. 遍历这个下标数组，用下标去将排序数组中的单词设置为空字符串（注意不能直接删除，直接删除会导致排序数组的长度变化导致下标不准确，且多个重复单词出现是不好判断）
1. 最后用filter过滤掉排序数组中的空字符串，返回即可

### 代码

```javascript
/**
 * @param {string} A
 * @param {string} B
 * @return {string[]}
 */
var uncommonFromSentences = function(A, B) {
    var alist = A.split(' ') // 数组化
    var blist = B.split(' ') // 数组化
    var indexArr=[] // 下标数组
    var list = alist.concat(blist).sort() // 排序数组
    list.map((v,i)=>{ // 将相邻且相同的单词下标保存到下标数组
        if(v === list[i+1]){
            indexArr.push(i),indexArr.push(i+1);
        }
    })
    indexArr.map((v,i)=>{ // 将排序数组中同样的单词置空
        list[v]=''
    })
    return list.filter((item)=>{ // 最后输出过滤掉空字符串即可
        return item!=''
    })   
};
```