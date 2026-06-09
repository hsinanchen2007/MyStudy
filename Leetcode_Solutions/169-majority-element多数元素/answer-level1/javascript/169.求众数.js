暴力求解
```
var majorityElement = function(nums) {
    if(nums.length == 1) return nums[0];
    for(let i = 0,len = nums.length;i<len;i++){
        let count = 1;
        for(let j = i+1;j<len;j++){
            if(nums[i] == nums[j]) count++;
            if(count > len/2) return nums[i];
        }
    }
};
```
hash求解
```
var majorityElement = function(nums) {
    if(nums.length == 1) return nums[0];
    let map = {},result;
    for(let i = 0,len = nums.length;i<len;i++){
        if(map.hasOwnProperty(nums[i])){
            map[nums[i]]++;
            if(map[nums[i]] > len/2){
                result = nums[i];
            }
        }else{
            map[nums[i]] = 1;
        }
    }
    return result;  
};
```
排序求解
```
var majorityElement = function(nums) {
    nums.sort();
    return nums[parseInt(nums.length/2)];
}
```
投票求解
```
var majorityElement = function(nums) {
        let count = 0;
        let candidate = null;

       nums.forEach(function(num){
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        });

        return candidate;
    }
```
