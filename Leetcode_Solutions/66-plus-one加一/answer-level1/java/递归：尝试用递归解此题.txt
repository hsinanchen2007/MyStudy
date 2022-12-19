**思路：**
关键的问题在与怎么`进位+1`，特别是在多个进位的情况下，使用递归解决也是一种新的思路。

假设输入`[8,9,9]`，每个位都需要加1，因此用递归从最右的元素开始，向左移动进位，直到打破的进位的条件。

假设输入`[9,9,9]`，当发现最后一位的下标小于0，也应该停止进位，然后创建一个新数组返回即可。

**递归实现：**


``` Java
class Solution {
    public int[] plusOne(int[] digits) {
        return plus(digits,digits.length - 1);
    }

    int[] plus(int[] digits,int i){
        //当前元素加1，然后求出余数给自己
        digits[i] = ++digits[i] % 10 ;
        //是否发生了进位？
        if(digits[i] == 0){
            //是不是数组的最后一位
            if(--i < 0){
                //重新写新的数组返回
                int[] temp = new int[digits.length+1];
                temp[0] = 1;
                return temp;
            }else{
                //递归进位
                return plus(digits,i);   
            }
        }
        return digits;
    }
}
```
