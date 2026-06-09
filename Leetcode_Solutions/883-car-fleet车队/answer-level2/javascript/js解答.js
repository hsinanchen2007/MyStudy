```
/**
 * @param {number} target
 * @param {number[]} position
 * @param {number[]} speed
 * @return {number}
 * 题目参数里不会有初始位置相同速度不同的情况，这是荒谬的
 */
var carFleet = function(target, position, speed) {
    const times = []
    //记录下标对应的时间
    for(let i = 0;i<position.length;i++) times.push([i, (target - position[i]) / speed[i]])
    // 按距离逆序排
    times.sort((a, b) => position[b[0]] - position[a[0]])
    let ans = 0
    //group初始为null是为了防止position为空数组
    let group = null
    while(times.length){
        let item = times.shift()
        // item起始位置一定小于group(逆序排的),如果它的时间不大于group那就是从后面追上，就是一个车队了
        if(group && (item[1] <= group[1])) continue
        // 否则，追不上就说明拉开了差距，产生一个新的车队
        group = item
        ans++
    }
    return ans
};
```
