以下乘号用\times表示。
但是如果对应的话，A在最高位的时候像1，但不在最高位的时候又有点像0.
一位，A-Z,26个。
二位，AA-ZZ,26\times26个。
形式上第一个三位数AAA实际上是26+26\times26+1，跟n进制的n^2不同。
然而这个超出进制的现象仅仅在最高的首位才会出现，且仅仅是与位数有关但与该位的值无关的偏移，一旦它不是最高位，在叠加的时候又相当于普通的26进制。
给出CCCCC
那么按照前面的解释可以认为
最高的首位C代表3\times26\times26\times26\times26+(26\times26\times26+26\times26+26+1)
后面代表的数减一但进制照常。
第二位的C看作2\times26\times26\times26
第三位的C看作2\times26\times26
第四位的C看作2\times26
第五位的C看作2\times1
最高位的超出进制部分实际上可以跟后面几位合并起来，也就不需要把后面几位减一了。

**也就是说，仍然可以看作26进制，A就视作1，B就视作2......Z是把本该进位的数写成了不进位的假形式。**

也就是说ZA=26\times26+1其实就是真正的三位数假写成两位。


```
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n){
            int b=n%26;n/=26;
            char c=b+'A'-1;
            if(b==0){
                c='Z';
                n--;
            }
            ans=c+ans;
        }
        return ans;
    }
};

```
