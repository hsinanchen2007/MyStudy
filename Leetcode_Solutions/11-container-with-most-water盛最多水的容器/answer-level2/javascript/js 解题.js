路过，水，另外测试波动好大，一次100ms，一次52ms
var maxArea = function(height) {
    let start=0,end=height.length-1,max=0
    while(end>start){
       let value=(height[start]>height[end]?height[end]:height[start])*(end-start)
           max=value>max?value:max
           height[start]>height[end]?end--:start++  
    }
    return max
};