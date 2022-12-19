### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        //方法：对reservedSeats排序，然后对每一行分别计算，当某些行不存在时，则加2；
        //需要考虑：
        //对每行计算时，当该行遍历结束，但是后面还有空位时，应该进行计算
        //需要注意：
        //jishu、使用j遍历某行的座位
        Arrays.sort(reservedSeats, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0]==o2[0]) return o1[1]-o2[1];
                return o1[0]-o2[0];
            }
        });
        int result = 0;
        int jishu = 1;
        for(int i = 0 ; i < reservedSeats.length;){
            int row = reservedSeats[i][0];
            if(row > jishu){
                result += 2 * (row - jishu);
            }
            jishu = row+1;
            int count = 0;
            int j = 2;
            while(i < reservedSeats.length && reservedSeats[i][0] == row){
                if(reservedSeats[i][1] == 1){i++;continue;}
                if(reservedSeats[i][1] > j){
                    count++;
                    j++;
                }else if(reservedSeats[i][1] < j){
                    i++;
                }else if(reservedSeats[i][1] == j){
                    switch(j){
                        case 2,3:
                            j = 4;
                            break;
                        case 4,5:
                            j = 6;
                            break;
                        case 6,7,8,9:
                            j = 10;
                            break;
                    }
                    count = 0;
                    i++;
                }
                if(count == 4) {result++;count = 0;}
            }
            if(j < 10){
                switch(j){
                    case 2:
                        result += 2;
                        break;
                    case 3,4,5,6:
                        result += 1;
                        break;
                }
            }
        }
        if(jishu <= n){
            result += 2 * (n - jishu + 1);
        }
        return result;
    }
}
```