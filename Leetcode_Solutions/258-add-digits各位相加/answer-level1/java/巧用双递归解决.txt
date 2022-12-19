class Solution {
    public int addDigits(int num) {
        if(num < 10){
            return num;
        }else{
            return addDigits(count(num));
        }
    }

    public int count(int n){
        if(n == 0){
            return n;
        }else{
            return n%10 + count(n/10);
        }
    }
}
直接贴代码，下面一个方法求出两位之和，上一个方法递归调用即可求解，看了大神的思路，觉得还是有待提高，贴出阶梯过程仅供大家参考就好了