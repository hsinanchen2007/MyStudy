### 思路

看到**连通**两个字样，十有八九就是**并查集**类型的题目，此时我们就应该拿出精心准备的并查集模板出来（结尾附赠）。

我们将**互相连通**的电脑压缩成**一个点**，若最后存在 N 个点，通过观察可以发现只需要 `N - 1` 条线就可以进行相连。

![image.png](https://pic.leetcode-cn.com/21d4a6c3667907c3319b5a9ca67d401adb5b7df270a5af3a1835787d27977d27-image.png)


那接下来的问题就是如何去寻找这 `N - 1` 条线。

考虑每一条线，如果线的两头已经连通（`find(p) == find(q)`），则这条线是**多余**的，可以拿去当做 `N - 1` 条线的其中一条。

### 代码

```java
class Solution {
    int[] father;
    int[] sz;
    int num;

    public int find(int p) {
        if (p != father[p]) {
            p = find(father[p]);
        }
        return p;
    }
    public void union(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;
        num -= 1;
        if (sz[i] < sz[j]) {
            father[i] = j;
            sz[j] += sz[i];
        } else {
            father[j] = i;
            sz[i] += sz[j];
        }
    }

    public void initUF(int n) {
        father = new int[n];
        sz = new int[n];
        num = n;
        for (int i = 0; i < n; i++) {
            father[i] = i;
            sz[i] = 1;
        }
    }
    public int makeConnected(int n, int[][] connections) {
        initUF(n);
        // 多余的线缆数量
        int cnt = 0;
        for (int[] c : connections) {
            int f = c[0], t = c[1];
            // 两个点已经连通，不需要这个线缆
            if (find(f) == find(t)) {
                cnt += 1;
                continue;
            }
            union(f, t);
        }
        // 所需要的线缆数量
        int cnt2 = num - 1;
        if (cnt < cnt2) {
            return -1;
        }
        return cnt2;
    }
}
```

### 并查集模板

#### 版本一：加权快速合并

```java
int[] father;
int[] sz;
int num;

public int find(int p) {
    if (p != father[p]) {
        p = find(father[p]);
    }
    return p;
}
public void union(int p, int q) {
    int i = find(p);
    int j = find(q);
    if (i == j) return;
    num -= 1;
    if (sz[i] < sz[j]) {
        father[i] = j;
        sz[j] += sz[i];
    } else {
        father[j] = i;
        sz[i] += sz[j];
    }
}

public void initUF(int n) {
    father = new int[n];
    sz = new int[n];
    num = n;
    for (int i = 0; i < n; i++) {
        father[i] = i;
        sz[i] = 1;
    }
}

```


#### 版本二：路径压缩的加权快速合并

```java
int[] father;
int[] sz;
int num;
public int find(int p) {
    if (p != father[p]) {
        father[p] = find(father[p]);
    }
    return father[p];
}
public void union(int p, int q) {
    int i = find(p);
    int j = find(q);
    if (i == j) return;
    num -= 1;
    if (sz[i] < sz[j]) {
        father[i] = j;
        sz[j] += sz[i];
    } else {
        father[j] = i;
        sz[i] += sz[j];
    }
}

public void initUF(int n) {
    father = new int[n];
    sz = new int[n];
    num = n;
    for (int i = 0; i < n; i++) {
        father[i] = i;
        sz[i] = 1;
    }
}
```

&nbsp;

---

如果该题解对你有帮助，点个赞再走呗~