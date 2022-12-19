### 解题思路
新开一个数组，遍历第一个string，对应位置+1；遍历第二个string，对应位置-1；
最后，若数组元素全是0，返回true,否则返回false;

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int count1=0;
        int count2=0;
        int length1=s.length();
        int length2=t.length();
        if(length1!=length2){
            return false;
        }
        int a[26] = {0};
        for(int i=0;i<length1;i++){
            int h=s[i]-'a';
            a[h]+=1;
        }
        for(int q=0;q<length1;q++){
            int j=t[q]-'a';
            a[j]-=1;
        }
        for(int j=0;j<26;j++){
            if(a[j]!=0){
                return false;
            }
        }
        return true;
        
    }
};
```