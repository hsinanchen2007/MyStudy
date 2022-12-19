```
class Solution {
    public void reverseString(char[] s) {
        int len = s.length;
        if(len > 0){
            char tmp = s[0];
            //偶数：左中位，右中位数:这两个数也要互相交换
            //奇数：中位数 不需要改动
            //>>> 无符号右移，取中位数的方法 int mid = (left+right)>>>1;
            int mid = len>>>1;
            for(int i=0; i<mid; i++){
                tmp = s[i];
                s[i] = s[len-1-i];
                s[len-1-i] = tmp;
            }
        } 
    }
}
```
