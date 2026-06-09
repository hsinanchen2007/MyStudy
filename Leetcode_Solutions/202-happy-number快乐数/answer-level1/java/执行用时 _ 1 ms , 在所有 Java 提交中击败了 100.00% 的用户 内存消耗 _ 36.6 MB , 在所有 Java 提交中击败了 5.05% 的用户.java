### 解题思路
思路就是每次循环计算平方和，再判断该值是否等于1，不等于的话继续循环

---有个问题就是当该数字不是快乐数的时候，会无限循环
我前几次提交失败的时候，观察了重复的值  都有4，20，等其他值，所以这直接写了个4来检查是否重复（这感觉很别扭）

大佬们看这个checkNum该怎么设置合理呢？？？

### 代码

```java
class Solution {
    public boolean isHappy(int n) {
        int checkNum = 4;
        boolean isCheck = true;

        while (n != 1) {
            int temp = 0;   //每次保存计算的平方和

            while (n != 0) {
                int tt = n%10;
                temp +=  tt * tt;
                n /= 10;
            }

            n = temp;
            if (isCheck) {
                isCheck = false;
            } else {
                if (checkNum == temp) {
                    return false;
                }
            }
        }
        return true;
    }
}
```