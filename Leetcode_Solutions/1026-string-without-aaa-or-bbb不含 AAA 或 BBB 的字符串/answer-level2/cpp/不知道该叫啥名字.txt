## 问题描述
给定两个整数 A 和 B，返回任意字符串 S，要求满足：

    1. S 的长度为 A + B，且正好包含 A 个 'a' 字母与 B 个 'b' 字母；
    2. 子串 'aaa' 没有出现在 S 中；
    3. 子串 'bbb' 没有出现在 S 中。
	
![](https://pic.leetcode-cn.com/3626a032e16d48f9886c338051b9558e95bfb84466d270fa0a4ca66218408d91.png)
[不含AAA和BBB的字符串](https://leetcode-cn.com/problems/string-without-aaa-or-bbb/ "不含AAA和BBB的字符串")
## 解决方法

### 无名解法
举例A比B多的情况：

- 先用aab，尽量将A和B相等

- AB相等，用ab补齐

- B为0，A不为零，用a补齐

```cpp
class Solution {
public:
    string res;
    void BgtA(int A,int B){
        while(B>A && A){
            res+="bba";
            B-=2;
            A--;
        }
        while(B && A){
            res+="ba";
            B--;
            A--;
        }
        while(B){
            res+="b";
            B--;
        }
    }
    void AgtB(int A,int B){
        while(A>B && B){
            res+="aab";
            A-=2;
            B--;
        }
        while(B && A){
            res+="ab";
            B--;
            A--;
        }
        while(A){
            res+="a";
            A--;
        }
    }
    string strWithout3a3b(int A, int B) {
        if(B>A){
            BgtA(A,B);
        }else{
            AgtB(A,B);
        }
        return res;
    }
};
```


site：[https://liyiping.cn/](https://liyiping.cn/)