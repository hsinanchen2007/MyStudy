### 解题思路
思路参考了讨论最多的官方题解中的 $O(N)$ 复杂度的双指针方法，个人感觉已经很极限了，没什么优化的地方了。贴不同语言的代码供大家一起学习。
### 代码
```C []
int maxArea(int* height, int heightSize){
    if (height == NULL || heightSize < 2) {
        return 0;
    }

    int result = 0;
    int i = 0; 
    int j = heightSize - 1;

    while (i < j) {
        int h = MIN(height[i], height[j]);
        result = MAX(result, h * (j - i ));

        if (height[i] < height[j]) {
            i++;
        }
        else {
            j--;
        }
    }

    return result;
}
```
```python []
class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans = float('-inf')
        start, end = 0, len(height) - 1
        while start < end:
            ans = max(ans,min(height[start],height[end]) * (end - start))
            if height[start] <= height[end]:
                start += 1
            else:
                end -= 1
        return ans
```
```java []
class Solution {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1, res = 0;
        while(i < j){
            res = height[i] < height[j] ? 
                Math.max(res, (j - i) * height[i++]): 
                Math.max(res, (j - i) * height[j--]); 
        }
        return res;
    }
}
```
```C++ []
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return -1;
        int i = 0, j = height.size() - 1, res = 0;
        while(i < j){
            int h = min(height[i], height[j]);
            res = max(res, h * (j - i));
            if(height[i] < height[j]) ++i;
            else --j;
        }
        return res;
    }
};
```
```javascript []
var maxArea = function(height) {
    let i = 0, j = height.length-1;
    let square, max = 0;
    while(j-i >= 1){
        if(height[i]>height[j]){
            square = height[j] * (j-i);
            j--;
        }else{
            square = height[i] * (j-i);
            i++;
        }
        max = Math.max(square,max);
    }
    return max;
};
```
```go []
func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func maxArea(height []int) int {
	o := 0
	i, j := 0, len(height)-1
	for i != j {
		hi, hj := height[i], height[j]
		s := (j - i) * min(hi, hj)
		if s > o {
			o = s
		}

		if hi > hj {
			j--
		} else {
			i++
		}
	}
	return o
}
```

### 复杂度分析
- 时间复杂度:$O(N)$。
- 空间复杂度:$O(1)$。