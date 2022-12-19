### 解题思路
不用抄作业了，算是个好的开始 ^_^!

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
// 获取最大不重复字符串长度
function getMaxNoRepetitionStringLength(data){
    if(data.index == data.string.length-1){
        return; // 没有下标了
    }
    let buffer = '';
    // 开始浮标
    for(let index = data.index;index < data.string.length;index++){
        if(index > data.index){
            let leftNum = buffer.indexOf(data.string[index]);
            if(leftNum == -1){
                // 查询buff是否有与当前值重复的值
                buffer += data.string[index];
                if(index == data.string.length-1){
                    // 下一个浮标循环就结束了，所以尝试更新一次max的值
                    data.max = buffer.length > data.max?buffer.length:data.max;
                }
            }else{
                // 重复了则尝试刷新max值并重新调用函数
                data.max = buffer.length > data.max?buffer.length:data.max;
                
                data.index = data.index+leftNum+1;
                getMaxNoRepetitionStringLength(data);
                break;
            }
        }else{
            buffer += data.string[index];
        }
    }
        
    

}

var lengthOfLongestSubstring = function(s) {
    if(s == ''){
        return 0;
    }
    let data = {
        // 浮标
        index: 0,
        // 目标字符串
        string: s,
        // 当前最大值
        max: 1,
    };
    getMaxNoRepetitionStringLength(data);
    return data.max;

};
```