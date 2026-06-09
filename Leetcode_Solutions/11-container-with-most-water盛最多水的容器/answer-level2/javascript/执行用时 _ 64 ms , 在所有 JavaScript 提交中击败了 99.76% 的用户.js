```
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let res = 0, l = height.length
    if(l==2){
        res=height[0]<height[1]?height[0]:height[1]
        return res
    }
    let h=0,f=l-1
    while(f>h){
        let s = (f-h)*Math.min(height[f],height[h])
        res=res>s?res:s
        height[f]>height[h]?h++:f--
    }
    return res
};
```
