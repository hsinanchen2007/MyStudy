## 回溯法


```C++ []
class Solution {
public:
    void backtrack(int n, int& k, string& ans, vector<int>& visited, string& curr){
        if(!k) return;
        if(k == 1 && curr.size() == n){
            ans = curr;
            k--;
            return;
        }
        if(curr.size() == n){
            k--;
            return;
        }
           
        for(int i = 1; k && i < n + 1; i++){
            if(visited[i]) continue;
            curr.push_back('0' + i);
            visited[i] = 1;
            
            backtrack(n, k, ans, visited, curr);
            
            curr.pop_back();
            visited[i] = 0;
        }
        
    }
    string getPermutation(int n, int k) {
        string ans = "";
        string curr = "";
        vector<int> visited(n + 1, 0);
        backtrack(n, k, ans, visited, curr);
        return ans;
        
    }
};

```
回溯就不谈了，感觉复杂度过于高了。这里我没剪枝，运行实在太慢了

## 公式法

实际上，排列组合与自然数是有一定的对应关系的，这样的对应关系叫做双射，其实就是互相映射，一个整数对应一个序列。而寻求其中对应关系的公式就是康托展开

$$ X = a_n * (n-1)! + a_{n-1} * (n-2)! + ... + a_1 * 0! $$

公式如上

其中$a_i$为整数,并且$a_i$表示原数的第i位在当前未出现的元素中是排在第几个 X表示他前面一共有多少排列，所以他其实是第X+1个排列

```C++ []
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> f = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        vector<int> visited(n + 1, 0);
        string ans = "";
        k = k - 1;
        int l = n;
        while(l > 0){
            int x = k / f[l - 1];
            int y = k % f[l - 1];
            int i = x;
            int t = 1;
            for(int j = 1; j < n + 1; j++){
                if(!visited[j]){
                    i--;
                }
                if(!i){
                    t = j;
                    break;
                }
                    
            }
            visited[t] = 1;
            ans.push_back('0' + t);
            k = y;
            l--;
        }
        return ans;
    }
};

```
