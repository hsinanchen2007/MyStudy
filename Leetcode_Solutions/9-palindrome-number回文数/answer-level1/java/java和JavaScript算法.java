### 解题思路
带有测试方法的java代码。
这个内容是取出最高位和最低位进行比较来进行操作的。
只要是有一个不同，立刻就会显示错误
这个也比两边直接比较，要轻松很多。
### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        int div=1;
        while(x/div>=10){
            div*=10;
        }
        while(x > 0){
            int right=x/div;
            int left=x%10;
            if (left != right) return false;
            x = (x % div) / 10;//括号中是去掉现有x的第一位。外面的/10是去掉现有最后一位。
            div /= 100;//因为去掉了两位，所以最高位次要缩小100倍。
        }
        return true;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.isPalindrome(1000000001));

    }
}
```
**JavaScript代码**
这个代码是将数完全倒转，然后比较。
```JavaScript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    var top=0;
    var total=x;
while(x/10>0)
{
    top=top*10+x%10;
    if(x%10==0)top*10;
    x=Math.floor(x/10);
}
if(top===total){
    return true;
}else{
    return false;
}

};
```
