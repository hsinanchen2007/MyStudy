### 解题思路
代码要点：思路同14-I，但是此题遇到求pow(3,a)时会越界，因此可以循环乘3，每次循环后就取一次模
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :5.7 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3)return n-1;
        int a=n/3;
        int b=n%3;
        long ans=1;
        if(b==0){
            while(a!=0){
                ans=ans*3%1000000007;
                a--;
            }
            return ans;
        }
        if(b==1){
            a=a-1;
            while(a!=0){
                ans=ans*3%1000000007;
                a--;
            }
            return (ans*4)%1000000007;
        }
        //b==2
        while(a!=0){
            ans=ans*3%1000000007;
            a--;
        }
        return ans*2%1000000007;
    }
};
```