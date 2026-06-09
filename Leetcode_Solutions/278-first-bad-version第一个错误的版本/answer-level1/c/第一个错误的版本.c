非常类似下面这个问题：

有一栋楼共 100 层，一个鸡蛋从第 n 层及以上的楼层落下来会摔破，在第 n 层以下的楼层落下不会摔破。给你 2 个鸡蛋，设计方案找出 n，并且保证在最坏情况下，最小化鸡蛋下落的次数。

**题解:**
- 第 1 次从 $x$ 楼扔下来。即使摔坏了，也可以用另一个鸡蛋遍历 $x-1$ 次从 1 楼到 $x-1$ 楼找到该楼层。
- 第 2 次（还剩下 $x-1$ 次尝试次数）可以从 $x+(x-1)$ 层扔下来。即使摔坏了，也可以用另一个鸡蛋遍历 $(x-1)-1$ 次从 $x+1$ 楼到 $x+(x-1)-1$ 楼找到该楼层。
- 同理，第3次，可以从 $x+(x-1)+(x-2)$ 层扔下来。
- 第 $x$ 次，可以从第 $x+(x-1)+(x-2)+...+(x-(x-1))$ 层扔下来，这就是最高可能尝试的楼层 $x(x+1)/2$，下面所有的楼层都可以在 $x$ 次尝试中到达。

当最高楼层为 100 时，最高可能尝试到的楼层 $x(x+1)/2\geqslant100$，解出 $x=14$ 次。

**解方程：**
$$
x(x+1)/2\geqslant{n}
$$
左右乘以8
$$
4x^2+4x\geqslant{8n}
$$
左右加上1
$$
4x^2+4x+1\geqslant{8n+1}
$$
即
$$
(2x+1)^2\geqslant{8n+1}
$$
得到
$$
x\geqslant{\frac{\sqrt{8n+1}-1}{2}}
$$
取值
$$
x=\left⌈\frac{\sqrt{8n+1}-1}{2}\right⌉
$$
对 $x$ 向上取整，有 $x=14$。


```C []
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int step = (sqrt(8.0 * n + 1) - 1) / 2 + 0.5;
    int curr = step, low = 1;
    while (curr <= n && step >= 1){
        if (isBadVersion(curr)){
            for (int i = low; i < curr; ++i){
                if (isBadVersion(i)) return i;
            }
            return curr;
        } else {
            low = curr + 1;
            curr += --step;
        }
    }
    return n;
}
```

