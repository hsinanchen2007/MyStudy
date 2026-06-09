### 解题思路
想法就是记录有多少个连续3个0的情况出现，但要考虑几种情况：

1. 开头是0的情况，这种情况只要在前两个元素是0，开头的0就可以种花
2. 结尾是0的情况，这种情况和第一种同理
3. 连续5个0的情况，这时候[0, 0, 0, 0, 0]

处理的方法也很简单，就是在计算0数量的时候，将初始值设置为1（zeroNum = 1）。

情况2的处理是：如果for循环结束，zeroNum中还记录了两个0，就返回true

### 代码

```java
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {

        int zeroNum = 1, count = 0;

        for(int num:flowerbed){
            if(num == 0){
                zeroNum++;
            }else if(num == 1){
                zeroNum = 0;
            }
            

            if(zeroNum == 3){
                count++;
                zeroNum = 1;
            }
        }

        if(zeroNum == 2) count++;

        return (count >= n ) ? true:false;
    }
}
```