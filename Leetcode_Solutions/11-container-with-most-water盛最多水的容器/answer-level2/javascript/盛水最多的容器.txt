### 解题思路
1. 解法一：双循环暴力破解
2. 解法二：双指针

### 解法一

```javascript

var maxArea = function(height) {
    let max=0;
    let minHeight=0;
    for(let i=0;i<height.length-1;i++){
        for(let j=i+1;j<height.length;j++){
            minHeight=height[i]<height[j]?height[i]:height[j]
            max=Math.max(max,(j-i)*minHeight)
        }
    }
    return max
}
```


### 解法二

```javascript

var maxArea = function (height) {
    let max = 0, left = 0, right = height.length - 1;
    while (left < right) {
        max = Math.max(max, Math.min(height[left], height[right]) * (right - left));
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max
}

```