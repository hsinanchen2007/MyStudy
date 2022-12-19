### 解题思路
此处撰写解题思路

初始化首尾两个指针，当两个指针分别指向字符时，交换两个指针的内容

### 代码

```cpp
class Solution {
public:
    string reverseOnlyLetters(string S) {
        if (S.size()<=1){
            return S;
        }
        int len=S.size();
        int left=0;
        int right=len-1;
        char tmp;

        while (left<right){
            
            while ((S[left]>=33 && S[left]<=64) || (S[left]>=91 && S[left]<=96) && left<right){
                left++;
            }
            while ((S[right]>=33 && S[right]<=64) || (S[right]>=91 && S[right]<=96) && left<right){
                right--;
            }
            if (left<right){
                tmp=S[left];
                S[left]=S[right];
                S[right]=tmp;
                left++;
                right--;
            }
        }
        
        return S;
    }
};
```