我也不知道这个叫什么方法，不需要奇偶性直接算，执行0ms耗时，8.8m内存，用时和内存消耗均击败100%用户
我发现这几个数字有关系  

当前数字    label  
当前数字所在层数 c  
当前数字的父节点在上一层按照从大到小的顺序排在第几  k  

这三个数字之间的关系是
1. 首先通过label求层数c
通过对数得到  
```c++
int c = (int) (log(label) / log(2) + 1);  //这里通过  +1 避免了 1,2,4,8,16....引起的计算错误
```
2. 通过层数c求上层位置k
这个就比较直观了，由于本层和上层顺序相反，想求上层从大到小位置，就需要先求本层从小到大的位置，然后再整除2(毕竟一棵树只有两个分支)
```c++
int k=(label-pow(2,c-1))/2+1;
```
3. 通过当前层数c和上层顺序k求上层数字label
注意到已经知道了上层数字label在上一层从大到小的位置，那么就可以直接求了
```c++
label = pow(2, c - 1) - k;
```
这样我们就可以通过 当前lable => 当前层数c => 上层位置k => 上层label
之后迭代的时候层数每次减一，k通过当前label和层数c直接算

完整代码
```c++
vector<int> pathInZigZagTreeTmp(int &label, int &c, int &k, vector<int> &result) {
        if (c == 2) {
            result[0] = 1;
            return result;
        }
        label = pow(2, c - 1) - k;
        result[c - 2] = label;
        c -= 1;
        k=(label-pow(2,c-1))/2+1;//在上一层是第几个
        return pathInZigZagTreeTmp(label, c, k, result);
    }

    vector<int> pathInZigZagTree(int label) {
        int c = (int) (log(label) / log(2) + 1);//层数 注意后面的括号必须有，不然取整就不对了
        if (c == 1) { return vector<int>(1, 1); }
        if (c == 2) {
            vector<int> result(2, 1);
            result[1] = label;
            return result;
        }
        int k=(label-pow(2,c-1))/2+1;//在上一层是第几个
        vector<int> result(c, 0);
        result[c - 1] = label;
        pathInZigZagTreeTmp(label, c, k, result);
        return result;
    }
```

