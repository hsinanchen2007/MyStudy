

最初想法0：求和看能不能三等分，有可能三等分，就按顺序去找三段，能找到三个子数组就true，找不到就false。
缺点：想麻烦了，已经确定总和是sumA了，找到两组，剩下一组只要不是空的，就肯定是可以的了。
我的其他想法：
法1：可以一个指针l正着找第一组，另一个指针r从尾端倒着找第二组，给第二组留至少一个元素就true；
法2：找第一组，找到了，继续找第二组，找到了，看当前mark不是在A外面（<A.size()）就行。

```
class Solution { //法2
private: int mark = 0;
public:
    bool canThreePartsEqualSum(vector<int>& A) {
         if( A.empty() ){ return false; }
         int sumA = 0; // 数组所有数字总和
         for( int i = 0; i < A.size(); i++ ){ sumA += A[i]; }
         if( sumA%3 != 0 ){ return false; } // 能三等分，意味着sumA是3的倍数
         int part = sumA/3; // 每一段的和是sumA/3
         // 只要能找到三段连续数字和=sumA/3则返回true，若不能则返回false。
         bool one = match( A, mark, part ); // 若第1组就不成，或者直接到尾，则不行
         if( !one || mark == A.size() ){ return false; }
         bool two = match( A, mark, part ); // 若第2组就不成，或者直接到尾，则不行
         if( !two || mark == A.size() ){ return false; }
         return true;  
    }
    bool match( vector<int>&vec,int start, int sum ){
        int temp = 0; // 记录当前和
        for( int j = start; j < vec.size(); j++ ){ 
             temp += vec[j];
             if( temp == sum ){
                 mark = j+1;// 下一段的起点
                 return true;                
             }
        }
        return false;
    }
};
```
反馈：
想法0：执行用时 :56 ms, 在所有 C++ 提交中击败了79.45%的用户。内存消耗 :31.6 MB, 在所有 C++ 提交中击败了5.26%的用户。
改进1：执行用时 :72 ms, 在所有 C++ 提交中击败了28.67%的用户。内存消耗 :32 MB, 在所有 C++ 提交中击败了5.26%的用户。
改进2：执行用时 :44 ms, 在所有 C++ 提交中击败了99.14%的用户。内存消耗 :32 MB, 在所有 C++ 提交中击败了5.26%的用户。