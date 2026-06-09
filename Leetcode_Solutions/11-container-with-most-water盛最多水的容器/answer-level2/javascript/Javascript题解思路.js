o(n^2)解法

`
var maxArea_hard= function(height) {
    var maxarea = 0
    for(var i = 0;i<height.length;i++){
        for (var j = i+1;j<height.length;j++){
            // console.log("当前解:",(height[j]>height[i]?height[i]:height[j])*(j-i),j-i,(height[j]>height[i]?height[i]:height[j]))
            maxarea = (height[j]>height[i]?height[i]:height[j])*(j-i)>maxarea?(height[j]>height[i]?height[i]:height[j])*(j-i):maxarea
        }
    }
    return maxarea
};

`
o(n)解法
`
var maxArea = function(height) {
    var maxarea = 0,l = 0,r = height.length-1;
    while(l<r){
        maxarea = (height[r]>height[l]?height[l]:height[r])*(r-l)>maxarea?(height[r]>height[l]?height[l]:height[r])*(r-l):maxarea;
        height[l]>height[r]?r--:l++;
    }
    return maxarea
};

`