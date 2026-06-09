### 解题思路
先统计出相同号码的卡片的长度，然后如果这些长度里面有共同的因数那就返回true

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    let deck_length = deck.length
    // 排除长度为 0 和 1 的情况
    if(deck_length<2){
        return false
    }
    /**
     * 设置一个字典保存相同数字的数量
     */
    let same_card_map = new Map()
    deck.forEach(d=>{
        if(same_card_map.has(d)){
            same_card_map.set(d,same_card_map.get(d)+1)
        }else{
            same_card_map.set(d,1)
        }
    })
    // 如果只有一个数那就直接通过
    if(same_card_map.values.length==1){
        return true
    }
    /**
     * 相同数字的卡片长度数组
     */
    let same_card_lengths = []
    same_card_map.forEach((v,k)=>{
        same_card_lengths.push(v)
    })
    /**
     * 从小到大排列
     */
    same_card_lengths.sort((a,b)=>{
        return a-b
    })
    /**
     * 最小的长度
     */
    let min_length = same_card_lengths[0]
    /**
     *  最大的长度
     */
    let max_length = same_card_lengths[same_card_lengths.length-1]
    /**
     * 如果存在只有一个数的，而且其他的元素有多个，那肯定不是
     * 例如:[0,0,0,0,0,1,1,2,3,4]
     */
    if (min_length == 1 && max_length != 1) {
        return false
    }
    /**
     * 求因子
     */
    let factors = [] //因子数组
    let temp_factor = 2 // 排除1的因子
    for(temp_factor = 2 ;temp_factor<min_length;temp_factor++)
    {
        if(min_length % temp_factor == 0)
        {
            factors.push(temp_factor)
        } 
    }
    /*
    * 把自己加入
    */
    factors.push(min_length) 
    
    /**
     * 求是否有共同因数
     */
    for(let i = 0;i<factors.length;i++)
    {
        let factor = factors[i]
        let index = 0
        for(index = 0;index<same_card_lengths.length;index++)
        {
            let len = same_card_lengths[index]
            if (len%factor != 0){ //不是共同因数
                break;
            }
        }
        /*
        * 如果找到共同的因数
        */
        if(index == same_card_lengths.length)
        {
            return true
        }
    }
    return false
}
```