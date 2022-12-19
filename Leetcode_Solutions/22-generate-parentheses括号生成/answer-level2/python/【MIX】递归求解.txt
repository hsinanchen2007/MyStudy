### 解题思路
在递归过程中检查左右括号的配对性

### 代码

```java []
class Solution {
    public List<String> generateParenthesis(int n) {
        this.res = new ArrayList<String>();
        String ans = new String();
        makePermutation(ans, 0, 0, n);
        return this.res;

    }

    private void makePermutation(String ans, int left, int right, int n){
        if(ans.length() == 2*n){   
            this.res.add(new String(ans));
            return;
        }
        if(left < n)
            makePermutation(ans+"(", left+1, right, n);

        if(right < left)
            makePermutation(ans+")", left, right+1, n);
    }

    private List<String> res;
}
```
```python []
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.res = []
        ans = ""
        self.makePermutation(ans, 0, 0, n)
        return self.res

    def makePermutation(self, ans, left, right, n):
        if len(ans) == 2*n:
            self.res.append(ans)

        if left < n:
            self.makePermutation(ans+"(", left+1, right, n)

        if right < left:
            self.makePermutation(ans+")", left, right+1, n)
```
```c++ []
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // 递归+回溯法
        int N = 2*n;
        string ans;
        makePermutation(ans, 0, 0, n);

        return res;
    }

private:
    void makePermutation(string ans, int right, int left, int n){
        if(ans.size() == 2*n){
            this->res.push_back(ans);
        }
        
        if(left < n){
            makePermutation(ans+"(", right, left+1, n);
        }

        if(right < left){
            makePermutation(ans+")", right+1, left, n);
        }
    }

private:
    vector<string> res;
};
```
**2020/4/9**
```c++ []
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return res;
        
        string ans;
        makeComb("", 0, 0, n);
        return res;
    }

private:
    void makeComb(string ans, int l, int r, int n){
        if(r == n)
            res.push_back(ans);
        if(l < n)
            makeComb(ans+"(", l+1, r, n);
        if(r < l)
            makeComb(ans+")", l, r+1, n);
    }

    vector<string> res;
};
```