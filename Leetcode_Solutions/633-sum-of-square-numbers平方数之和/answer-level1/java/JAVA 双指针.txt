### 解题思路
这道题用双指针作答，用到方法Math.sqrt(double a) 返回正确舍入的c值的正平方根
left初始化0，right初始化为c的平方根，如果left<=right进行下面操作，否则返回false，如果sum等于left^2+right^2，如果小于的话，右指针向左移动，否则左指针向右移动。

### 代码

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        if (c < 0) return false;
        int sum = 0;
        int left = 0;
        int right = (int) Math.sqrt(c);
        while(left <= right){
            sum = left*left + right*right;
            if(sum == c){
                return true;
            }else if(sum > c){
                right--;
            }else{
                left++;
            }
        }
        return false;
    }
}
```