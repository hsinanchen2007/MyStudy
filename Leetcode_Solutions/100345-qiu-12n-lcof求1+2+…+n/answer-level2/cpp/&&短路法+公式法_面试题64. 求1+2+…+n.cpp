### 解题思路一 &&短路法
    /*
     * 方法1 && 短路法
     *
     * && 的短路特性是——
     * A && B :
     * 当A为true时，返回表达式B的bool值；
     * 当A为false，返回false。
     * */
### 代码

```cpp
int Solution64::sumNums(int n) {
    // 构造A && B
    // A : n > 0是终止条件
    // B : (n += sumNums(n-1) > 0)是计算式子
    n > 0 && ((n += sumNums(n-1)) > 0);

    return n;
}
```

### 解题思路二 公式法
    /*
     * 方法2 公式法
     *
     * 计算公式：
     * 1+2+...+(n-1)+n = ((n+1)n)/2 = (pow(n,2)+n)>>1
     *
     * 此处使用右移代替除法，使用求幂函数代替乘法。
     * */
### 代码

```cpp
int Solution64::sumNums2(int n) {
    return ((int)(std::pow(n, 2)+n))>>1;
}
```

### 解题思路三 构造函数法
    /*
     * 方法3 构造函数法
     *
     * 创建一个类的n个实例，该类的构造函数将会被调用n次，
     * 在构造函数中对全局静态变量n和sum进行累加
     * */
### 代码

```cpp
// 对全局静态变量初始化
int Solution64::n = 0;
int Solution64::sum = 0;

Solution64::Solution64() {
    // 没调用一次对n加1
    ++n;

    // 没调用一次对sum加n
    sum += n;
}

void Solution64::reset() {
    n=0;
    sum=0;
}

int Solution64::getSum() {
    return sum;
}

int Solution64::sumNums3(int n) {
    Solution64::reset();

    // 创建n个类对象，
    // 构造函数调用n次
    auto* s = new Solution64[n];

    // 释放n个对象的空间
    delete []s;
    // 将对象指针设为null
    s = nullptr;

    return getSum();
}
```

### 解题思路四 函数指针法
    /*
     * 方法4 函数指针法
     *
     * 使用函数返回0作为终止条件，
     * 定义函数指针，该函数指针数组指向函数terminator和sumNums3，
     * 当f[!!n]中的(!!n)为0时指向terminator，为1时指向sumNums3。
     *
     * 1. 当n>0时,(!!n)为1，此时sumNums3函数递归计算：n+(n-1)+(n-2)+...+1；
     * 2. 当n=0时,(!!n)为0，此时terminator函数返回0，运算结束。
     *
     * 此处f[!!n]这样使用的原因是，函数指针数组包含两个函数指针，
     * 而要判断n为0时指向terminator，即f[0]，所以将其中的n转化为bool值(!!n)。
     * */
### 代码

```cpp
int Solution64::sumNums4(int n) {
    // 函数指针数组
    static fun f[2] = {terminator, sumNums4};

    // 1. n > 0时，f[!!n] = f[1] = sunNums3,
    // 此时计算: n+(n-1)+(n-2)+...+1
    // 2. n = 0时，f[!!n] = f[0] = terminator
    // 此时返回0，计算终止
    return n + f[!!n](n-1);
}

int Solution64::terminator(int n) {
    return 0;
}
```

### 解题思路四 函数指针法
    /*
    * 方法5 模板类型法
    *
    * 使用模板类型的方法，递归计算：N = n+(n-1)+...+1
    * 当递归到参数为1的类型时，递归结束。
    *
    * 由于此过程是在编译过程中完成的，因此需要n为确定的常量。
    * */
### 代码

```cpp
template <int n> struct sumNums5{
    enum VALUE{N=sumNums5<n-1>::N+n};
};

// 终止类型
template <> struct sumNums5<1>{
    enum VALUE{N=1};
};
```