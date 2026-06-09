### 解题思路
首先将数组进行排序,
算出数组最大分组用l表示,deck.length()是奇数最大分组就是deck.length/2-1,如果是偶数就是deck.length/2,如果超过最大分组,一定不会被等分的
开始遍历从1到l,从分成1组到分成l组,如果如果deck.length()不能整除i,那么一定不会被等分,直接跳出循环
以[1,2,3,4,4,3,2,1]为例,排序后[1,1,2,2,3,3,4,4],如果i=1那么必定deck[0]=deck[length-1],但是明显这个数组不满足,所以分成1组不正确,然后i++;
需要分为i组,然后从第一组开始temp=1判断是否满足,组内所有的牌上都写着相同的整数。只需要判断组内的首位数据是否相同
可以得到公式deck[(temp - 1) * len] == deck[len * temp - 1],len表示分为i组后,每一组的长度,如果相等说明对应temp组满足条件,然后继续循环,直到有组满足条件说明等分i组可以实现,返回true,如果都不满足返回false
### 代码

```java
class Solution {
    public  boolean hasGroupsSizeX(int[] deck) {
        //数组排序
        Arrays.sort(deck);
        int length = deck.length;
        //计算最大分组数
        int l = length % 2 == 0 ? length / 2 : length / 2 - 1;
        for (int i = 1; i <= l; i++) {
            //如果不能整除i说明肯定不能等分成i分
            if (length % i != 0) {
                continue;
            }
            //temp表示当前验证第temp组,count记录等分成i分之后的每一组满足条件的情况,len表示分成i组后组内的长度
            int temp = 1, count = 0,len = length / i;
            while (temp <= i) {
                //判断组内的两个边界是否相等,如果相等说明该组满足
                //因为已经排好序了，只需要判断每组的首尾元素是否相同
                if (deck[(temp - 1) * len] == deck[len * temp - 1]) {
                    //计数加1
                    count++;
                    //验证组加1
                    temp++;
                } else {
                    //如果有一次验证不通过,说明肯定不会满足了直接break跳出循环
                    break;
                }

            }
            //如果计数的满足条件的组等于分成的i组,即count==i,说明等分成i组满足条件,直接返回true,不需要在继续寻找了
            if (count == i) {
                return true;
            }
        }
        //如果循环跳出没找到,肯定都不满足,返回false
        return false;
    }
}
```