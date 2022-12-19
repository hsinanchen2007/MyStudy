## 哈希表
```cpp
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int lenA=A.size(), lenB=B.size(), diff=0;
            //如果A比较短，开B的哈希表，遍历A
            if(lenA < lenB){
            int countB[100001]={0};
            for(int i=0; i<lenA; i++){
                diff += A[i];
            }
            for(int i=0; i<lenB; i++){
                diff -= B[i];
                countB[B[i]]++;
            }
            diff /= 2;
            for(int i=0; i<lenA; i++){
                int curB = A[i]-diff;
                if(curB>=1 && curB<=100000 && countB[curB]!=0) return {A[i], A[i]-diff};
            }
        }
        else{ //如果B比较短，开A的哈希表，遍历B
            int countA[100001]={0};
            for(int i=0; i<lenA; i++){
                diff += A[i];
                countA[A[i]]++;
            }
            for(int i=0; i<lenB; i++){
                diff -= B[i];
            }
            diff /= 2;
            for(int i=0; i<lenB; i++){
                int curA = B[i]+diff;
                if(curA>=1 && curA<=100000 && countA[curA]!=0) return {B[i]+diff, B[i]};
            }
        }
        return {-1, -1};
    }
};
```