### 解题思路
  因为是需要能够被整除的，因此字符串最长的长度是，str1的长度和str2的长度的最大公因数d。
  d求出来后就好做了，因为字符串的长度是d，并且是能够一个或多个该字符串拼凑成str1和str2。
  因此，就只需要从str1或者str2中截取该字符串，去看能不能拼凑成str1和str2就可以了。

  可能有的人会问，为什么最大公因数就可以了，不需要考虑其他公因数吗？比如6和12，我可以不取6，可以取2或者3啊，实在不行还可以取1呀。
  但是题目要求S = T + T + ... + T。所以你的其他公因数如果满足题目要求的话，那必然是可以组成最大的公因数的。我的理解和表达能力有限，就不多说了，自己多思考一下。

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.length();
        int l2 = str2.length();
        //最大公因数
        int d = gcd(l1 , l2);
        //符合条件的目标字符串
        string r = str1.substr(0 , d);
        //长度为d的字符串是否能够拼凑成str1，如果不能就返回空字符串。
        for(int i = 0 ; i < l1 - d + 1 ; i+=d){
            if(str1.substr(i , d) != r)return "";
        }
        //同理，如果不能拼凑成str2就返回空字符串。
        for(int i = 0 ; i < l2 - d + 1 ; i+=d){
            if(str2.substr(i , d) != r)return "";
        }
        return r;
    }

    int gcd(int x , int y){
        if(y == 0)return x;
        return gcd(y , x % y);
    }
};
```