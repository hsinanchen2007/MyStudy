![image.png](https://pic.leetcode-cn.com/87c2abd8825a395b4952b9075589faa8f5f3b33fe49b4c771ae832ca7d4fd6bd-image.png)


位运算  。。  
```
     int sum = 0;

    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        if (n == 0) {
            return 0;
        }

        Arrays.sort(reservedSeats, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });

        int p = reservedSeats[0][0];
        int t = 0;
        int i = 0;

        while (i < reservedSeats.length ){
            if (p == reservedSeats[i][0]) {
                t |= (512 >> (reservedSeats[i++][1] - 1));
                continue;
            }
            n--;
            addsum(t);
            t = 0;
            p = reservedSeats[i][0];
        }

        addsum(t);
        sum += (n - 1) * 2;

        return sum;
    }

    private void addsum (int t){
        int m = Integer.parseInt(Integer.toBinaryString(~t).substring(22),2);
        int a = m & 510;
        int b = m & 480;
        int c = m & 120;
        int d = m & 30;
        if (a == 510) {
            sum += 2;
            return;
        }
        if (b == 480 || c == 120 || d == 30) {
            sum += 1;
        }
        return;
    }
```
