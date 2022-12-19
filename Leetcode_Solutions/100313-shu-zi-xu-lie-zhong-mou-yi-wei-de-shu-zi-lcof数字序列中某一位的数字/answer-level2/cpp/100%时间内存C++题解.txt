### 解题思路
很显然数字序列是有规律的，假设我们要找数字n在数字序列中出现的位置：
* 如果n的数位为1，由于每一个数字如：1，2，3 ...只占据了一个位置，因此返回的数字就是n。且数位为1的数字一共有10个
* 如果n的位数为2，每一个数字如：11，21，30 ...占据两个位置.我们以n=23为例子，由于0到9都占有一位，因此处于两位的位置的有23-10=13个，
  用13/2=6...1，说明从10开始有6个两位数，余数为1说明对应的因该是第7个两位数的第0个位置（从0开始表示第一位）。
* 如果n为位数为bits，则我们可以从bits=1开始往后寻找n应该是属于几个数位的区间，如果不属于这个数位区间，我们需要跳过该区间的所有数字，
  计算结果在getCount（）里面，即n=n-getCount（bits）。如果找到属于该bits的空间之后，我们用n/bits得到商number和余数left，用商number加上该
  数位开始的第一个数得到indexNum，在indexNum中对应的left-1位就是最后的结果。
  

### 代码

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        if(n==0) return 0;
        int bits=1;
        while(true){
            long count=getCount(bits);
            if(n<count) return getIndex(n,bits);
            n-=count;
            ++bits;
        }
        return 0;
    }

    long getCount(int bits){
        if(bits==1) return 10;
        long count=pow(10,bits-1);
        return 9*count*bits;
    }

    int getIndex(int index,int bits){
        if(bits==1) return index;
        int number=index/bits;
        int left=index%bits;
        int begOfThisBites=pow(10,bits-1);
        int indexNum=number+begOfThisBites;
        stack<int> S;
        while(indexNum!=0){
            S.push(indexNum%10);
            indexNum/=10;
        }
        for(int i=0;i<left;++i){
            S.pop();
        }
        return S.top();
    }
};
```