根据题意只交换字母，找到左边的第一个字母和右边的第一个字母，交换，从两边向中间走。
```
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int left=0,right=S.size()-1;
        while(left<right)
        {
            while(left<right&&!isalpha(S[left])) left++;
             while(left<right&&!isalpha(S[right]))right--;
             swap(S[left],S[right]);
             left++;right--;
        }
        return S;
    }
};
```
