### 解题思路
1. 第一遍扫描数组看看A,B有木有重复元素，有的话如果能让A或B全一样那么那个元素肯定就是他，然后就数个数就行谁的小选谁
2. 没重复元素的话，就用两个map数组记录数字出现次数，如果两个map数组个数加起来有等于A.size()的那么肯定就是那个数，返回次数小的就行，不是就返回-1


### 代码

```cpp
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int flag=0;
        for (int i=0;i<A.size();i++){
            if (A[i]==B[i]){
                flag = A[i];
                break;
            }
        }
        if (flag){
            int a=0,b=0;
            for (int i=0;i<A.size();i++){
                if (A[i]==flag && B[i]!=flag)
                    b++;
                else if (A[i]!=flag && B[i]==flag)
                    a++;
                else if (A[i]!=flag && B[i]!=flag)
                    return -1;
            }
            return min(a,b);
        }
        else{
            int a[6]={0},b[6]={0};
            for (int i=0;i<A.size();i++){
                a[A[i]-1]++;
                b[B[i]-1]++;
            }
            for (int i=0;i<6;i++){
                if (a[i]+b[i]==A.size())
                    return min(a[i],b[i]);
            }
            return -1;
        }
    }
};
```