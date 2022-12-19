### 解题思路
* 贪心算法，一开始各种胡思乱想
* 不要假设第一个种或者第一个没种，场景太多，后续每一个位置都可能种了或者没种
* 贪心的关键条件是把所有前后都是0的全部都种上。

### 代码
```java
// 第一步、正常判断条件，存在越界情况无法正常运行
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int flowerCnt = 0;
        for(int i = 0; i < flowerbed.length; i++) {
            //TODO 给i-1越界增加一个or的前置条件i == 0会自动略过左边界i-1 = -1的错误
            //if(flowerbed[i] == 0 && i==0 || flowerbed[i-1] == 0):这会导致第二个元素为1时也会种下去
            //所以需要再增加一个判断条件，[i+1]也得等于0才可以给第一个元素种下去
            //i+1在最后元素时会再次出现越界，所以需要再增加一个i==length-1剔除右边界越界
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                flowerCnt++;
            }
        }
        return flowerCnt >= n;
    }
}
```
```java
第二步、增加贪心条件
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int flowerCnt = 0;
        for(int i = 0; i < flowerbed.length; i++) {
            if(flowerbed[i] == 0 && (i==0 || flowerbed[i-1]==0) && (i == flowerbed.length -1 || flowerbed[i+1]==0) ) {
                flowerbed[i] = 1;
                flowerCnt++;
            }
        }
        return flowerCnt >= n;
    }
}
```