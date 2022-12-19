
首先须知道十进制数如何转化二进制，一句话来说就是“除二取余，倒序排列”。
题目要求1的个数，令F(n)表示十进制数字n转化为二进制后1的个数。
结合动态规划思想来看，可以得出
状态转移公式：F(n) = F(n/2) + n%2 
边界：F(0) = 0
代码如下：
```
vector<int> countBits(int num) {
        vector<int> a;
        for(int i=0;i<=num;i++){
            if(i==0){
                a.push_back(0);
            }else{  
                int current = a.at(i/2) + i%2;
                a.push_back(current);
            }
        }
        return a;
    }
```
