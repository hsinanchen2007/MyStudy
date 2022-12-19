# 看到这题首先想到了动态规划，不过需要做一些优化，否则会超时，代码看起来比较复杂，逻辑还算简单
# 基本思路：
1.首先对题解空间N(n)进行分解，可根据root节点值为1~n将解空间分解为n个子解空间，N1(N),N2(n),N3(n)...,Nn(n),所有子解空间的解个数加起来就是总的解
2.对于root节点为i的子解空间，包括两个部分，一个是 N(i-1)(左子树)，一个是N(n-i)(右子树)，转发为子问题采用递归的方法求解
3.写完提交发现超时了， 分析了下发现有一些重复求值的冗余过程，优化了下代码，添加了一个数组记录已求出来的解，如果判断发现解已经求出来了，直接取值，不再重复求解
# 代码如下：
```
int numTreesDown(int n,  int* nums){
    if(n == 0 | n ==1 ) {
        nums[n] = 1;
        return 1;
    }
    int numTree = 0;
    for(int i = 1; i < n + 1; i++) { 
        int tmp = 0;
        int leftTreeNum;
        int rightTreeNum;
        if(nums[i-1] == -1) { 
            leftTreeNum = numTreesDown(i - 1, nums);
            nums[i-1] = leftTreeNum; 
        } else {
            leftTreeNum = nums[i-1];
        }
        if(nums[n-i] == -1) {
            rightTreeNum = numTreesDown(n - i, nums);
            nums[n-i] = rightTreeNum; 
        } else {
            rightTreeNum = nums[n-i];
        }
        tmp = leftTreeNum * rightTreeNum;
        numTree = tmp + numTree;
    }
    return numTree;
}
int numTrees(int n) {
    int* nums = (int*)malloc(sizeof(int) * (n+1));//添加一个树组记录numtrees（n）
    for(int i = 0; i < n+1; i++) {
        nums[i] = -1;
    }
    int ret = numTreesDown(n, nums);
    free(nums);
    return ret;
}
```
