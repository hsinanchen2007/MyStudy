刚开始看到这道题的时候，毫无思路，只知道题目要求我们求出一个最长无重复字符的拼接串。不过仔细分析后发现其实就是**对一个二叉树进行回溯**。接下来，我们一步步分析。

### 解题思路（抽象为一颗二叉树）
你可能会有疑惑，这和二叉树有什么关系呢，为什么要抽象为一颗二叉树呢？通过分析我们发现，对于字符数组`arr`中的每个字符串都只有两个选择：要么加入到最后的结果串，要么不加入。对吧！你是不是明白了什么？哈哈。 

我们可以从`arr`中的第一个字符串开始（作为根结点），然后分出两个分支，**假设往左分支走是加入当前字符串，往右分支走就不加入当前字符串**。最后，我们只需要返回左右两个分支所产生的结果串中较长的那个即可。
1. 走左分支（即加入当前字符串）产生的结果串长度为，当前字符串长度+继续向下遍历返回的结果串长度，`curLen + dfs(arr, childIndex+1, t)`.
2. 走右分支（即不加入当前字符串）产生的结果串长度就只是继续向下遍历返回的结果串长度，`dfs(arr, childIndex+1, m)`.
3. 最后返回两者中较长的一个即可，`return max(curLen + dfs(arr, childIndex+1, t), curLen + dfs(arr, childIndex+1, m))`.

这样思路就很清晰了！不过这里还有些细节需要注意下。
- 因为要考虑到结果串中不能存在相同的字符，我们就需要构建一个长度为26的哈希表来记录每个字符出现的次数（因为`arr`中只含小写字母，所以长度为26）。然后编写一个判断字符串是否所有字符唯一的函数：
```cpp
/*
  t[0]~t[25]分别表示'a'~'z'
  因此使用s[i]-'a'即可实现一一映射
*/
bool isUnique(string& s, vector<int>& t) {
    for (int i = 0; i < s.length(); i++) {
        t[s[i]-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (t[i] > 1) {
            return false;
        }
    }
    return true;
}
``` 
- 当我们考虑走左分支或右分支时，还需考虑加入当前字符串是否会造成结果串出现相同字符，如果不会出现相同字符即`isUnique`，就可以同时向左和向右遍历；否则就只能向右遍历，即不能加入当前字符串。


Code Following

```cpp
class Solution {
public:
    int maxLength(vector<string>& arr) {
        // 当作哈希状态表，记录每个小写字母出现的次数
        vector<int> m(26, 0);  
       // 以0号元素为根结点，开始回溯。 
        return dfs(arr, 0, m);  
    }
    int dfs(vector<string>& arr, int childIndex, vector<int> m) {
        if (childIndex == arr.size()) {
            return 0;
        }
        // 再定义一个状态表来保存加入当前字符串之后的状态
        vector<int> t(m); 
        if (isUnique(arr[childIndex], t)) {
            int curLen = arr[childIndex].length();
            int len1 = curLen + dfs(arr, childIndex+1, t);
            int len2 = dfs(arr, childIndex+1, m);
            return max(len1, len2);
        }
        return dfs(arr, childIndex+1, m);
    }
    /*
    判断加入字符串s后，是否满足不含相同字符
    注意对于哈希表传入的是引用
    */
	bool isUnique(string& s, vector<int>& t) {
	    for (int i = 0; i < s.length(); i++) {
	        t[s[i]-'a']++;
	    }
	    for (int i = 0; i < 26; i++) {
	        if (t[i] > 1) {
	            return false;
	        }
	    }
	    return true;
	}
};
```
时间复杂度为$2^n$。
### 哈希表使用位压缩代替
由题可知，字符串中只含有小写字母（最多只需使用26位来存储每个字符的存在状态）。

1. 使用一个36位的int来存储结果字符串的状态，初始化为0（开始时每位都为0，0～25位分别表示a～z）。`int m = 0;`

2. 每来一个字符`c`先通过`i = c-'a'`获取它的对应位`i`，然后判断`m`的第`i`位是否为0. 如果为0，说明该位对应字符还未出现；否则该字符已存在，返回`false`。

使用位压缩的判断函数就是下面这样
```cpp
bool isUnique(string& s, int& t) {
    for (char c : s) {
        int i = c-'a';	//获取字符对应位
        //判断该位是否为0
        if (t & (1<<i)) {
            return false;
        }
        t |= (1<<i);
    }
    return true;
}
```

修改之后的代码

```cpp
class Solution {
public:
    int maxLength(vector<string>& arr) {
       // 当作哈希状态表，记录每个小写字母出现的次数
        int m = 0;   
        return dfs(arr, 0, m);
    }
    int dfs(vector<string>& arr, int childIndex, int m) {
        if (childIndex == arr.size()) {
            return 0;
        }
        int t = m;
        if (isUnique(arr[childIndex], t)) {
            int curLen = arr[childIndex].length();
            int len1 = curLen + dfs(arr, childIndex+1, t);
            int len2 = dfs(arr, childIndex+1, m);
            return max(len1, len2);
        }
        return dfs(arr, childIndex+1, m);
    }
    bool isUnique(string& s, int& t) {
        for (char c : s) {
            int i = c-'a';
            if (t & (1<<i)) {
                return false;
            }
            t |= (1<<i);
        }
        return true;
    }
};
```

### 最后

感谢您的观看！欢迎大家留言，一起讨论交流。

如果这篇文章对您有帮助，欢迎您扫码关注我的公众号，谢谢您的支持。

![小小算法.png](https://pic.leetcode-cn.com/1776597b2773892787b2a16738cd78feb346c5a5290273bce69275b0b66a0a95-%E5%AE%A3%E4%BC%A0%E5%9B%BE2.png)