
1. 通过预先计算所有元素的和，优化和的计算
2. 以 j 作为第一层遍历的基准，然后不断遍历两端，再进行判断

```
var splitArray = function(nums) {
    if (nums.length < 5) {
        return false;
    }

    const sums = new Array(nums.length + 1);
    sums[0] = 0;
    for(let i = 0; i < nums.length; i++) {
        sums[i + 1] = nums[i] + sums[i];
    }

    const _split1 = (l, r) => {
        const ret = [];

        for (let i = l + 1; i < r - 1; ++i) {
            const sumLeft = sums[i] - sums[l];
            const sumRight = sums[r] - sums[i + 1];
            
            if (sumLeft === sumRight) {
                ret.push(sumLeft);
            }
        }

        return ret
    };

    const _split2 = (l, r) => {
        for (let i = l + 3; i < r - 3; ++i) {
            const lSums = _split1(l, i);
            if (lSums.length) {
                const rSums = _split1(i+1, r);
                if (rSums.length) {
                    const r = rSums.some(s => lSums.indexOf(s) !== -1);
                    if (r) {
                        return true;
                    }
                }
            }
        }
        return false;
    };

    return _split2(0, nums.length);
};
```
