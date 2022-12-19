### 解题思路
统计不匹配的半括号数量

### 代码

```golang []
func minAddToMakeValid(S string) int {
	rightLoss := 0
	leftLoss := 0
	for _, c := range S {
		if c == '(' {
			rightLoss++
		} else {
			if rightLoss > 0 {
				rightLoss--
			} else {
				leftLoss++
			}
		}
	}
	return leftLoss + rightLoss
}
```
```java []
class Solution {
    public int minAddToMakeValid(String s) {
        int leftLoss = 0;
        int rightLoss = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                rightLoss++;
            } else {
                if (rightLoss > 0) {
                    rightLoss--;
                } else {
                    leftLoss++;
                } 
            } 
        }
        return leftLoss + rightLoss;
    }
}
```