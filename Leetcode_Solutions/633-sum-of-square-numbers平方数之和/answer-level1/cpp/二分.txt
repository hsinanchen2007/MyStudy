### 解题思路
此处撰写解题思路
由a2+b2=c可知 a或b的范围在0-根号c 
在利用双指针 二分查找
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户内存消耗 :8.1 MB, 在所有 C++ 提交中击败了28.77%的用户
### 代码

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        long n=sqrt((double)c);
        long  i=0,j=n,sum;
        while(i<=j){
            sum=i*i+j*j;
            if(sum==c) return true;
            else if(sum>c) j--;
            else i++;
        }
        return false;
    }
};
```