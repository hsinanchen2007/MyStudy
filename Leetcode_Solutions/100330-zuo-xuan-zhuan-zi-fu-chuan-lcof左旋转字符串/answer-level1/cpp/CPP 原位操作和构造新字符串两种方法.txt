### 解题思路
两种方法, 耗时与耗内存要有取舍
![image.png](https://pic.leetcode-cn.com/5d385a845c1d8efd770037bdb93a8e42dd30b35715358345d8b7756d4b370996-image.png)

### 代码

#### 1. 原位操作, 内存占用比较少,但耗时长

![image.png](https://pic.leetcode-cn.com/064c9e997f0fd8629c03ebdc18b1b07e963cbfd7b872ba888f1899b8d9047c02-image.png)

```cpp
string reverseLeftWords(string s, int n) {
    for(int i = 0; i < n; ++i){
        s.push_back( *s.begin( ) );
        s.erase( s.begin( ) );
    }
    return s;
}
```

#### 2. 构造一个新的字符串, 用时短, 但消耗内存多

![image.png](https://pic.leetcode-cn.com/af51d4731c705dc4d0985e1ef1c8625bb40a53cd3108013f010bf0b0784b2eda-image.png)

```cpp
string reverseLeftWords(string s, int n) {
    string ret( s.cbegin( ) + n, s.cend( ) );
    ret += string( s.cbegin( ), s.cbegin( ) + n );
    return ret;
 }

```