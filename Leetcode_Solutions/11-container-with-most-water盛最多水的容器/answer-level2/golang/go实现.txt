func maxArea(height []int) int {
   
    var min = 0
    var max = 0
    for i:=0;i<len(height)-1;i++{
        for j:=i+1;j<len(height);j++{
            if height[i]<height[j]{
                min=height[i]
            }else{
                min=height[j]
            }
            if max<min*(j-i){
                max=min*(j-i)
            }
        }  
    }
    return max
}