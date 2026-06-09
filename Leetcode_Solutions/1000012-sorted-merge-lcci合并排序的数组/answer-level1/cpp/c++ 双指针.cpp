将A的情况，分为已经可以直接复制和还需要判断后赋值。
```
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int index_b = 0;
        int index_a = 0;
        while(1){
            if(index_b > n-1){
                break;
            }
            if(index_a > m - 1 + index_b){// A自己的，加上B插入的个数，已经可以直接赋值了
                A[index_a] = B[index_b];
                index_a++;
                index_b++;
                continue;
            }
            if(B[index_b] > A[index_a]){// 如果A还没有越界，可以继续比较
                index_a++;
            }else{
                // A[a] >= B[b] 一直找到A中大于等于它的第一个元素，插在它的位置上
                A.insert(A.begin()+index_a, B[index_b]);
                index_b++;
                index_a++;
            }
        }
        while(A.size() > m+n){ // 因为之前的是insert，所以要把末尾多于的0删除
            A.pop_back();
        }
    }
};
```