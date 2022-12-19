### 解题思路
先建立一个二维数组存每一波要分的数量，然后剩下的就按照提示，如果够分就一波走，如果不够分就一个一个来。

### 代码

```csharp
public class Solution {
    public int[] DistributeCandies(int candies, int num_people) {
        int rows = 100000;
        int[][] turn = new int[rows][];
        for(int i=0; i<rows; i++) {
            turn[i] = new int[num_people + 1];
        }
        int cur = 1;

        for(int i=0; i<rows; i++) {
            int tmp = 0;
            for(int j=0; j<num_people + 1; j++) {
                if(j != num_people) {
                    turn[i][j] = cur;
                    tmp += cur;
                    cur += 1;
                }
                else {
                    turn[i][j] = tmp;
                }
            }
        }

        /*
        for(int i=0; i<rows; i++) {
            for(int j=0; j<num_people + 1; j++) {
                Console.WriteLine(i + ", " + j + "\t" + turn[i][j]);
            }
        }
        */
        int cnt = 0;

        int[] res = new int[num_people];
        int time = 0;
        while(candies > 0) {
            if(candies >= turn[time][num_people]) {
                for(int i=0; i<num_people; i++) {
                    res[i] += turn[time][i];

                    cnt++;
                    /*
                    for(int j=0; j<num_people; j++) {
                        Console.WriteLine(res[j] + " ");
                    }
                    */
                }
                candies -= turn[time][num_people];
                time++;
            }

            else {
                for(int i=0; i<num_people; i++) {
                    if(candies >= turn[time][i]) {
                        res[i] += turn[time][i];
                        candies -= turn[time][i];
                    }
                    else {
                        res[i] += candies;
                        candies = 0;
                    }

                    cnt++;
                    /*
                    for(int j=0; j<num_people; j++) {
                        Console.WriteLine(res[j] + " ");
                    }
                    */
                }
            }
        }

        Console.WriteLine(cnt);
        return res;
    }
}
```