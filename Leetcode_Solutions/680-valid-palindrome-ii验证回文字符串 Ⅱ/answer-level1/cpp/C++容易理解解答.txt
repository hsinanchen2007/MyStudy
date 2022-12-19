### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool validPalindrome(string s) {
        int left=0,right=s.size()-1;//,count=0;
        //bool flag = false;
        while(left<right){
            if(s[left]==s[right]){
                left++;right--;
            }else{
                break;
            }
        }
        //怎么让程序做出正确的选择？用选择结构，让程序走完两条路。
        if(left>=right) return true;
        int i = left, j = right;
        if(s[i] == s[j-1]){
            j--;
            while(i<j){
                if(s[i]==s[j]){
                i++;j--;
                }else{
                    break;
                }
            }
            if(i>=j)
             return true;
             i = left; j = right;
        }
        if(s[i+1] == s[j]){
            i++;
            while(i<j){
                if(s[i]==s[j]){
                i++;j--;
                }else{
                    break;
                }
            }
            if(i>=j) 
            return true;
        }
        return false;
    }
};
```