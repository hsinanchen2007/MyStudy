```
public class Solution {
    public int Reverse(int x) {
        //思路：利用取模和取整的方法
        int newVal = 0;//保存反转后的值
        while(x != 0){
            //在newVal乘以10之前判断是否溢出
            if(newVal > int.MaxValue / 10 || newVal < int.MinValue / 10){
                return 0;
            }
            newVal = newVal * 10 + x % 10;
            x /= 10;
        }
        return newVal;
    }
}
```