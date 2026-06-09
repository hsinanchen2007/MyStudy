# 解法一：equal函数的使用
#### equal算法也是逐一比较两个序列的元素是否相等，只是equal函数的返回值为bool值 true/false，不是返回迭代器值。它有如下两个原型，如果迭代器区间[first1，last1)和迭代器区间[first2， first2+(last1 - first1))上的元素相等（或者满足二元谓词判断条件binary_pred） ，返回true，否则返回false。
```
class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        for(int i=n-1;i>=0;i--){//从长度大的向小的去比较
            if(equal(s.end()-i,s.end(),s.begin())){
                return string(s.end()-i,s.end());
            }
        }
        return "";
    }
};
```

