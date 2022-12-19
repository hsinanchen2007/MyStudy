只有第一次达到0ms，其他都是4|8ms
### 解题思路
- 先让两个字符串等长，在短的字符串前补零，避免操作溢出。这样就能用一个指针操作两个字符串了。
- 从后往前扫描字符串，利用ACII码与'0'的差值做加法，并加上进位（初始值为0）。结果只有4种可能：0，1，2，3。
    - '0'、'1'时，无进位，进位值置0
    - '2'、'3'时，有进位，进位值置1，再将字符串的当前位置'0'或置'1'，'2'->'0','3'->'1'
- 扫描完成后，最后一次计算可能产生进位，有进位则在字符串开头加个"1"。

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;//代表进位
        int asize = a.size(),bsize=b.size();
        //统一两个字符串的长度
        while(asize<bsize) {a = "0" + a;asize+=1;}
        while(bsize<asize) {b = "0" + b;bsize+=1;}
        //扫描
        for(int i=a.size()-1;i>=0;--i){
            a[i]+=b[i]-'0'+carry;
            if(a[i]<'2') {//结果为0、1
                carry=0;
                continue;
            }
            carry=1;//结果为2、3
            if(a[i]=='2'){
                a[i]='0';continue;
            }
            if(a[i]=='3'){
                a[i]='1';continue;
            }
        }
        if(carry) return "1"+a;//有进位时加个开头"1"
        return a;
    }
};
```