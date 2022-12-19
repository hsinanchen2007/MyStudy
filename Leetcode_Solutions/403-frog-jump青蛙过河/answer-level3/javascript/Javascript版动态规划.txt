刚开始用数组来存储跳到每一个单位格的跳跃距离可能性，结果代码运行超时了
然后换了set来存储，虽然执行用时和内存消耗不理想，但总算是通过了

```javascript
var canCross = function (stones) {
    // 确定状态
    let ability = new Array(stones.length)  // 存每一个单元格是否有解
    let step = {}   //  存跳到每一个单元格的步跳跃距离可能性
    
    // 初始化数据
    ability[0] = true
    step[stones[0]] = new Set().add(0)  

    // 第二个单位格开始遍历
    for (let i = 1; i < ability.length; i++) {

        ability[i] = false
        step[stones[i]] = new Set()

        // 遍历之前的单位看是否有满足条件的单位
        for (let j = 0; j < i; j++) {

            // 取出在这之前每一个单元格基于前面单元格跳跃步数的可能性
            for (let k of step[stones[j]]) {

                /* 
                    只要之前的所有单元格其中一个满足两个条件
                    1.所遍历到的之前的单元格可以到达
                    2.此单元格对应跳跃步数的可能性满足题目中所描述的 "如果青蛙上一步跳跃了 k 个单位，那么它接下来的跳跃距离只能选择为 k - 1、k 或 k + 1个单位。"

                    则当前单元格可到达
                */
                if (ability[j] && (stones[i] - stones[j] >= k - 1 && stones[i] - stones[j] <= k + 1)) {
                    ability[i] = true
                    // 存储所有可以到达该单元格的步数
                    step[stones[i]].add(stones[i] - stones[j])
                }
            }
        }
    }
    // 返回最后一个点是否到达情况
    return ability[ability.length - 1]
};
```
