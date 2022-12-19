### 解题思路
递归解法

### 代码

```cpp
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        move(A.size(),A,B,C);
    }
    //将n个盘从A移动到C,  B作为缓冲盘
    void move(int n,vector<int>& A, vector<int>& B, vector<int>& C){
        if(n==1){
            moveone(A,C);
        }
        else{
            move(n-1,A,C,B);
            moveone(A,C);
            move(n-1,B,A,C);
        }
    }
    //将1个盘从A到C
    void moveone(vector<int>& A,vector<int>& C){
        int temp=A[A.size()-1];
        cout<<temp<<endl;
        A.pop_back();
        C.push_back(temp);
    }

};
```