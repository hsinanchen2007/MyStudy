### 思路：
二分回文长度，根据是否找到相应长度的回文串情况来修改端点值。

* 与普通的二分区别：区间长度为 2 不能满足条件时，长度 3 可以满足条件，如 "aba"，因此要对二分进行修改，每次二分时，需要进行两次判断，长度值，及长度值+ 1，都不满足时缩减区间长度，一者满足则增加区间长度。

* 正确性：长度为 5 满足，则长度为 3 一定满足；长度为 4 满足，则长度为 2 一定满足，因此二分是正确的。

* 效率 ：执行用时：12 ms, 在所有 C++ 提交中击败了 95.67% 的用户；

   内存消耗：9 MB, 在所有 C++ 提交中击败了 90.81% 的用户

下面是代码
```python [-python]
class Solution:
    def checkPolindrome(self, s: str) -> bool:
        i = 0
        j = len(s)-1
        while i<j:
            if s[i]!=s[j]:
                return False
            i+=1
            j-=1
        return True
    
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ''
        # 二分长度, 直接二分长度不行，因为3个成立，2个有可能不成立
        # 但是长度为4成立，则2一定成立，长度为5成立，则3一定成立
        # 因此每次判断两个一奇一偶，不满足才能长度减一。
        ans = ''
        l = 0
        r = len(s)
        while l<=r:
            mid = (l+r)//2
            find = False
       
            for i in range(len(s)-mid+1):
                if self.checkPolindrome(s[i:i+mid]):
                    find = True
                    ans = s[i:i+mid]
                    break
                    
            for i in range(len(s)-mid):
                if self.checkPolindrome(s[i:i+mid+1]):
                    find = True
                    ans = s[i:i+mid+1]
                    break   
            if find:
                l = mid + 1
            else:
                r = mid - 1
        return ans
```
```c++  [-c++]
class Solution {
public:
    bool checkPalindrome(string &s, int i, int j) {
        if (j>s.size()) return false;
        while (i<j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int low = 0, high = s.size(), mid;
        string ans;
        if (s == ""|| s.size() == 1) 
            return s;
    
        while (low<=high) {
            mid = (low+high)/2;
            bool changed = false;
            for (int i=0;i<s.size()-mid;i++) {
                if (checkPalindrome(s, i, i+mid-1)){
                    changed = true;
                    ans = s.substr(i, mid);
                    break;
                }
            }
            for (int i=0;i<s.size()-mid;i++) {  //此处应该-1，但最长时，会得到-1，因此在check函数里判断
                if (checkPalindrome(s, i, i+mid)){
                    changed = true;
                    ans = s.substr(i, mid+1);
                    break;
                }
            }
            
            if (!changed) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            
        }
        return ans;
    }
};
```


