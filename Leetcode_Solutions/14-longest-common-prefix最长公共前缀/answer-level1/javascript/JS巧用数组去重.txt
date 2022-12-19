### 解题思路
这个函数刚开始写的时候，首先的思路就是对参数进行约束，也就是对简单值的处理

刚开始分为**没有参数**、**参数长度为1的情况**。后来考虑追加了**多个元素相等**的情况

下面进入正题：
首先既然是最大前缀，最大也不会超过最短元素，所以**第一步是找到最短元素**

其次就是遍历了，从小到大和从大到小都无所谓，**从小到大是遇到不相等的情况就跳出遍历** ， **从大到小是遇到相等的就跳出遍历**。

### 运行结果：
执行用时 :68 ms, 在所有 javascript 提交中击败了74.99%的用户
内存消耗 :34.2 MB, 在所有 javascript 提交中击败了78.63%的用户

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(strs.length === 0 ){
        return ''
    }
    if(strs.length === 1){
        return strs[0]
    }
    if ( (new Set(strs)).size === 1 ){
        //三个元素都一样的情况
        return strs[0]
    }
    // 最小元素
    let min_len = Math.min(...strs.map(el => el.length));
    let common_str = ''; // 最长前缀
    // 从最大值开始向下搜索 ，
    for(let i = min_len ; i > 0 ; i--){
        // 简单的使用 Set 对 数组去重， 如果只有一个元素，自然就是相等的
        if( (new Set(strs.map(item => item.substr(0,i))) ).size === 1){
            common_str = strs[0].substr(0,i);
            // 因为是从大到小，所以遇到相等的，就是最大的了，再向下执行也没有什么意义，结果也会错，跳出循环
            break;
        }
    }
    return common_str;
};
```