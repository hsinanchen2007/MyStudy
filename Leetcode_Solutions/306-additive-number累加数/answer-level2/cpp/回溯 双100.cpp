### 解题思路
典型的回溯法的题：和之前有个斐波那契数列的题类似，直接把代码copy过来，改了下返回值，竟然发现"1203"的case过不了，看来之前那个题的测试数据不充分(之前那个题也有数字不能以0开头，代码没写对)，改好了之后发现还是过不了，仔细一看得用大数加法，抄袭了一个，0ms挺意外的

1，结束条件为：剩下的string为空。如果已参与计算的数大于等于3则说明是合法解，否则非法解
2，感觉没啥说的了，就是标准的回溯，详见注释吧
  大概就是从left中查找从0开始的子串，如果子串为前两个数的和，则继续dfs，然后回溯，过滤下left[0] == '0'的情况
3，子串还可以用index优化下，内存还能少点


执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.2 MB, 在所有 C++ 提交中击败了100.00%的用户


### 代码

```cpp
class Solution {
public:
    // 大数加法
    string add(string& a,string& b){
        int n1=a.size()-1;
        int n2=b.size()-1;
        int carry=0;
        string ans;
        while(n1>=0||n2>=0||carry>0){
            int t1=n1>=0?a[n1--]-'0':0;
            int t2=n2>=0?b[n2--]-'0':0;
            ans+=(t1+t2+carry)%10+'0';
            carry=(t1+t2+carry)>=10?1:0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    // left表示剩余的未参与计算的数字串，level表示已参与计算的数字个数，ans用于记录已参与计算的数字串
    bool backtrace(string& left, int level, vector<string>& ans) {
      // 剩余数字串为空，dfs结束，level小于1和2都是非法解
      if (left.empty() ) {
        if (level >= 3) {
          return true;
        } else {
          return false;
        }
      }

      for (int i = 0; i < left.size(); ++i) {
        // 从0索引获取子串
        string num = left.substr(0, i + 1);
        // 如果当前只有一个数，需要遍历选择第二个数；如果已有大于等于两个数，需要找到num必须为最后两数之和
        if (level < 2 ||
            num == add(ans[level - 1], ans[level - 2])) {
          // 记录一下当前数
          ans.push_back(num);
          // 构造剩余子串
          string substr;
          if (i + 1 < left.size()) {
            substr = left.substr(i + 1);
          }
          if (backtrace(substr, level + 1, ans)) {
            return true;
          }
          ans.pop_back();
        }

        // 如果首数为0，给它一次为最后一个数的机会，但不管它有没有可行解，无需继续dfs
        if (left[0] == '0') {
          break;
        }
      }

      return false;
    }

    bool isAdditiveNumber(string num) {
      vector<string> ans;
      return backtrace(num, 0, ans);
    }
};
```