```
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
var relativeSortArray = function(arr1, arr2) {
    // 转换成次数表达的数组
    // arr1 === [1,1,1,2,2,3]
    // repo === [,3,2,1]
    const repo = []
    arr1.forEach(num => {
        if (repo[num]) {
            repo[num]++
        } else {
            repo[num] = 1
        }
    })
    //  循环arr2拿到排序，然后把统计出来repo的次数兑掉
    const result = []
    arr2.forEach(num => {
        while (repo[num]) {
            result.push(num)
            repo[num]--
        }
    })
    // 循环剩下的repo，依次推进结果
    for (let i = 0; i < repo.length; i++) {
        while(repo[i]) {
            result.push(i)
            repo[i]--
        }
    }
    return result
};
```
