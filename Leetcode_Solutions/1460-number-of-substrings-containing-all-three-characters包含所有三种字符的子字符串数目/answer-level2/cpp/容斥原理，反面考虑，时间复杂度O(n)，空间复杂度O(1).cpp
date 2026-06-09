因为本题只有3种字符，我们可以反面考虑问题，考虑只含'a','b'和'a','c'以及'b','c'这三种情况的子字符串（当然，还有只有只含'a','b','c'单个元素的子字符串的情况）。如果能把上面三种情况的子字符串求出，再利用总的子字符串的总数减去，就可以得到含'a','b','c'字符串的数目了。

首先，一个长度为n的字符串所包含的所有子字符串个数（含自身，不含空串）为：
$$
getTotal(n) = n + n-1 + n-2 + ... + 1 = \frac{(n+1)*n}{2}
$$

来看看只含有特定的两个字符的子字符串好不好求？
其实是比较好求的，只需要遍历一遍字符串，边遍历边记录只含有两种特定字符串的中间子字符串长度c，再利用一个长度为c的字符串的子串公式可以求得每次中间那些只含特定两个字符的子串，把所有这样的加起来，即得到了子串的个数。但是，需要注意的是，上面这种情况也包含了只含有单个字符的情况，所以最后再减去的时候，需要加回来。

最后的结果为：s()表示只含特定字符的子字符串的总个数。
$$
ans = getTotal(n) - s(a,b) - s(a,c) - s(b,c) + s(a) + s(b) + s(c)
$$

```c++
typedef long long LL;
class Solution {
public:
    long long getTotal(int n){
        return (long long)((n+1))*n/2;
    }

    //获得单个字符的子字符串个数
    LL getOnly(char a,string& s){
        LL ans = 0;
        int c = 0;
        if(s[0] == a) c = 1;
        
        for(int i=1;i<s.length();++i){
            if( (s[i] == s[i-1] && s[i] == a) || s[i] == a ){
                c++;
            }
            else{
                if(c) ans += getTotal(c);
                c = 0;
                
            }
        }
        if(c) ans += getTotal(c);
        return ans;
    }
    //获取特定两个字符子串的个数
    LL getTwo(char a,char b,string& s){
        int c = 0;
        LL ans = 0;
        if(s[0] == a || s[0] == b) c = 1;
        for(int i=1;i<s.length();++i){
            if(s[i] == a || s[i] == b){
                c++;
            }
            else{
                if(c) ans += getTotal(c);
                c = 0;
            }
        }
        if(c) ans += getTotal(c);
        return ans;
    }
    int numberOfSubstrings(string s) {

        //子字符串的总数
        LL total = getTotal(s.length());
        
        LL a = getOnly('a',s);
        LL b = getOnly('b',s);
        LL c = getOnly('c',s);
        
        LL ab = getTwo('a','b',s);
        LL ac = getTwo('a','c',s);
        LL bc = getTwo('b','c',s);
        
        //容斥原理得到最后结果
        return total+(a+b+c)-ab-ac-bc;
        
    }
};

```
算法只需要分别进行6次遍历，时间复杂度为O(n)。空间复杂度的话，只需要用到常数个变量，所以为O(1).