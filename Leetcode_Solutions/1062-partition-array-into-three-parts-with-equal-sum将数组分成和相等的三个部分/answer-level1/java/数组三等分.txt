### 解题思路
1.数组之和必须为3的倍数
2.每小段元素之和必须相等
3.必须能拆成3部分

### 代码

```java
class Solution {
public boolean canThreePartsEqualSum(int[] A) {

        //解题思路：满足条件的数组的元素必须是3的倍数，并且拆分后的每个数组之和都为：数组之和除以3

        //元素个数必须不小于3
        if (A.length < 3) return false;




        //求数组之和

        int sum = 0;
        for (int i = 0; i < A.length; i++) sum += A[i];

        if (sum % 3 == 0) {
            sum = sum / 3;
            System.out.println("sum:"+sum);
        } else
            return false;

             //开始遍历数组，判断是否存在元素相加为sum/3
            int part1 = 0;
            int part2 = 0;
            int part3 = 0;
            
            //必须有三部分，count不为0才有第3部分！
            int count=0;
            for (int i = 0; i < A.length; i++) {
                part1 += A[i];
                if (part1 == sum) {
                    for (int j = i + 1; j < A.length; j++) {
                        part2 += A[j];
                        if (part2 == sum) {
                            for (int k = j + 1; k < A.length; k++) {
                                part3 += A[k];
                                count ++;

                            }
                            //不再遍历下一轮的j
                            break;

                        }

                    }
                    //不再遍历下一轮的i
                    break;

                }


            }


        //判断三部分是否相等
        if (part1 == part2 && part2 == part3 && count!=0) {
            return true;
        } else
            return false;


    }

}
```