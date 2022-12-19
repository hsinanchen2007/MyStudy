### 解题思路
依次比较两个相邻单词的字母出现顺序，分为三种情况：
1.出现后一个单词的index大于前一个单词的index，那么直接return false
2.出现后一个单词的index小于前一个单词的index，将flag记为1，为了和相等的情况区分，break，进入下面两个单词的比较
3.index均相等此时flag=0，那么判断后一个单词长度是不是更小，更小说明排序错了，return false
中途如果没有return，那么整体有序，return true

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} order
 * @return {boolean}
 */
var isAlienSorted = function(words, order) {
    if(words.length == 1) return true;
    for(let i = 0; i < words.length - 1; i++){
        let one = words[i];
        let two = words[i+1];
        let idx = Math.min(one.length,two.length);
        let flag = 0;
        for(let j = 0; j < idx; j++){
            if(order.indexOf(one[j]) < order.indexOf(two[j])){
                flag = 1;
                break;
                //once < , true, break inner cycle
            }else if(order.indexOf(one[j]) > order.indexOf(two[j])){
                //once > , return false
                return false;
            }
        }
        //check case: apple,app
        if(flag == 0 && two.length == idx){
            return false;
        }
    }
    return true;
};
```