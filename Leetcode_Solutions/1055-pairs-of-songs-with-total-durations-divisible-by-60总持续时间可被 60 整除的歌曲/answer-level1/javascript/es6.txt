```
var numPairsDivisibleBy60 = time => {
    let c = new Array(60).fill(0)
    return time.reduce((count, cur) => {
        count += c[(60 - cur % 60) % 60]
        c[cur % 60] += 1 
        return count
    }, 0)
}