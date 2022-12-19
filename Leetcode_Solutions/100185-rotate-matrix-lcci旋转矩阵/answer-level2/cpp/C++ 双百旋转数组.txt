![45b711144e80bdbed5ba4735fa9cb30.png](https://pic.leetcode-cn.com/c6d90087c5a31d6c4935b0267095a7cf649807c720bb81e301bac344a2e6cc61-45b711144e80bdbed5ba4735fa9cb30.png)

这题似曾相识，和主站上的48题相同，这次解答的思路也是这样。
核心思想是找一个位置的数值进行旋转，然后旋转下一个数值。以下图为例，①旋转后的位置在③，③旋转后的位置在⑨，然后是⑦。①→③→⑥→⑨四个数各自移动了一个位置。(盗图于官方48的题解)

![be0d53dfd7fe925bf767c02444a645a.png](https://pic.leetcode-cn.com/4d860e3bad04e9bcef4c9437dd0a0ea0a9f970eb00d4619c1f241d3ccf213fbb-be0d53dfd7fe925bf767c02444a645a.png)

①旋转结束后，旋转②，直到最外的一圈旋转完成；
从外向内，外圈旋转后旋转内圈，直到n=1，或者n=0(其实n小到一定程度，while里面的for循环就停止了)

时间复杂度是`O(n^2)`，空间复杂度是`O(1)`，就地完成。
```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp,bef,cycle=0;
        int n = matrix.size();
        //cycle是行数，cycle=0时，是最外圈，cycle=1是次外圈，以此类推
        while(n>1){
            for(int i=cycle;i<n-1;i++){
                bef = matrix[cycle][i];
                int begrow = cycle, begcol=i;
                for(int num=0;num<4;num++){
                    //循环四次，旋转①，③，⑥，⑨四个数字的位置
                    temp = matrix[begcol][n-1-begrow];
                    matrix[begcol][n-1-begrow] = bef;
                    bef = temp;
                    temp = begcol;
                    begcol = n-1-begrow;
                    begrow = temp;
                }
            }
            cycle++;
            n--;
        }

    }
};
```

