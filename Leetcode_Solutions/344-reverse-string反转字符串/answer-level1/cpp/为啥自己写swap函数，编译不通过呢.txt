### 解题思路
前后交换，
while终止条件：
奇数：left = right 
偶数： left<right 

### 代码

```cpp
class Solution {
public:

    // void swap(vector<char>& s,int left,int right){
    //     char temp = s[left];
    //     s[left] = s[right];
    //     s[right] = temp;
    // }
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;

        while(left<right){
            //swap(s,left,right);
            swap(s[left],s[right]);
            left++;
            right--;
        }


    }
};