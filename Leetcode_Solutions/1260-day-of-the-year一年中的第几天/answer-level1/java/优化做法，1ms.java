```
class Solution {
    public int dayOfYear(String date) {
        int[] monthDays = new int[]{31,28,31,30,31,30,31,31,30,31,30,31};
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8, 10));
        int dayOfYear = 0;
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) monthDays[1] = 29;
        for (int i = 0; i < month -1 ; i++) {
            dayOfYear += monthDays[i];
        }
        return dayOfYear+day;
    }
}
```
一开始想的是使用hashMap或者case-when，但hashMap出来的结果有点出乎意料的慢，后来一想，这相当于走了一次索引(key)，再获取value，慢是正常的，然后就改换数组，数据因为是连续存储，所以里面的地址就直接相当于key了，就不需要搜寻了，速度自然也就快起来了