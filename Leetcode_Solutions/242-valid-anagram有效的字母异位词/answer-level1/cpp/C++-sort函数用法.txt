### sort函数
Sort函数有三个参数：
第一个是要排序的数组或字符串的起始元素。
第二个是要排序的数组或字符串的末尾元素。
第三个参数是排序的方法，可以是从大到小也可是从小到大（第三个参数可不写，此时默认的排序方法是从小到大排序）。
对于字符串string来说，可以通过s.begin()或s.end()来获取字符串的首位字符

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t?true:false;
    }
};
```

### 执行结果
![微信截图_20200407181943.png](https://pic.leetcode-cn.com/fc43fb9090504e59c71229c5936829f9764a4bf50f2282f49848ee95faa96c6b-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200407181943.png)