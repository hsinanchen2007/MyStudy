这里来证明一下为什么双指针写法是正确的
由题意可知  area = min(height[x] , height[y]) * (y - x) [ y > x];

我们需要找到一对x，y来使得area最大，我们在开始和结束处都设置一个指针，
一个从前往后遍历，一个从后往前遍历，那这样(y-x)这一项肯定是在减小的，那我们需要找到一个方法让另一项增大，
而增大的因素与两者之间更小的高度有关，所以我们移动height值更小的指针，这样一个增加，一个减少才有可能area变大

```
let left = 0;
    let right = height.length - 1;
    let area = 0;
    while(left < right){
        let tempArea = Math.min(height[left],height[right]) * (right - left);
        area = area > tempArea ? area : tempArea;
        if(height[left] < height[right] ) left++;
        else if (height[left] > height[right] ) right--;
        else{
            left++;
            right--;
        }
    }
    return area;
```
