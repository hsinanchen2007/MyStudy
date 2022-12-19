
初学c#可以想到的简单实现
执行用时：92ms
内存消耗：15.3MB
```
public class Solution {
    public bool IsPalindrome(int x) {
//正数才有回文，判断正负。
        if(x >= 0){
            int temp = x;
            int result = 0;
//计算回文
            do{
            int num = 0;
            num = x % 10;
            x = x / 10;
            result = 10 * result + num; 
	        } while (x != 0);
//判断回文与原文是否相等并输出bool结果
            if(temp == result){
                return true;
            }else{
                return false;
            }
//负数直接输出结果
        }else{
            return false;
        } 
    }
}
```
注意点：do···while循环体的使用;当条件成立时循环，当条件不成立时跳出。这是与for的主要区别。

