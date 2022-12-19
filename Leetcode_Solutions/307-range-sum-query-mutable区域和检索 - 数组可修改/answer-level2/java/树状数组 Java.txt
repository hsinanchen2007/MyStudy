![TIM截图20191230194139.jpg](https://pic.leetcode-cn.com/7048dc5024b44fc8e64e0a6312236ffb142038cc24c4eb8d9fad929c1ee7385c-TIM%E6%88%AA%E5%9B%BE20191230194139.jpg)

思路：树状数组
![0dd7912397dda14482d369acbfb7d0a20df486d1@wm_1,g_7,k_d2F0ZXIvYmFpa2U5Mg==,xp_5,yp_5.jfif](https://pic.leetcode-cn.com/19c7d9c01538a369e2b0e0f6fd60b9169bafd5699f9c5cda723f207f775d3361-0dd7912397dda14482d369acbfb7d0a20df486d1@wm_1,g_7,k_d2F0ZXIvYmFpa2U5Mg==,xp_5,yp_5.jfif)

**1，构造：**
分层构造，从最底层开始不断向上求和。
第一层使用输入值填充（注意树状数组的索引是从1开始）；
第二层以2为步长更新，计算第一层相邻节点的和，构造第二层的节点；
第三层以4为步长更新，计算第二层相邻节点的和，构造第三层；
...
以此类推，直到构造出最高层。
```
private int[] arr;
private int[] tree;
private int length;
public NumArray(int[] nums) {
    length = nums.length + 1;
    arr = nums;
    tree = new int[length];
    //第一层
    System.arraycopy(nums, 0, tree, 1, nums.length);
    int step = 2, offset = 1;
    //自下向上构造
    while(step < length) {
        for(int i = step; i < length; i+= step) {
            tree[i] += tree[i - offset];
        }
        step = step << 1;
        offset = offset << 1;
    }
}
```
**2，更新**
对第i个节点的更新会更新所有包含第i个节点信息的节点。
或者说，对第i个节点的更新会更新i的父节点，i父节点的更新又会更新i父节点的父节点。

将节点编号i写成二进制可以发现：
所有1结尾的父节点都是i+1，
所有10结尾的父节点都是i+2，
所有100结尾的父节点都是i+4，
...
即i的二进制中以k个0结尾的节点的父节点是i+2^k，
而2^k可以用补码和位运算 `i&(-i)` 算出。
```
public void update(int i, int val) {
    int delta = val - arr[i];
    arr[i] = val;
    i++; //树状数组以1号元素开头
    while(i < length) {
        tree[i] += delta;
        i += (i & (-i)); //指向父节点
    }
}
```
**3，区间查询**

在此之前，先看一下每个节点的 “管理范围” 与其二进制索引号的关系：
所有1结尾的节点包含的数据的个数为1（只有他自己的数据），
所有10结尾的节点包含的数据的个数为2（从他向前两个数据的和），
所有100结尾的节点包含的数据的个数为4（从他向前四个数据的和），
...
即i的二进制中以k个0结尾的节点包含从这个节点的索引号开始向前2^k个数据的和，
而2^k就是 `i&(-i)` 算出。

因此，计算区间和，就是从右侧边界的节点开始向左求和，每次向左移动 `i&(-i)`（因为这中间的数据在当前节点的范围内，已经求过了），直到移动到左边界的左边。

但是很多时候，不能正好移动到左边界上，会计算一些超出范围的数据。
如10个元素中查询第7，8，9元素的和的时候，实际上是计算了9，8两节点的和，包含了从1-9的所有元素的和。

还要减去多求的数据，即减去 从“上一步中求和的最左位置”到“区间左边界”的和。
但这一步不会出现多算的问题了，因为这些计算都在较低的层中，最后会正好落到上一步中的最左位置上。
如10个中查7，8，9。第一步中计算的最左侧是0（节点号8减去8），从6开始计算第1-6元素的和，计算了节点6，4的和，最后刚好落到0（节点4减去4）。
```
public int sumRange(int i, int j) {
    j++;
    int sum = 0;
    int nextj = j;
    //第一次求和
    while(j > 0) {
        sum += tree[j];
        nextj = j - (j & (-j));
        if(nextj < i) {
            //已经超出区间左侧了
            break;
        }
        j = nextj;
    }
    //nextj和i之间就是刚才多算了的东西
    while(i > nextj) {
        sum -= tree[i];
        i -= (i & (-i));
    }
    return sum;
}
```
