### 解题思路
    对A数组和数字K都是  从后往前  处理，记录在res数组中，最后记得翻转。
    注意：没必要去剥离  K的每一位  来与  数组A对应位  进行计算（这样还要添加一个carry变量来记录进位与否）
    PS：不断学习大佬们的思路和代码 ~ ~ ~
### 代码

```cpp
class Solution{
public:
    vector<int> addToArrayForm(vector<int>& A,int K){
        int i = A.size() - 1;
        vector<int> res;
        while(i >= 0 || K > 0){
            if(i >= 0) K += A[i--];
            res.push_back(K % 10);
            K /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

```