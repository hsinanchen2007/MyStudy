```
class Solution {
public:
    void moveHanota(int n,vector<int>& A, vector<int>& B, vector<int>& C)
    {
        //A->C,B is temp tower
        if(n>0)
        {
            moveHanota(n-1,A,C,B);
            int num=A[A.size()-1];
            A.pop_back();
            C.push_back(num);
            moveHanota(n-1,B,A,C);
        }
    }
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        moveHanota(A.size(),A,B,C);
    }
};
```
个人的一点小思考：
目标：A -> C, B作为缓冲塔

移动过程：
1.A -> B,C作为缓冲塔
2.B -> C,A作为缓冲塔

代码思路过程：
1.首先解决递归代码的顺序问题，分析了移动过程后便可以解决；
2.接下来处理移动盘子的代码放在哪里的问题，因为一次性只能处理一个盘子，故必须等到n为1的时候才能进行移动，所以将移动盘子的代码放到两个递归语句之间。