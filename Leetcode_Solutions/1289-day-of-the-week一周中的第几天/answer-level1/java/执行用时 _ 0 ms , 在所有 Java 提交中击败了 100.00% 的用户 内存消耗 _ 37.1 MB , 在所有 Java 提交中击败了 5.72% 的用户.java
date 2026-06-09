我承认我的方法很笨，但是容易理解。首先，该年是从1971开始计算，我们必须知道1971.1.1究竟是星期几，这很重要，在知道是星期五后，我们以此为基准，计算1971.1.1到给定时间的总天数，再加4，因为是从星期五开始，这一点必须理解，也是核心思想，针对闰年，加366，反之365，闰年2月29天，反之28天，通过计算总天数除以7，余数即我们的待求的数，设置arr为储存周几，考虑周日的特殊性，把周日放到第一位，基本思想就这么多，代码已经用回车隔开了，可以一看。

### 代码

```java
class Solution {
    public String dayOfTheWeek(int day, int month, int year) {
        int sum = 4;
        if(year!=1971) {
            for(int i = 1971;i<year;i++) {
                sum+=Tianshu(i);
            }
        }



        String[] arr = new String[7];
        arr[0]="Sunday";
        arr[1]="Monday";
        arr[2]="Tuesday";
        arr[3]="Wednesday";
        arr[4]="Thursday";
        arr[5]="Friday";
        arr[6]="Saturday";
        int[] brr = new int[12];
        brr[0] = 31;
        brr[2] = 31;
        brr[3] = 30;
        brr[4] = 31;
        brr[5] = 30;
        brr[6] = 31;
        brr[7] = 31;
        brr[8] = 30;
        brr[9] = 31;
        brr[10] = 30;
        brr[11] = 31;



        if(year%4==0&&year%100!=0||year%400==0) {
            brr[1]=29;
            if(month==1) {
                return arr[(day+sum)%7];
            }
            for(int i = 0;i<month-1;i++) {
                sum+=brr[i];
            }
            sum+=day;
            return arr[sum%7];
        }else {
            brr[1]=28;
            if(month==1) {
                return arr[(day+sum)%7];
            }
            for(int i = 0;i<month-1;i++) {
                sum+=brr[i];
            }
            sum+=day;
            return arr[sum%7];
        }


    }

    public int Tianshu(int a) {
        if(a%4==0&&a%100!=0||a%400==0) {
            return 366;
        }
        return 365;
    }


}
```