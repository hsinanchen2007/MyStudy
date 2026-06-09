```js
var lastStoneWeight = function(stones) {
        // 1. 石头排序
        stones.sort((a,b) => a-b)
        
        while(stones.length>=2){
            // 2. 找出最重的两块石头并处理
            let afterCrash = stones.pop() - stones.pop()
            // 3. 找到合适的位置插入新石头
            if(afterCrash > 0) {
                stones.splice(findPostion(afterCrash, stones),0,afterCrash)
            }
        }
        // 4. 重复2,3步骤 直到石头数组里只剩一块或者零块石头
        return stones[0] ? stones[0] : 0
};

    // 2分法查找位置插入
    function findPostion(afterCrash, stones){
        let left = 0, right = stones.length-1
        let mid
        while(left<=right){
            mid = Math.floor((left + right) / 2)
            if(stones[mid]<=afterCrash){
                left = mid + 1
            }else{
                right = mid - 1
            }
        }
        return left
    }
```