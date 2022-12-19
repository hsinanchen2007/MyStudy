### 解题思路
没有选择sort函数的方式，本解答的亮点（智障点）在于完全使用if-else区分各种情况。有三个注意点：
1、 A初始0个元素
2、 区分碰到的数是数组内的元素0还是用来给B占位的元素0
3、 区分B的单个元素是小于A的当前元素还是大与等于
以下是智障代码：

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int j=0;
        int temp=0;
        for(int i=0;i<n;i++){
            for(;j< m+n;j++){
                if(A[j]==0 && m==0 ){
                    A[j]=B[i];
                    j++;
                    break;
                }
                else if(A[j+1]==0 &&(j == i + m - 1)){
                    if(A[j]<=B[i])
                        A[j+1]=B[i];
                    else{    
                        A[j+1]=A[j];
                        A[j]=B[i];
                    }
                    if( j != m+n-2)
                        j=0;
                    break;
                }
                else if(A[j]>B[i]){
                    temp = A[j];
                    A[j]=B[i];
                    B[i]=temp;
                    i--;
                    j++;
                    break;
                }   
                else if(A[j]<=B[i]&&A[j+1]>B[i]){
                    temp = A[j+1];
                    A[j+1]=B[i];
                    B[i]=temp;
                    i--;
                    j++;
                    break;
                }
            }
        }
    }
};
```