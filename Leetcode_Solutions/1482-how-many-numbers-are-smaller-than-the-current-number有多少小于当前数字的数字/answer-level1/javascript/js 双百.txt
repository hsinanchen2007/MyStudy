```
var smallerNumbersThanCurrent = function (nums) {
    return nums.reduce((prev, curr) => {
        prev.push(nums.filter(n => n < curr).length)
        return prev;
    }, [])
};
```
