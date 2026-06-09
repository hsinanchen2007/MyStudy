### 解题思路
非暴力法，利用等差数列求和公式

### 代码

```java
class Solution {
    // 思考，循环分是一种办法，不过太粗糙了
    // 考虑糖果一定是以n(人数)为列，k行和k+1行之间
    // 第k行和第k+1行，二者之差是n的平方
    // 比如6个人
    // 1 2 3  4  5  6 = 21
    // 7 8 9 10 11 12 = 57
    // 第一行和第二行的差是6的平方，36
    // 所以就存在快速定位的可能
    // 如果糖果总数不是人数连续自然数的和，那么必然在下一行之间
    public int[] distributeCandies(int candies, int num_people) {
        // 行计数器
        // 最少1行
        int row = 1;
        int delta = num_people * num_people;
        // 初始需要分的数
        int sum = (num_people + 1) * num_people / 2;
        int nextLine = sum;
        while (sum < candies) {
            // 这是本行的+过去所有的
            nextLine = nextLine + delta;
            sum += nextLine;
            row++;
        }
        // 有了行数就好办了
        // 每一列都是等差数列求和
        // debug(row, num_people);

        // 按照列求和
        // 一定要少求1列
        int[] result = new int[num_people];
        int r = row - 1;

        // 初始化
        sum = 0;
        for (int i = 0, j = 1; i < num_people; i++, j++) {
            // 这个是核心，这个是等差数列求和公式
            result[i] = j * r + (r - 1) * r * num_people / 2;
            sum += result[i];
        }
        // 这个时候sum是少了底下一行的
        // System.out.println("剩下 " + (candies - sum) + " 糖果");

        // 然后补上不足的最后一行
        // 从第0列开始
        int left = candies - sum;
        while (left > 0) {
            for (int col = 0; col < num_people; col++) {
                // 第一行和其他行不一样
                if (row > 1) {
                    // 足够分给1个人的
                    int v = col+1+(row - 1) * num_people;
                    if (left >= v) {
                        result[col] += v;
                        sum += v;
                        left -= v;
                    } else {
                        result[col] += left;
                        sum += left;
                        left = 0;
                    }
                } else {
                    int v = col + 1;
                    if (left > v) {
                        result[col] = v;
                    } else {
                        result[col] = left;
                    }
                    left -= v;
                    if(left <= 0){
                        break;
                    }
                }
            }
        }

        return result;
    }
}
```