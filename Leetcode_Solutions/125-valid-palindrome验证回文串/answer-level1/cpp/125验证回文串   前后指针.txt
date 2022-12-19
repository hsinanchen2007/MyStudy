### 解题思路
前后指针
while（左<右）{
     while（到目标点(跳过不要的点)&&l左《右边）{
}
if（比较）
左++；右++
}
只考虑字母和数字字符  想到可以，内部while跳过非这个条件的点 到目标点

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            while(!isalnum(s[left])&&left<right){
                left++;
            }
            while(!isalnum(s[right])&&left<right){
                right--;
            }
                //跳过非数字字母则用内部whhile
            if(toupper(s[left])!=toupper(s[right])){
                return false;
            }//正常的双指针操作
            left++;
            right--;
        }
        return true;
    }
};
```