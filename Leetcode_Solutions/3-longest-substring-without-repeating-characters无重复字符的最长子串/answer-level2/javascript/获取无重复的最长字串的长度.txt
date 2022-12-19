### 解题思路
此处撰写解题思路
1. 肯定需要遍历字符串，一定又循环
2. 用一个地方存储无重复的字串，最后用它来计算长度
3. 循环的时候，查看仓库里有没有改字符，没有就加入，并记录当前仓库最长字串的长度，因为最终结果取的是两个下标的差值，所以，需要判断当前的差值是否是大于最大长度maxLength的， 大于才需要把最大长度替换为最新的差值
4. 有就把仓库内的字符从第一位开始挨个删除，再循环一次当前位置，看有没有在仓库内，回到步骤3
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
function lengthOfLongestSubstring(str){
    let length = str.length;
    let i = 0, j = 0, maxLength = 0;

    let set = new Set();

    while(i < length && j < length){
        let end = str.substring(i, i + 1); // 获取一位字符
        if( !set.has(end) ){
            set.add(end);
            i++;
            if( i-j>maxLength ){
                maxLength = i-j;
                console.log("最大子字符串：" + str.substring(j,i));
            }
        }else{
            let start = str.substring(j,j+1);
             
            set.delete(start);
            j++;
        }
    }

    return maxLength;
}

```