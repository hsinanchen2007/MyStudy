1. **直接暴力解决了,因为一共就只有24种情况.**
2. **四个数字组成hour和minute两个数,hour要小于24,minute要小于60,**
3. **把符合条件的里面最大的那个找出来就好.**
4. **最后输出的时候注意,hour和minute如果是个位数的话,要加一个0,**
5. **同时用flag来判断是否找到了符合条件的时间,没找到就返回空字符串**
```java
public String largestTimeFromDigits(int[] A) {
        boolean flag = false;
        int maxHour = 0;
        int maxMinute = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (j != i)
                    for (int k = 0; k < 4; k++)
                        if (k != j && k != i) {
                            int l = 6 - i - j - k;
                            int hour = A[i] * 10 + A[j];
                            int minute = A[k] * 10 + A[l];
                            if (hour < 24 && minute < 60) {
                                flag = true;
                                if (hour > maxHour) {
                                    maxHour = hour;
                                    maxMinute = minute;
                                } else if (hour == maxHour && minute > maxMinute)
                                    maxMinute = minute;
                            }
                        }
        if (flag) {
            String hour;
            String minute;
            if (maxHour < 10)
                hour = "0" + maxHour;
            else
                hour = maxHour + "";
            if (maxMinute < 10)
                minute = "0" + maxMinute;
            else
                minute = "" + maxMinute;
            return hour + ":" + minute;
        }
        return "";
    }
```