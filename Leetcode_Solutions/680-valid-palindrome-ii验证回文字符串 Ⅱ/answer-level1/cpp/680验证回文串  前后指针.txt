### 解题思路
由于是只允许删掉一个，所以不能用内while来跳过异常点，而应该用条件语句，进入另一个函数判断剩下的
whiel{
if（异常点）
    return  进入另一个函数判断后面的
  左++；右--
}

### 代码

```cpp
class Solution {
public:
    bool is(string s,int left, int right){
        while(left<right){
             if(s[left++]!=s[right--]){
                 return false;
             }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right]){
                 return is(s,left+1,right)||is(s,left,right-1);
            }
            left++;
            right--;
        }
        return true;
    }
};
```