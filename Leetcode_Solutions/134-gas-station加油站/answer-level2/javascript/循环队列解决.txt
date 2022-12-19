/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    let start = 0
    let end = start + gas.length
    let cur = 0
    for(let i = 0;i < end ; i++){
        if(i >= gas.length){
            let real = i - gas.length
            if(cur + gas[real] - cost[real] < 0) return -1
            else {
                cur = cur + gas[real] - cost[real]
            }
        }
        
        else {
             if(cur + gas[i] - cost[i] < 0){
            start = i + 1
            cur = 0
            end = start + gas.length
        }
        else {
            cur = cur + gas[i] - cost[i]
        }
        }
       
    }

    return start 
};

时间复杂度O(2n)