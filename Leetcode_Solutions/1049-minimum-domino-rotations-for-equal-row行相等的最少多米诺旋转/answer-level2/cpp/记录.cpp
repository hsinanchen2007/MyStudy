### 解题思路
思路一：遍历第一次找出A，B分别出现最大次数的元素及其个数，第二遍分别A，B中对应不是自己最大出现元素的地方，检查对面可以是否可以替换。但是在第一此遍历最大频率元素的时候count方法使耗时达到O（n^2），超时。

思路二：学习了官方答案发现：关键在于：如果存在答案A，B其中之一或者都可以被调整为全A[0]或者B[0]， 这样就可以不用因为思路一的缺点而超时

代码来源与官方答案
### 代码

```cpp
class Solution {
    public:
    int check(int x, vector<int>& A, vector<int>& B, int n) {
        
        int rotations_a = 0, rotations_b = 0;
        for (int i = 0; i < n; i++) {
            // rotations coudn't be done
            if (A[i] != x && B[i] != x) return -1;
            // A[i] != x and B[i] == x
            else if (A[i] != x) rotations_a++;
            // A[i] == x and B[i] != x    
            else if (B[i] != x) rotations_b++;
        }
        // min number of rotations to have all
        // elements equal to x in A or B
        return min(rotations_a, rotations_b);
    }

    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int rotations = check(A[0], B, A, n);
        // If one could make all elements in A or B equal to A[0]
        if (rotations != -1 || A[0] == B[0]) return rotations;
        // If one could make all elements in A or B equal to B[0]
        else return check(B[0], B, A, n);
    }
};

```