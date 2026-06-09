### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} houses
 * @param {number[]} heaters
 * @return {number}
 */
var findRadius = function(houses, heaters) {
    houses = houses.sort((a,b)=> a-b)
    heaters= heaters.sort((a,b)=> a-b)
    heaters.unshift(Number.MIN_SAFE_INTEGER)
    heaters.push(Number.MAX_SAFE_INTEGER)

    let max = 0
    for(let i=0;i<houses.length;i++) {
        let left =0;
        let right = heaters.length - 1
        let mid
        while(left< right) {
            mid = left + Math.floor((right-left)/2)
            if(houses[i] >  heaters[mid]){
                left = mid+1
            }else {
                right = mid
            }
        }
        var distance = Math.min(houses[i]-heaters[left-1], heaters[left]-houses[i])

    max = Math.max(max, distance)

    }
    return max
};
```