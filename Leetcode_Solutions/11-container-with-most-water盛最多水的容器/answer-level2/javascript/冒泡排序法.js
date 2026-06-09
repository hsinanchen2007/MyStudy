/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    var res=0
    for(var i=0;i<height.length;i++){
        for (var j=i+1;j<height.length;j++){
           if(height[i]>height[j]){
               if(res<(j-i)*height[j]){
                    res=(j-i)*height[j]
               }
             
           }else{
               if(res<(j-i)*height[i]){
                    res=(j-i)*height[i]
               }
              
           }
        }
    }
    return res
};