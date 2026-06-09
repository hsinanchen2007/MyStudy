### 方法一
每个数都遍历一次，查找1的个数，这种时间复杂度较高。

### 代码

```java
class Solution {
    public int[] countBits(int num) {
        return method1(num);
    }

    private int[] method1(int num){
        int[] res = new int[num + 1];
        for(int i=0; i<=num; i++){
            res[i] = getBitCount(i);
        }
        return res;
    }
    private int getBitCount(int m) {
        int cnt = 0;
        while(m != 0) {
            if((m & 1) != 0) {
                cnt++;
            }
            m = m >>> 1;
        }
        return cnt;
    }
}
```

### 方法二
运用数字直接的关系查找；有人说数字直接肯定有关系，后一个数=前一个数+1；这是数字的大小关系，并不是bit数的关系；bit的关系从下图可以看出来。

所有的数，除了第一个1，剩下的bit都是从之前的某个数开始重复。

比如 
2 到 3 除了第一个1，剩余的bit与 0 到 1的bit相同；
4 到 7 除了第一个1，剩余的bit与 0 到 3的bit相同；
8 到 15 除了第一个1，剩余的bit与 0 到 7的bit相同； 

![image.png](https://pic.leetcode-cn.com/9eb58a024fbce15868c51de997eaca1e6fbbb012a896d0f4619e76a90ee25a94-image.png)


### 代码

```java
class Solution {
    public int[] countBits(int num) {
        return method2(num);
    }

    private int[] method2(int num) {
        int[] res = new int[num + 1];
        res[0] = 0;
        if(num == 0) {
            return res;
        }
        res[1] = 1;
        int tmp = 1;
        for(int i=2; i<=num; i++){
            if((i & (i-1)) == 0) {
                tmp = i;
            }
            res[i] = res[i % tmp] + 1;
        }
        return res;
    }
}
```