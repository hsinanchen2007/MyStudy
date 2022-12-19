🙋 再晚也要打个卡！

### 一、题目分析

- **读题知：** 每种数字的卡牌张数必须是X的倍数（只有这样才能每X张牌分为1组，且每组牌的数字都相同), 且X>1。由此，本题转换成了求: 每种卡牌张数的最大公约数。

- 那么**实现方法**就很简单了：

    **1、计数**（本题数据范围有限直接数组计数即可）
    **2、求计数数组的最大公约数**（👇）

- 2个数求gcd直接辗转相除法，至于**如何求多个数的最大公约数**：
  
  根据数论中的gcd结合律知：
![image.png](https://pic.leetcode-cn.com/ce1b4c3772e7757c2c120ad0f26fb5195c8a2ba741cb19a4ae1bf45bbada4437-image.png){:height="40%" width="40%"}
感兴趣的可以👉[戳](https://math.stackexchange.com/questions/1189424/gcda-b-c-gcd-gcda-b-c-gcd-associative-law)👈
所以迭代求gcd就行了。

### 二、代码

##### 1、先说一个3ms的方法

``` Java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        // 计数
        int[] counter = new int[10000];
        for (int num: deck) {
            counter[num]++;
        }
        // 迭代求多个数的最大公约数
        int x = 0;
        for(int cnt: counter) {
            if (cnt > 0) {
                x = gcd(x, cnt); 
                if (x == 1) { // 如果某步中gcd是1，直接返回false
                    return false;
                }
            }
        }
        return x >= 2;
    }
    
    // 辗转相除法
    private int gcd (int a, int b) {
        return b == 0? a: gcd(b, a % b);
    }
}
```

##### 2、迭代求gcd的过程可以用reduce算子进行代码简化

``` Java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        // 计数
        int[] counter = new int[10000];
        for (int num: deck) {
            counter[num]++;
        }
        // reduce求多个数的最大公约数
        // （因为这里当gcd==1的时候没有提前终止，并且本题数据量太小无法用并行流，因此耗时10ms，比for循环慢点）
        return Arrays.stream(counter).reduce(this::gcd).getAsInt() >= 2;
    }
    
    // 辗转相除法
    private int gcd (int a, int b) {
        return b == 0? a: gcd(b, a % b);
    }
}
```

其中，`reduce(this::gcd)` 即为 `reduce((a, b) -> gcd(a, b))`
下图以`reduce((a, b) -> a + b)`来解释reduce算子：
![image.png](https://pic.leetcode-cn.com/2946e5fcf0a5a053c409926c8b89414199dc4d36a97e7a4fae42f4e5fdd0a7c8-image.png){:height="40%" width="40%"}



大佬们随手关注下我的wx公众号【[甜姨的奇妙冒险](https://pic.leetcode-cn.com/304599b006dd41bcf2042715f31a2dc4fbdc4cf9748a11a81d8978ea1e839956-wxgzh.jpeg)】和 知乎专栏【[甜姨的力扣题解](https://zhuanlan.zhihu.com/c_1224355183452614656)】