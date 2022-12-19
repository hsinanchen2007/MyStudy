![image.png](https://pic.leetcode-cn.com/c5b9d9cd7bf9c2902b78a8071dc029be7a3bd56cbeb0a7d0938939930725d1a7-image.png)

**贴上老师的ppt，一定要看!**
属于子集树问题。

![image.png](https://pic.leetcode-cn.com/395422eadc7360181e0c1e4b7d22ca2b90b729a025be3a74f086287bdfbbc1b8-image.png)
![image.png](https://pic.leetcode-cn.com/66ed35e2026fda9cc8e4c27c1fee61c3402ec8642d3bae9bcce01b47c0df5dab-image.png)
![image.png](https://pic.leetcode-cn.com/905ca01b62e31059e3518e22e9fe2b7f383d4b4d543eace29b88299e1d62fb46-image.png)



### 解题思路
先生成数字形式的解，再转成字符串形式的。
注释详细。

### 代码

```cpp
class Solution {
private:
    vector<vector<string>> res; // 最终的字符串形式的解集
    vector<vector<int>> numRes; // 数字形式的解集，和ppt中类似
    vector<int> x;  // 存放一个可行的数字形式的解
    int n; // 全局变量，存放最初传进来的n。
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n; // 将参数n置为全局
        dfs(0);// 决定第0行的皇后放在第几列
        turn_numRes_to_res();// 得到数字形式的解numRes之后，转换得到字符串形式的
        return res;
    }
    void dfs(int k){ // 决定第k行的皇后放在第几列
        if(k==n){ // k==n说明前面n行的皇后都放好了，于是得到了一个解
            numRes.push_back(x); // 将得到的一个解放到数字形式的解集numRes中
            return ; //回溯
        }
        for(int i=0; i<n; i++){// 每一行的皇后都有n列可能放置
            x.push_back(i);    // 首先尝试放入皇后
            if(placeTest(k)){ // 然后测试本轮的这种放置方案是否可行
                dfs(k+1); // 如果可行，就放置下一行的皇后
            }
            x.pop_back(); // 尝试完了，就pop出去，准备尝试下一个。
        }
    }
    bool placeTest(int k){ // 测试第k行的此时的放置方案是否合理
        for(int i=0; i<k; i++){ // 只要确保前面的k-1行都不和本次放置的数在同一列或者在同一对角线上就可以了。
            if(x[i]==x[k] || x[i]-x[k]==i-k ||x[i]-x[k]==k-i){
                return false;
            }
        }
        return true;
    }
    void turn_numRes_to_res(){ // 功能如名
        for(int i=0; i<numRes.size(); i++){//对每一个可行解x
            vector<string> resString;  
            for(int j=0; j<n; j++){// 对每个可行解的每个数，肯定是n个数，因为是n行
                string s = "";
                for(int t=0; t<n; t++){//对于一个具体的数，生成一个string
                    if(t==numRes[i][j]) s+='Q';
                    else s += '.';
                }
                //生成一个string之后，作为最后一个解的最后一个字符串
                resString.push_back(s);
            }
            res.push_back(resString);
        }
    }
};
```
有收获的话求赞。