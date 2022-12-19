### 解题思路
此处撰写解题思路
逻辑方面挺简单，从左到右，从右到左，比target小左边加1，比target大右边减1，关键是右边的初始位置的选择，选择target的开方的值作为右边界，我觉得是这道题的关键
### 代码

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        if (c == 1){
            return true;
        }
        int left = 0;
        int right = (int) Math.sqrt(c);
        while (left <= right) {
            if (left * left + right * right == c){
                return true;
            }else if(left * left + right * right < c) {
                left++;
            }else if (left * left + right * right > c){
                right--;
            }
        }
        return false;
    }
}
```