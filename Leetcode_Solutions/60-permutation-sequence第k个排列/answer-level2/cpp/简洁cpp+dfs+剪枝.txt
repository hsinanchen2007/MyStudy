从递归的角度出发，这题与一般的全排列问题的思路是一致的，可以大体套用dfs的模板，但是这样会超时。那如何在dfs搜索中进行剪枝是本题的关键。回顾下我们使用dfs搜索的过程，下面是dfs搜索树的搜索路径分析。
![Draft-1.jpg](https://pic.leetcode-cn.com/93effd21b842e31ddb3d9a05477dade2e92f79948805343ce7108a7759dedddd-Draft-1.jpg)

假设 n = 4, k = 17，我们可以知道第17个全排列为[3,4,1,2]，为了找到它，我们需要在关键节点做剪枝。如何判断呢？如图，当我们开始搜索时，我们访问紫色节点“1”，注意到此时如果我们继续往下访问（深度搜索），其实是没有意义的，因为从该节点往下最多有3！=6个全排列组合，而我们要找的是第17个，6<17，所以直接剪枝；访问紫色节点“2”，同理可知，在该节点处需要剪枝；访问紫色节点“3”,此时满足条件，6 > 5，需要往下搜索。（这里注意，一个简单的计数技巧，就是当某个节点处需要剪枝时，我们需要更新k值，**k = k - 该节点对应阶乘数**）。从紫色节点“3”处，向下搜索，直到搜索完[3,4,1,2]，这就是我们要的答案。代码如下：

```
class Solution {
private:
    vector<int> hash;
    vector<int> factorial;
    bool flag = true;
    void dfs(int cur, int n, int &k, string &ret, int &cnt, string path){
        if(cur == n){
            ret = path;
            flag = false;
            return;
        }
        int temp = factorial[n-cur-1];
        for(int i=0; i<n; i++){
            if(hash[i] && flag){
                if(temp < k ){
                    k = k - temp;
                    continue;
                }
                path.push_back(i+1+'0');
                hash[i] = 0;
                dfs(cur+1,n,k,ret,cnt,path);
                hash[i] = 1;
                path.pop_back();
            }
        }
    }

public:
    string getPermutation(int n, int k) {
        //calculate the factorial
        if(n == 1) return "1";
        factorial.resize(n);
        factorial[0] = 1;
        factorial[1] = 1;
        if(n > 2){
            for(int i=2; i<n; i++){
                factorial[i] = i * factorial[i-1];
            }
        }
        string ret;
        string path;
        hash.resize(n,1);
        int cnt = 0;
        dfs(0,n,k,ret,cnt,path);
        return ret;
    }
};
```

注意计算阶乘时的细节处理，0!=1,1!=1。
