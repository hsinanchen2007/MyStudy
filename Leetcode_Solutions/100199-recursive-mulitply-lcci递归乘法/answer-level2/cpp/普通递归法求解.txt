简单粗暴的想法：A*B分解为A个B累加，首先想到自下而上常规递归，但是会出现栈溢出问题。
```
class Solution {
public:
    int multiply(int A, int B) {
        if(A == 0 || B == 0 ) return 0;
        if(A == 1) return B;        //基条件
        int res = multiply(A-1, B); //中间值 = 递归函数（修改参数）；
        return res + B ;            //返回最终结果，根据中间值及修改后的参数得到 = 基条件的结果 + 父问题结果 +……
       
    }
};
```
换一种打开方式，用由上到下的尾递归，同样栈溢出：
```
class Solution {
public:
    int multiply(int A, int B) {
    if(A == 0 || B == 0) return 0;
        int res = 0;
        return multiply2(A,B,res);
    }
    int multiply2(int A, int B, int res){
        if(A == 0 ) return res;
        res += B;
        return multiply2(A - 1, B , res);
    }
};
```
改进版尾递归，增加判断，用较大的数做累加，减少计算次数，测试通过，```但是如果两个数都很大，难道不应该也会溢出……QAQ？```
```
class Solution {
public:
    int multiply(int A, int B) {
    if(A == 0 || B == 0) return 0;
        int res = 0;                     //中间值初始化
        if(A > B) swap(A,B) ;//似乎第一种递归方法不能进行这一步操作
        return multiply2(A,B,res);       //递归函数（参数，中间值）
    }
    int multiply2(int A, int B, int res){
        if(A == 0 ) return res;          //基条件，退出递归，返回最终结果
        res += B;                        //更新中间值，中间值 = 根据参数与中间值重新计算
        return multiply2(A - 1, B , res);//递归函数（修改参数，中间值）
    }
};
```

![捕获.PNG](https://pic.leetcode-cn.com/579dca769605d19b746614a075ea3b23f227405ceaa559609d00aacb83ed4ca7-%E6%8D%95%E8%8E%B7.PNG)



