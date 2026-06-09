### 解题思路
step1.排除串长不等以及串为0的情况
step2.当串相等的时候，串必须含有相同的元素，只要找到y两个相同元素就return true
step3.当串不等的时候，找到A和B第一个不等的位置和第二个不等的位置，在A中交换，如果交换之后和B相等true，b否则false

### 代码

![1.png](https://pic.leetcode-cn.com/fceb7313048390df2f08f07fc943464d9c8419a7a1c40c13c432014b1a30e1dc-1.png)
```cpp
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() !=B.size() || A.size() == 0){
            return false;
        }
        if(A==B)
        {
             string c;
             for(int i=0;i<A.size();i++)
             {
                if(c.find(A[i])==c.npos)
                   c.push_back(A[i]);
                else
                   return true;
             }
            return false;
        }

        int i=0;
        while(A[i] == B[i] && i<A.size()){
            i++;
        }
        int j=i+1;
        while(A[j] == B[j] && j<A.size()){
            j++;
        }
        swap(A[i],A[j]);
        return (A==B) ? true:false;


    }
};
```