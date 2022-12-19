用一个函数处理不同量级的表示情况。具体内容请见注释，应该很明白了。

时间超过了 92.88% 答案
内存超过了 82.84% 答案

```java
class Solution {
    public String intToRoman(int num) {
            StringBuilder sb = new StringBuilder("");
            num = (num >= 1000 ? modify(num, "", "", "M", sb) : num);   //处理完就是100-1000了
            num = (num >= 100 ? modify(num, "M", "D", "C", sb) : num);  //处理完就是10-100了
            num = (num >= 10 ? modify(num, "C", "L", "X", sb) : num);   //处理完就是1-10了
            num = (modify(num, "X", "V", "I", sb));                     //处理完就是0了
            return sb.toString();
        }
    private static int modify(int num, String tenMod, String halfMod,String oneMod, StringBuilder sb) {
        /*  
            格式处理函数
            参数解释：
            num： 传入的数字
            tenMod： 当前数量级表示 单位10 的修饰符
            halfMod： 当前数量级表示 单位5 的修饰符
            oneMod： 当前数量级表示 单位1 的修饰符
            sb： 传入的StringBuilder ID
            如果当前为100-1000的量级，则tenMod为表示1000的String，halfMod为表示500的String，oneMod为表示100的String，以此类推
        */
        if (num == 0) {return 0;}   //如果数字是0不用处理
        int div = 1;
        while(num/div != 0){div *= 10;}     //获取数量级
        int count = num/(div/10);           //获取有几个当前量级的 单位1
        int p = count;
        num -= count * div/10;
        switch (p) {
            case 4: sb.append(oneMod+halfMod);break;    //如果有4个单位1，表示方法为 单位1表示符 + 单位5表示符
            case 9: sb.append(oneMod+tenMod);break;     //如果有9个单位1，表示方法为 单位1表示符 + 单位10表示符
            default: {
                if (p<4) {                              //小于4个 单位1，直接append 4个单位1
                    while(p>0) {sb.append(oneMod);p--;}
                } else {                                //其余情况就是大于5小于9的，则先append 1个单位5，然后剩下的append单位 1
                    sb.append(halfMod);
                    while(p>5) {sb.append(oneMod);p--;}
                }
            }
        }
        return num;
    }
}
```
