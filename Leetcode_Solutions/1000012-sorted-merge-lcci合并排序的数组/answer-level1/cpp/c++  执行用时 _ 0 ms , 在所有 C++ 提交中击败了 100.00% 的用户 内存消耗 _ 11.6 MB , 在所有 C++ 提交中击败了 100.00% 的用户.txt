### 解题思路
基于3个指针的思路：
开始时，设立一个size指针指向A容器的末尾，另外两个指针，a、b分别指向A、B最后一个非零的有效的元素，即a=m，b=n
每次选取a、b指针指向的最大的元素，放在size指针所指的位置。用到的指针减一。
最终一定a、b指针总会有一个指针的值会等于0，
如果b还大于零，就把b剩余的元素移到a中；
如果a还大于零，就不管了，已经排好了。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int size;
        int a=m;
        int b=n;
        for(size=m+n;size>0&&b>0&&a>0;size--){
            if(B[b-1]>=A[a-1]){
                A[size-1]=B[b-1];
                b--;
            }else{
                A[size-1]=A[a-1];
                a--;
            }
        }
        if(a<=0&&b>0){
            while(size>0){
                A[size-1]=B[b-1];
                b--;
                size--;
            }
            
        }

    }
};
```