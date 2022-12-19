```
/**
 * @param {number[][]} times
 * @param {number} N
 * @param {number} K
 * @return {number}
 */
var networkDelayTime = function(times, N, K) {
    const paths = new Map()
    const dist = new Map()

    for(edge of times) {
        if(paths.has(edge[0])) {
           paths.get(edge[0]).push([ edge[1], edge[2] ])
        } else paths.set(edge[0], [ [ edge[1], edge[2] ] ])
    }

    for(let i = 1;i <= N;i++) {
        dist.set(i, Infinity)
    }
    dist.set(K, 0)
    const visited = new Array(N + 1).fill(false)
    while(true) {
        let cand = -1
        let cand_cost = Infinity
        for(let i = 1;i <= N;i++) {
            /* 注意，这里用dist.get(i) < cand_cost 而不是dist.get(i) !== Infinity
                是因为有可能有些点只能通过较大的点到达，如果先遍历较大的点，这时较大的点
                还没有获取到它最小的耗时，那么通过较大的点才能到达的点的耗时就永远是比较大的，
                而不是最小的。这就是迪杰斯特拉算法要从源点开始遍历，并优先遍历离源点代价较小的
点的原因:如果一个点存在多个到达代价，那么必须先让这个点获得多个代价中的最小值，然后才能以这
个点开始作为中间的起点遍历。


            */
            if((!visited[i]) && (dist.get(i) < cand_cost)) {
                cand = i
                cand_cost = dist.get(i)
            }
        }
        if(cand === -1) break
        visited[cand] = true
        if(paths.has(cand)) {
            for(info of paths.get(cand)) {
                dist.set(info[0], Math.min(dist.get(info[0]), dist.get(cand) + info[1]))
            }
        }
    }
    let ans = 0
    for(v of dist) {
        if(v[1] === Infinity) return -1
        ans = Math.max(ans, v[1])
    }
    return ans
};
```
