![捕获.JPG](https://pic.leetcode-cn.com/b84fd3e578d7dba2dd642942730091cc91456ff44fd1f788c6d494b66a8710fe-%E6%8D%95%E8%8E%B7.JPG)

第一种：转换为字符串，检测是否存在特定字符串
既然是交替0和1，那必然不存在“00”和“11”这种字符串。
```
    String binaryStr = Integer.toBinaryString(n);
    return !(binaryStr.contains("00") || binaryStr.contains("11"));
```
第二种：传统的进制转换算法
    把十进制正整数转为二进制，只要任意相邻两位不相同就行
```
    do {
        int last=n%2;
        n/=2;
        if (last==n%2){
            return false;
        }
    }while (n>0);
    return true;
```

