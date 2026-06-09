
# N数求和
```js
function nSum(nums, sum, n) {
    var len = nums.length;
    if (len === 0) return [];
    var arr = [];
    return loop(n);
    function loop(m) {
        // console.log(JSON.stringify(arr), m);
        if (arr.length !== 0) {
            if (m > 0) {
                var tmp = [];
                for (let i = 0; i < len; i++) {
                    arr.forEach(j => {
                        if (j.ids.indexOf(i) === -1) {
                            tmp.push({
                                sum: j.sum + nums[i],
                                ids: [...j.ids, i],
                                list: [...j.list, nums[i]],
                            });
                        }
                    });
                }
                arr.splice(m - 1, 1)
                arr = arr.concat(tmp);
                return loop(m - 1);
            } else {
                var obj = {};
                /**
                 * 索引去重
                 * 
                    for (let x = 0; x < arr.length; x++) {
                        if (arr[x].sum == sum && arr[x].ids.length === n) {
                            arr[x].ids.sort((a, b) => a - b);
                            obj[arr[x].ids.join()] = arr[x].list;
                        }
                    }
                    // return obj; // 索引:值
                    // return Object.keys(obj).map(i => i.split(',')); // 索引
                    return Object.values(obj); // 值
                */

                /**
                 * 值去重
                 * */

                for (let x = 0; x < arr.length; x++) {
                    if (arr[x].sum == sum && arr[x].ids.length === n) {
                        arr[x].list.sort((a, b) => a - b);
                        obj[arr[x].list.join()] = arr[x].list;
                    }
                }
                return Object.values(obj); // 值
            }
        } else {
            for (let i = 0; i < len; i++) {
                arr.push({
                    sum: nums[i],
                    ids: [i],
                    list: [nums[i]],
                });
            }
            return loop(m - 1);
        }
    }
}

var nums = [0,0,0,0,0];
var sum = 0;
var n = 3;
var res = nSum(nums, sum, n);
console.log(JSON.stringify(res));
```
