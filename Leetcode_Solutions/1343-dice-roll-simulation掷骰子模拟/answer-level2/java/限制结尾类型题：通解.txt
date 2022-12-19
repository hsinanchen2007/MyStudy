**类似题： 1220**
```
/**
 * 主要解题思路：  用变量记录以xx结尾的数/字母的情况，但是这道题变量太多，所以改用数组;
 * 如 records[1][6] 表示以1结尾，连续出现6次1的情况有多少种；
 * 如 records[2][3] 表示以2结尾，连续出现3次2的情况有多少种；
 * 知道这个以后，
 * 我们又可了解到  records[1][1] =  sum(//以 2、3、4、5、6结尾的情况之和，但不能包括自己)   //因为抛出2、3、4、5、6后 再抛出1，是没有任何问题的；
 * 如上，便可解题
 */
public class Solution {
    public static final int limit = 1_000_000_007; 
    public int dieSimulator(int n, int[] rollMax) {
        int[][] records = new int[7][16];  // 二维数组表示以某个数字结尾了多少次
        int[][] temp_records = new int[7][16];  //临时数组暂存数据

        for (int i=1; i<=6; i++){   //只抛一次时，都是1
            records[i][1] = 1; 
        }

        for (int i=2; i<= n; i++){
            for (int j =1; j<= 6; j++){
                temp_records[j][1] = sumBesides_self(records,j);  //以j结尾只出现一次，是以其他数字结尾的情况之和
                int index = 2;
                int max = rollMax[j-1];
                while (index <= max){  //规定不能超出max个情况
                    temp_records[j][index] = records[j][index-1];
                    index++;
                }
            }
            records = temp_records;  // 保存数据，清空临时数组
            temp_records = new int[7][16];
        }

        int sum = 0;    //求和
        for (int i=1; i<=6; i++)
            for (int j=1; j<=15; j++)
                sum = (sum + records[i][j]) % limit;

        return sum;
    }

    public int sumBesides_self(int[][] records ,int tar){
        int sum = 0;
        for (int i=1; i<=6; i++){
            if (i != tar){
                for (int j=1; j<=15; j++)
                    sum = (sum + records[i][j]) % limit;
            }
        }

        return sum;
    }
}
```
