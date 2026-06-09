
申明一个变量count，然后依次遍历数组，在遍历过程中，count的值表示当前位置之前（不包括当前位置）**出现过的0**的次数，即当前位置需要前移的位数

```javascript
var moveZeroes = function (nums) {
    let count = 0
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === 0) {
            count++
        } else if (count > 0) {
            nums[i - count] = nums[i]
            nums[i] = 0     // 前移之后立刻置0，这个位置以后还会不会有别的值过来不用管
        }
    }
};
```