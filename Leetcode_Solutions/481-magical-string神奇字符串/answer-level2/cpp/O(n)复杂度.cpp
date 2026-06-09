两个指针，走前面的负责填数，走后面的负责获得要填的数量。由于只需要填1或者2，每次填完了一种数，就直接换另一个填。

遍历1遍，时间复杂度O(n)，空间复杂度O(n)。不过只能从n>2开始。

![Screenshot from 2019-12-11 16-53-28.png](https://pic.leetcode-cn.com/3ce8b861d7c6db89699da788d2e4f637c04977e0e2e0867a6345ca4435ef4dcf-Screenshot%20from%202019-12-11%2016-53-28.png)

```
class Solution {
public:
    int magicalString(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;
        int i=1,
            j=1,
            cnt=2,
            res=1,
            num=2;
        int S[n];
        S[0]=1;
        while(i<n && j<n){
            while(cnt>0 && i<n){
                S[i]=num;
                if(num==1)res++;
                cnt--;
                i++;
            }
            num= num==1?2:1;
            cnt=S[++j];
        }
        return res;
    }
};
```
