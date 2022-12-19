利用&&运算符左边为false时跳过右边的特性跳出递归

```

public:
    int sumNums(int n) {
        n && (n+=sumNums(n-1));
        return n;
    }
};
```

![QQ截图20200320102442.png](https://pic.leetcode-cn.com/8750dc304fecf32a5619e928d2ed05b7a5f4a45a2ccf459933e2840b3d30a6ec-QQ%E6%88%AA%E5%9B%BE20200320102442.png)

我去看了那38.23%是什么代码，发现人家是在构造函数里判断是否为0，话说不是不让if吗
