利用数学的方法,先根据一元二次方程的解求出要进行的次数,
然后求出轮次,和剩余轮次,找出规律,最后加上剩余的数
```
    public int[] distributeCandies(int candies, int num_people) {
        //求最多的(n+1)次,注意,candies*8会超出int范围
        int n = (int) (Math.sqrt((long) candies * 8 + 1) - 1) / 2;
        //求出完整多少轮
        int turn = n / num_people;
        //求出剩余次数
        int mod = n % num_people;
        int[] arr = new int[num_people];
        //根据mod来区分获得糖数
        for (int j = 0; j < num_people; j++) {
            if (j < mod) {
                arr[j] = (turn * turn + turn) / 2 * num_people + (turn + 1) * (j + 1);
            } else {
                arr[j] = (turn * turn - turn) / 2 * num_people + turn * (j + 1);
            }
        }
        //把剩余的数加上
        arr[mod] += candies - (n * n + n) / 2;
        return arr;
    }
```
