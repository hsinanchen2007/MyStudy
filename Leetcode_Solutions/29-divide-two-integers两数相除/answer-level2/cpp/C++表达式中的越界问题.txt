最近在刷二分题目的时候踩了好多越界的坑，比如LeetCode #69 X的平方跟，我在这里用二分查找时用的是右中位点
int mid=left+(right-left+1)/2,
我二分查找的范围为[0,x],初始时left=0，right=x，有一个测试用例是x=2147483647(INT_MAX)，这时候
right-left+1=x-0+1=INT_MAX+1,直接runtimeerror了，当时取了个巧把(right-left+1)/2改成了
(right-left-1+2)/2即(right-left-1)/2+1;这样保证了编译器开的int临时变量不会被越界。

leetcode #29 两数相乘这道题，我又跳了一次坑，这次我服了ORZ。下面代码加注释部分我单独拿出来分析一下，res+=1<<weight;其中res为long long型用来存商，weight代表商二进制中每位1的权值1×2^(weight)，那么坑挖好了，我准备跳了，最后一个测试用例(-2147483648，-1),这时weight=31，我期待的结果是
res+=1×2^31即res+=INT_MAX，但是编译器却说不你不想，给了我个res+=INT_MIN;总结发现，我之前一直以为在一个表达式中只要有一个较高类型，其他变量类型都会自动提升到这个类型，包括编译器中间开的临时变量，但是事实是，编译器会根据表达式计算优先级的顺序提升和开辟临时变量的类型，比如还是
res+=1<<weight这个表达式，虽然res是long long型，但是这个表达式会先计算1<<weight，编译器会开辟一个int临时变量来存储这个结果，1<<31正好是int的最小值INT_MIN，临时变量再和res计算时，进行类型提升结果还是INT_MIN，最后的res当然就是INT_MIN而不是我想要的INT_MAX,这里我又用了一个奇技淫巧
res+=lLL<<weight，强制声明数字1为long long类型，或者把weight声明成long long。力友们有没什么好的编程范式规避这些琐碎细节呢，我每次都比较纠结这种细节ORZ。。。

```
typedef long long ll;
class Solution {
public:
    int divide(int dividend, int divisor) {//左移、右移相当于二分
        int sign=(dividend>=0)^(divisor>=0);
        int weight=0;
        ll tmp_dividend=llabs(dividend),tmp_divisor=llabs(divisor),init_divisor=llabs(divisor);
        while(tmp_divisor<=tmp_dividend){
            tmp_divisor<<=1;
            weight++;
        }
        ll res=0;
        while(init_divisor<=tmp_dividend){
            tmp_divisor>>=1;
            weight--;
            if(tmp_divisor>tmp_dividend) continue;
            res+=1LL<<weight;//最后一个测试用例通不过的坑。
            tmp_dividend-=tmp_divisor;
        }
        if(sign) return -res;
        return res<INT_MAX?res:INT_MAX;
    }
};
```
