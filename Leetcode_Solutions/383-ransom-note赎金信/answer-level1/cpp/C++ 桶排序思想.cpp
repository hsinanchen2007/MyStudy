### 解题思路
菜鸡解法：
1.  前面两个for循环：将两个数组的小写字母 a~z 分别放到数组的 0~26 里
2.  第三个for循环比较数组的数字：
        若第一个数组的数字小于或等于第二个数组相应的数字，
        则符合题意。

（12ms, 97.86%;     11MB, 27.36%）

### 代码

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.length()==0 && ransomNote.length()==0) return true;
        if(magazine.length()==0) return false;
        
        int ransomArr[26] = {0}, magaArr[26] = {0};
        for(int i = 0; i < ransomNote.length(); i++)
            ransomArr[ransomNote[i]-97]++;
        
        for(int i = 0; i < magazine.length(); i++)
            magaArr[magazine[i]-97]++;

        for(int i = 0; i < 26; i++)
            if(ransomArr[i]>magaArr[i]) return false;

        return true;
    }
};
```