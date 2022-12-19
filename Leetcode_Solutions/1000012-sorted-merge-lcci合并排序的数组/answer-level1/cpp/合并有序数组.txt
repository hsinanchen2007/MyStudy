### 解题思路
双指针从后往前分别比较两个数组的指针所指的元素，放到数组A的末尾

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int index1=m-1;
        int index2=n-1;

        for(int i=m+n-1;i>=0;--i){
            if(index2<0){//第二个数组赋值完毕，第一个数组的前半部分不需要动
                break;
            }
            else{//第一个数组和第二个数组取大的放到数组A的末尾
                if(index1>=0&&A[index1]>B[index2]){//注意区分出第一个数组取完的特例
                    A[i]=A[index1];
                    --index1;
                }
                else{//第
                    A[i]=B[index2];
                    --index2;
                }                
            }
        }
    }
};
```