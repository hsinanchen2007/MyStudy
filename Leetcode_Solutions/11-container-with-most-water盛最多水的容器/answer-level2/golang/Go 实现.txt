```
func maxArea(height []int) int {
    l,r := 0,len(height)-1
    maxArea :=0
    for l<r{
        h := height[l]
        if height[l]>height[r]{
            h = height[r]
        }
            w := r-l
            if w*h>maxArea{
                maxArea = w*h
            }
            if height[l]<height[r]{
                l++
            }else{
                r--
            }
        }
    return maxArea
 }

```
