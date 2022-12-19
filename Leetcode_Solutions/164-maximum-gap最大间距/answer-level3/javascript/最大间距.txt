```
var maximumGap = function(nums) {
    if (nums.length < 2) return 0

    const sort = (arr) => arr.sort((x, y) => y - x)

    const getDeffs = (arr) => {
      let deffs = []
      for (let i = 0; i < arr.length - 1; i++) {
        deffs.push(arr[i] - arr[i + 1])
      }
      return deffs
    }

    const compose = (f, g, h) => (x) => f(g(h(x)))

    return compose(sort, getDeffs, sort)(nums)[0]
  }
```