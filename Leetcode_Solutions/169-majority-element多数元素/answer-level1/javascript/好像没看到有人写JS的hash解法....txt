```javascript
var majorityElement = function(nums) {
    let hash = [];  // 用hash表存储被扫描元素的次数
    for (let i = 0; i < nums.length; i++) {
        // 若该元素已被扫描过，则次数++
        if (hash[nums[i]] !== undefined) {
            hash[nums[i]]++;
        }
        // 若该元素是第一次扫描到，则初始化为1
        else {
            hash[nums[i]] = 1;
        }
        // 判断该元素次数是否大于数组长度一半，注意这里的>= 
        // 例如length为奇数:[1,1,1,2,3]，次数等于长度一半；length为偶数:[1,1,1,2]，次数大于长度一半
        if (hash[nums[i]] >= nums.length / 2) {
            return nums[i];
        }
    }
};
```