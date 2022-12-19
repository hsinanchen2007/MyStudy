### 解题思路
1. [素数打表（4种方法）](https://blog.csdn.net/Harington/article/details/86571150)
    - 我们算一个数是否是素数，是不是要判断它的因子，是否只是1和他本身,从2 ~ sqrt(n)
    - 埃拉托斯特尼筛法: 去除合数: 若i是素数，则从 j=i*i 开始，把 j+i , j+2i , j+3i .....都标记为合数 （因为2*i , 3*i,4*i,....(i-1)*i 分别是2,3,4,...i-1的的倍数，已经在i之前标记过，所以从j=i*i开始标记）
        ```
        #include<iostream>
        using namespace std;
        #define MAX_NUM 10000000
        bool isPrime[ MAX_NUM + 10 ];
        
        void prim(){
            for(int i = 2; i <= MAX_NUM; i++)
                isPrime[i] = 1;
            for(int i = 2; i <= MAX_NUM; i++){
                if( isPrime[i] )
                    for(int j = 2 * i; j <= MAX_NUM; j += i)
                        isPrime[j] = 0;
            }
            
            for(int i = 2; i <= MAX_NUM; i++){
                if(isPrime[i])
                cout << i << endl;
            }
        } 
        
        int main(){
            prim();
            return 0;
        }

        ```

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        n = len(deck)

        if n <= 1:
            return False
        
        di = dict()

        for i, ele in enumerate(deck):
            di[ele] = di.get(ele, 0) + 1

        g = -1
        for idx, val in di.items():
            if val == 1:
                return False
            if g == -1:
                g = val
            else:
                g = self.gongyue(g, val)
                if g == 1: ## 剪枝
                    return False
        return g >= 2

    def gongyue2(self, a, b):
        if a == 0:
            return b 
        else:
            return self.gongyue(b%a, a)

    def gongyue(self, a, b):
        while a != 0:
            a, b = b % a, a
        return b 
```