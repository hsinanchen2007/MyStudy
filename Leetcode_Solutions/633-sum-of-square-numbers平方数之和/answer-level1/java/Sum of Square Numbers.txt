### 解题思路
代码如下
确定最大最小值，减小查找区间以节约时间。

### 代码

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        int i = 0,j = (int)Math.sqrt(c);        //i j 为工作指针，i最小为0，j最大为c的平方根
        int a;                                  // a 记录平方和

        while(i <= j){                         //在i j 之间查找
            a = i * i + j * j;
            if(c == a){                        //如果 相等
                return true;
            }else if(a > c){                   // 如果 大了 j--
                j--;
            }else                               // 小了 i ++
                i++;
        }
        return false;

    }
}
```