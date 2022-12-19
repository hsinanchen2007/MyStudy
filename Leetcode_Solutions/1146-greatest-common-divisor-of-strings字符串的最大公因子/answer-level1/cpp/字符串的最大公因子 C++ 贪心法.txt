### 解题思路
暴力法，先设最大的公因子是2个字符串长度较短的一个，然后取余判断能否整除，然后就一个一个的遍历是否相同，如果相同，就输出，如果不相同，则最大公因子减一，重复上面的操作。
如果在遍历中没有输出正确结果，那么表明没有2个字符串之间没有最大公因子，那么输出空串。

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1=str1.size(),len2=str2.size();
        int maxGCD=min(len1,len2),index,i;
        char tmp;
        bool flag;
        while (maxGCD>0){
            flag=false;
            if(len1%maxGCD==0 && len2%maxGCD==0) {
                for(i=0;i<maxGCD;i++) {
                    index=i;//str1的索引
                    tmp=str1[index];//索引处的字符
                    while(tmp-str1[index]==0) {
                        if(maxGCD+index<len1) index+=maxGCD;//每次都加maxGCD
                        else break;
                    }
                    if(tmp-str1[index]!=0) break;//错误，则退出
                    index=i;//str2的索引
                    tmp=str1[index];//索引处的字符（注意这里是str1的索引，这样才能保证2个字符串的公因子是共同的。
                    while(tmp-str2[index]==0) {
                        if(maxGCD+index<len2) index+=maxGCD;//每次都加maxGCD
                        else break;
                    }
                    if(tmp-str2[index]!=0) break;//错误，则退出
                    if(i==maxGCD-1) flag=true;//遍历完且都正确。
                }
            }
            if(flag) return str1.substr(0,maxGCD);//遍历完成且正确，返回从第一个字符开始的maxGCD个字符
            maxGCD--;//减一操作
        }
        return "";//当maxGCD遍历到0，表明没有公因子，那么输出空串
    }
};
```