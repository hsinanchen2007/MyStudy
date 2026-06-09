### 解题思路
题意：有n（deck.length）个整数的数组，是否存在一个整数X使得该数组能够分成X组，并且每一组中的数据都一样。
    这样我们可以发现：
    1，X是存在一个范围的，即是：2 - deck.length。
    2，X应该能够被deck.length整除，如果不行的话肯定就分不了组啦。

那么我们就可以搞个循环遍历每一个在允许范围内的X，找这个范围中是否存在这样一个X，使得满足条件的。

怎么找呢？
    1，可以先将这个数组进行排序，这里我直接调用了内置的快排函数
    2，对于每一个X，重头开始遍历数组看是否可行
    3，遍历的过程是：我们可以将每X个值看成一个子数组，只要判断该子数组中的第一个和最后一个是否是一样的就可以判断这X个值是否是一样的了，因为我们已经排好序了。

时间复杂度：快排为O(nlogn),遍历每个X的次数最坏为n-2，每一次遍历中当X满足条件时又进行了n % X 次的判断即为logn,因此总的遍历也为O(nlogn)。所以最后的时间复杂度应该为O(nlogn)


### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int X = 2;
        boolean flag = false;   //设立标志位，用来判断循环是否应该继续执行
        Arrays.sort(deck);      //先将数组进行排序

        while (X <= deck.length) {
            if (deck.length % X != 0) { //如果不能整除那就肯定不能分组，直接排除这个情况
                flag = false;
                X++;
                continue;
            }
            int count = 0;  //数组遍历计数器
            while (count < deck.length) {      
                if (deck[count] == deck[count + X - 1]) {   //判断每X个值是否相等，直接比较最后一个和第一个
                    count += X;
                    flag = true;
                    continue;
                }
                flag = false;
                break;      //只要有一组不满足就该X就直接不行了
            }
            if (flag) return true;
            X++;

        }
        return false;
    }
}

```

执行结果：时间3ms，打败84%的java提交用户。
      内存消耗：42.3MB，打败5.64%的用户

最后：感觉代码写的有点难看，但是不知道怎么优化哈。