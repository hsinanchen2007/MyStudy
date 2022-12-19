### 解题思路
不会KMP算法，同时感觉暴力法不太美好
学了一个新的算法：Rabin Karp
算法大致思路：通过用Hash function 计算字符串的hash值（其实就是一个整数）
   1.首先计算目标字符串的hash值（相当于转换为一个整数）；
   2.然后以同样的方法计算原字符串的hash值，通过逐个字符计算然后累加的方法；
   3.当达到与目标字符串个数相等时，与目标字符串计算的hash值相比较；
   4.如果相等的话，这时还需要再次确认字符串是否匹配，因为hash function并不能保证不同字符计算出来的hash值不相等；
hash function：例如：“abc”
hash=a×31的2次方+b×31的1次方+c×31的0次方;(31是hash function中一个比较常用的底数值)
   计算目标字符串直接计算就可以了，原字符串的话，因为需要每次计算的子字符串长度与目标字符串相等，所以涉及对计算hash值的减法，直接：haystackCode-(haystack.charAt(i-m)*power)，然后再对10的6次方取余即可，代码中的power其实就是先计算出每次需要进行减法时需要减去的乘数部分。
复杂度：O(n)
如果直接暴力的话，肯定需要两个for循环
### 代码

```java
class Solution {
    public int BASE=1000000;
    public int strStr(String haystack, String needle) {
        if(haystack==null||needle==null){
            return -1;
        }
        int n=haystack.length();
        int m=needle.length();
        if(m==0){
            return 0;
        }
        int power=1;
        for(int i=0;i<m;i++){
            power=(power*31)%BASE;
        }

        int needleCode=0;
        for(int i=0;i<m;i++){
            needleCode=(needleCode*31+needle.charAt(i))%BASE;
        }

        int haystackCode=0;
        for(int i=0;i<n;i++){
            haystackCode=(haystackCode*31+haystack.charAt(i))%BASE;

            if(i<m-1){
                continue;
            }
            if(i>m-1){
                haystackCode=haystackCode-(haystack.charAt(i-m)*power)%BASE;
                if(haystackCode<0){
                    haystackCode+=BASE;
                }
            }

            if(haystackCode==needleCode){
                if(haystack.substring(i-m+1,i+1).equals(needle)){
                    return i-m+1;
                }
            }
        }
        return -1;
    }
}
```