### 解题思路
转为组合问题处理, 添加字符串的回文判定

### 代码

```java []
class Solution {
    public List<List<String>> partition(String s) {
        if(s == null || s.length()==0)
            return res;
        int N = s.length();
        isPalindrome(s);
        ArrayList<String> arr = new ArrayList<>();
        makePalindrome(s, 0, arr);
        return res;
    }

    private void makePalindrome(String s, int index, ArrayList<String> arr){
        if(index == s.length()){
            this.res.add(new ArrayList<String>(arr));
        }

        for(int i=index; i<s.length(); ++i){
            if(f[index][i]){
                arr.add(s.substring(index, i+1));
                makePalindrome(s, i+1, arr);
                arr.remove(arr.size()-1);
            }
        }
    }

    // 存储S中的所有回文串信息
    private void isPalindrome(String S){
        int N = S.length();
        // 状态: f[i][j]表示S[i..j]是否为回文串
        this.f = new boolean[N][N];
        for(int i=0; i<N; ++i)
            f[i][i] = true;

        for(int i=0; i<N-1; ++i)
            f[i][i+1] = (S.charAt(i)==S.charAt(i+1));
        
        // 方程: f[i][j] = f[i+1][j-1]+1 | S.charAt(i)==S.charAt(j)
        for(int i=N-3; i>=0; --i)
            for(int j=i+2; j<N; ++j){
                f[i][j] = f[i+1][j-1] && (S.charAt(i)==S.charAt(j));
            }

    }

    private boolean [][]f;
    private List<List<String>> res = new ArrayList<>();
}
```
```python []
class Solution:
    
    def partition(self, s: str) -> List[List[str]]:
        N = len(s)
        self.res = []
        if N == 0:
            return self.res
        
        self.isPalindrome(s)
        comb = []
        self.makeCombination(s, 0, comb)
        return self.res

    def makeCombination(self, s, index, comb):
        if index == len(s):
            self.res.append(list(comb))
            return

        for i in range(index, len(s)):
            if self.f[index][i]:
                comb.append(s[index:i+1])
                self.makeCombination(s, i+1, comb)
                comb.pop(-1)

    
    def isPalindrome(self, s):
        N = len(s)
        self.f = [[False for _ in range(N)] for _ in range(N)]

        # 状态: f[i][j]表示s[i..j]是否构成回文
        for i in range(N):
            self.f[i][i] = True

        for i in range(N-1):
            self.f[i][i+1] = s[i]==s[i+1]

        # 方程: f[i][j] = f[i+1][j-1] && s[i]==s[j]
        for i in range(N-3, -1, -1):
            for j in range(i+2, N):
                self.f[i][j] = (self.f[i+1][j-1] and (s[i]==s[j]))
```
```c++ []
class Solution {
public:
    vector<vector<string>> partition(string s) {
        // 分割问题->组合问题
        if(s.size() == 0)
            return res;
        vector<string> vec;
        makePalindrome(s, 0, vec);
        return res;
    }

private:
    void makePalindrome(string s, int index, vector<string> vec){
        if(index == s.size())
            res.push_back(vec);

        for(int i=index; i<s.size(); ++i){
            if(isPaindrome(s.substr(index, i-index+1))){
                vec.push_back(s.substr(index, i-index+1));
                makePalindrome(s, i+1, vec);
                vec.pop_back();
            }
        }
    }

private:
    // 判断是否为回文串
    bool isPaindrome(string s){
        int N = s.size();
        for(int i=0, j=N-1; i<j;){
            if(s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }

private:
    vector<vector<string>> res;
};
```