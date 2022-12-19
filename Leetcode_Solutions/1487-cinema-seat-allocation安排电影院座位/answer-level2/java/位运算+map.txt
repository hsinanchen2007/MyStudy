一、样例的n有10亿，使用dp直接超内存；
    dp的类型尝试过使用boolean、int、char都是超内存...
二、逐排处理，又超时间...各种超时

解决：
     周赛的时候没仔细看给定的条件；
     后来发现1 <= reservedSeats.length <= **min**(10*n, **10^4**)
     即reservedSeats的最大长度就是1万，就是说最多有1万的座位被预定。至少有9亿9999万是空排
     用map记录哪些排有人预定；另外的排就避免处理了

     反过来想，初期设置每排都能安排2户家庭（总计n*2）；有预定的排再行处理
     
     然而，依然是超时
    使用System.out.println()打印，使用位运算的前提下，执行在2~3亿数据量的时间就超时了

     最后在题解区看到了一点提示
     还是reservedSeats的长度的问题，当处理的实际个数达到了map的size，说明所有的预定座都已经处理过了。
     后面的排，不需要处理了!!!!

最后的执行在 85 ~ 100ms区间

```
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        int temp = 0b10000000000;
        int sum = 2 * n;
        int row = 0;
        int col = 0;
        int left = 0b0111100000;   //2345座
        int middle = 0b0001111000; //3456座
        int right = 0b0000011110;  //5678座
        HashMap<Integer, Integer> hashMap = new HashMap<>(reservedSeats.length * 2);
        for (int[] reSeat : reservedSeats) {
            row = reSeat[0];
            col = reSeat[1];
            //第一个座、最后一个座，压根不会影响后面的安排 ☆
            if (col == 1 || col == 10) {
                continue;
            }
            //将订座信息存到map中
            if (hashMap.containsKey(row)) {
                int val = hashMap.get(row) | (temp >> col);
                hashMap.replace(row, val);
            } else {
                hashMap.put(row, temp >> col);
            }
        }

        int x = 0;
        //逐排处理
        for (int i = 1; i <= n; i++) {
            //map中所有的排都处理完了，后面的n对应的都是空排
            if (x >= hashMap.size()) {
                break;
            }
            //有人预定的排，分析
            if (hashMap.containsKey(i)) {
                x++;
                int val = hashMap.get(i);
                //这一排没人预定，continue
                if (val == 0) {
                    continue;
                }
                //这一排有人预定了，那么剩下的座最多安排一个家庭了
                //（请注意，前面☆的位置，把第一个座、最后一个座有人的情况排除掉了）
                //方便后面的分析，先 -2
                //即，认为这一行不能安排家庭
                sum -= 2;
                //判断能安排家庭的情况，即是left、middle、right模式有一个满足没人预定的情况
                if ((val & left) == 0 || (val & middle) == 0 || (val & right) == 0) {
                    sum++;
                }
            }
        }

        return sum;
    }
}
```

