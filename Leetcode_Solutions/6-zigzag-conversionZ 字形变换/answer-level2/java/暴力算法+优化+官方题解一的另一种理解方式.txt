
#### 方法一：暴力求解一把梭

##### 思路

遍历一遍字符串，计算每个字符串的在`z`字形输出里的对应的横、纵坐标。之后计算出`x*row+y`的大小。最后排序按序输出。

##### 算法

下标为`i`的字符在`z`字形输出种的横坐标`x`和纵坐标`y`可以表达为：

+ $\mathrm{MOD}(i,\space group)\gt numRows-1$时：
    + $x= \frac{i}{group} \times (numRows - 1) + i\%group - numRows + 1$
    + $y = 2 \times numRows-2-i\%group$
+ $\mathrm{MOD}(i,\space group)\le numRows-1$时：
    + $x=\frac{i}{group}\times (numRows - 1) + 1$
    + $y = i\%group$

> 注：这里的`group`等于$(numRows - 3) \times 2 + 4$

<br>
```java []
class Pair {
    int key;
    char c;

    public Pair(int key, char c) {
        this.key = key;
        this.c = c;
    }
}

class Solution {
    public String convert(String s, int numRows) {
        int len = s.length();
        if (len <= 1 || numRows == 1)
            return s;
        int group = (numRows - 3) * 2 + 4;

        char[] zigzag = s.toCharArray();

        int col = (len / group + 1) * (numRows - 1);
        List<Pair> list = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            int group_num = i / group;
            int group_seq = i % group;

            int x = 0;
            int y = 0;
            if (group_seq > numRows - 1) {
                x = group_num * (numRows - 1) + group_seq - numRows + 1;
                y = 2 * numRows - 2 - group_seq;
            } else {
                x = group_num * (numRows - 1) + 1;
                y = group_seq;
            }
            list.add(new Pair(y * col + x, zigzag[i]));
        }

        list.sort(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return o1.key - o2.key;
            }
        });

        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < len; i++) {
            builder.append(list.get(i).c);
        }

        return builder.toString();
    }
}
```
得到的结果是这样的。。。

![TIM图片20200225220028.png](https://pic.leetcode-cn.com/faaf50b5cb93d322a04330c5e7322594846a9d9ff3102096a7f9f412018e6a8f-TIM%E5%9B%BE%E7%89%8720200225220028.png)


#### 优化

没错，暴力求解的方法速度又慢又难以理解，而且还很难编写。但是，我们只需要观察一下`z`字形图案就能得到很大的优化。首先，我们先来观察一下`z`字形图案：

```
L     D     R
E   O E   I I
E C   I H   N
T     S     G
```
可以看出，对于在`z`字形图案中的同一行的那些字符。其横坐标对其输入顺序和其输出顺序是一样的。换句话说就是：如果两个字符在`z`字形图案中的行相同，那么其输入的先后顺序和其输出的先后顺序相同。根据上面的分析，我们就可以很轻松的把代码写出来：

```java []
public class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1)
            return s;


        int group = (numRows - 3) * 2 + 4;
        List<StringBuilder> list = new ArrayList<>();
        char[] str = s.toCharArray();
        for (int i = 0; i < str.length; i++) {
            int group_seq = i % group;
            int row = group_seq > numRows - 1 ? 2 * numRows - 2 - group_seq : group_seq;
            if(list.size() <= row) list.add(new StringBuilder());
            list.get(row).append(str[i]);
        }

        StringBuilder res = new StringBuilder();
        for(StringBuilder row:list) res.append(row);
		
        return res.toString();
    }
}
```

是不是感觉很像官方题解中的方法一？没错，其实官方题解中的方法一其实就是通过这种思路简化了计算。

优化完之后，可见性能有了很大提升。

![TIM图片20200225220127.png](https://pic.leetcode-cn.com/b5e0821857b343e73dc7c08888c72be99dca0b5a8743b7dc703917be57d35f32-TIM%E5%9B%BE%E7%89%8720200225220127.png)
<br>
