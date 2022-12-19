1. 首先判断一下有效num的范围，可以一眼看出来num的取值范围为0～10。对于10的话，是取不到的，因为分钟（0～11）和小时（0～59）都会溢出，即63分钟和15小时。而9的话则是分钟或小时中的一个会溢出，导致也没有符合要求的答案，故返回空列表。
2. 分钟和小时总共构成了10bit，它表示的范围是小于1024的，我们从0分0时，开始累加，筛选出数值的二进制含有num个1，再进一步对分钟和时钟进行筛选。
3. 特殊处理，hour和minute可能不在其规定的范围，以及分钟可能展示形式不符合要求。

代码如下：
```
class Solution {
    public List<String> readBinaryWatch(int num) {
        if (num < 0 || num > 8) {
            return Collections.emptyList();
        }
        int hour = 0,minute = 0;
        List<String> ans = new ArrayList<>();
        // 累加一分钟，统计1的个数，分离出时和分钟
        for (int i = 0; i < 1024; i++) {
            if (countOnes(i) == num) {
                minute = i & ((1 << 6) - 1);
                hour = (i >> 6) & ((1 << 4) - 1);
                if (hour < 12 && minute < 60) {
                    String m = "";
                    String h = Integer.toString(hour);
                    if (minute < 10) {
                        m = "0" + Integer.toString(minute);
                    } else {
                        m = Integer.toString(minute);
                    }
                    ans.add(h +":" +m);
                }
            }
        }
        return ans;
    }
    private int countOnes(int num) {
        int count = 0;
        while (num > 0) {
            num = num & (num - 1);
            count++;
        }
        return count;
    }
}
```