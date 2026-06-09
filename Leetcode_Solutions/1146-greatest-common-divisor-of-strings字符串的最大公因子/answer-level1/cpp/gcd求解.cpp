### 解题思路
思路：虽然是两个字符串，但它同样可以抽象成是数字的整除，只不过多了字符串的判断
我们先得到这两个字符串的长度n1, n2  
然后求出gcd(n1,n2)的最小公约数的所有约数，那么如果有解必然是约数里的某个
否则就是无解

然后从大到小枚举每个绝数

### 代码

```cpp
class Solution {
public:
    int gcd(int a, int b){
        while(b != 0){
            a %= b;
            swap(a , b);
        }
        return a;
    }

    bool judge(const string& s1 , const string& s2 , int d){
        for(int i = 0; i < d; ++i){
            if(s1[i] != s2[i])
                return false;
        }
        int i = d , j = d;
        int n1 = s1.size() , n2 = s2.size();
        for(; i < n1 || j < n2;){
            if(i < n1){
                if(s1[i] != s1[i - d])
                    return false;
                ++i;
            }
            if(j < n2){
                if(s2[j] != s2[j - d])
                    return false;
                ++j;
            }
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int n1 = (int)str1.length() , n2 = (int)str2.length();
        int d = gcd(n1 , n2);
        vector<int> v;
        v.push_back(d);v.push_back(1);
        for(int i = 2; i <= d / i; ++i){
            if(d % i == 0){
                v.push_back(i);
                if(i != d / i)
                    v.push_back(d / i);
            }
        }
        sort(v.begin() , v.end());
        reverse(v.begin() , v.end());
        for(const int & i : v){
            if(judge(str1 , str2 , i))
                return str1.substr(0 , i);
        }
        return "";
    }
};
```