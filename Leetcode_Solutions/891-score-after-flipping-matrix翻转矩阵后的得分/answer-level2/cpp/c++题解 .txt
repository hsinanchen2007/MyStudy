
![image.png](https://pic.leetcode-cn.com/1a720ef5d2d16d560445ef9b7692e8307ce910c506e3adfb93b29bb0d8d9add2-image.png)

思路：
第一列必为1，然后逐列看 1 和 0 的个数 1<0的时候，进行翻转，否则不变
有一个快捷的方法，就是翻转的时候就加和

```
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int output=0; 

        for(int i=0;i<A.size();i++){
            if(A[i][0] == 0){
                A[i][0] = 1;
                for(int j=1;j<A[0].size();j++){
                if(A[i][j] == 1){
                    A[i][j] = 0;
                }else{
                    A[i][j] = 1;
                }
              }
            }
        }
        
        int one = 0;
        int zero = 0;
        
        for(int j=1;j<A[0].size();j++){
             for(int i=0;i<A.size();i++){
                if(A[i][j] == 1){
                    one ++;
                }else{
                    zero++;
                }
            }
            if(one >= zero){
                one = 0;
                zero = 0;
                continue;
            }
            for(int i=0;i<A.size();i++){
                if(A[i][j] == 0){
                    A[i][j] = 1;
                }else{
                    A[i][j] = 0;
                }
            }
            one = 0;
            zero = 0;
        }

        
        for(int i=0;i<A.size();i++){
            output += getsum(A[i]);   
        }
        
        return output;
    }
    
    int getsum(vector<int> A){
        int sum=0;
        for(int i=0;i<A.size();i++){
            int k = A.size() - i -1;
            int o = 1;
            for(int j=0;j<k;j++){
                o = o*2;
            }
            sum += o* A[i];
        }
        
        return sum;
    }
    
    
};
```
