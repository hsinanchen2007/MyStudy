一次遍历找到最大第二大最小第二小数字 时间复杂度O(n)
/**
 * @param {number[][]} arrays
 * @return {number}
 */
var maxDistance = function(arrays) {
  let max = [],maxIndex;
  let min = [],minIndex;
    arrays.forEach((arr,key)=>{
        let mi = arr[0],ma = arr[arr.length-1];
        if(min[0] === undefined){
            min.push(mi);
                minIndex = key;
        }else {
            if(min[0]>mi){
                min[1] = min[0];
                min[0] = mi;
                minIndex = key;
            }else{
                if(min[1] === undefined){
                    min[1] = mi;
                }else {
                    if(min[1]>mi){
                        min[1] = mi;
                    }
                }
                
            }
        }
        
              if(max[0] === undefined){
            max.push(ma);
                maxIndex = key;
        }else {
            if(max[0]<ma){
                max[1] = max[0];
                max[0] = ma;
                maxIndex = key;
            }else{
                if(max[1] === undefined){
                    max[1] = ma;
                }else {
                    if(max[1]<ma){
                        max[1] = ma;
                    }
                }
                
            }
        }
         
    });
    if(minIndex !=maxIndex){
        return max[0] -min[0]
    }else{
        return Math.max(max[1] - min[0],max[0]-min[1]);
    }
};
