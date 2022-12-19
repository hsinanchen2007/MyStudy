### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int Hash_A[26]={0};  //存大写字母
        int Hash_a[26]={0};  //存小写字母
        int sumA=0;
        int suma=0;
        int sum=0;
        int flag=0;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]-'A'>=0)&&(s[i]-'A'<=26))
            {
                Hash_A[s[i]-'A']++;
            }
            else
            {
                Hash_a[s[i]-'a']++;
            }
        }
        for(int j=0;j<26;j++)
        {
            if(Hash_A[j]>=2)
            {
                sumA=sumA+Hash_A[j]/2*2;
            }
            if(Hash_a[j]>=2)
            {
                suma=suma+Hash_a[j]/2*2;
            }
            if((Hash_A[j]%2==1)||(Hash_a[j]%2==1))
            {
                flag=1;  //存在落单的最后加个1即可
            }
        }
        sum=suma+sumA;
        sum=sum+flag;
        return sum;
    }
};
```