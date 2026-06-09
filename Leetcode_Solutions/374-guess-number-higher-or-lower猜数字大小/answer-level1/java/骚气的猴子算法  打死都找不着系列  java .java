# 猴子排序
猴子排序是一种什么样子的排序呢？ 

猴子排序引用了无限猴子定理：`即一只猴子随机不停的敲击键盘，如果时间足够长，那么它总有可能会打出特定的文本，比如莎士比亚全集？，算法通过不停的随机排列数组，直到数组有序`

这个真实的含义就是把一个无序的数组进行乱排序，然后看其是否会有序，这是个概率性事件，有可能一次之后就有序了，也有可能很多次后依然无序。

实现方法如下： 
1. 定义数组 
2. 数组随机 
3. 检验数组是否有序，无序继续，有序了就停止

# 猴子算法
当然这个算法也可能不存在哈，我给它起的名字，就叫猴子算法，也是随机寻找的意思

所以我想的就是，随机数找这个数字，这样就完事儿了

虽然超出时间限制，但是也很好玩

# 代码
```java
/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int num = 0;
        Random random = new Random();
        while(guess(num) != 0){
            num = random.nextInt(n) + 1;
        }
        return num;
    }
}
```