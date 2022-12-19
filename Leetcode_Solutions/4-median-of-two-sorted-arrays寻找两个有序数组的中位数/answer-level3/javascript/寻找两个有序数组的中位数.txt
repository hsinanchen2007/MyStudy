/**
 *  排序
 */

function arrange(arr){
    let ex = null;
    
    for(let i = 0; i < arr.length; i++) {
        
        for(let j = i + 1; j < arr.length; j++) {
            
            if(arr[i] > arr [j]) {
                
                ex = arr[i];
                arr[i] = arr[j];
                arr[j] = ex;
                
            }
        }
        
    };
    
    return arr;
    
}



var findMedianSortedArrays = function(nums1, nums2) {
    
    
    var nums = nums1.concat(nums2);
    
    var newNums = arrange(nums)
    
    var arrlength =  newNums.length / 2;
    
    if(arrlength.toString().indexOf(".") > -1) {
        var z = Math.floor(arrlength);
        return newNums[z];
    }else {
       var zw = (newNums[arrlength] + newNums[arrlength - 1]) / 2;
       return zw;  
    }    
   
};