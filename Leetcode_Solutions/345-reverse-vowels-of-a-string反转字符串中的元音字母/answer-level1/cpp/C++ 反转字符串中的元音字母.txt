### 题目描述

编写一个函数，以字符串作为输入，反转该字符串中的元音字母。


#### 样例

```
示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。
```


----------

### 算法1
##### (双指针)  $O(n)$

接着前面的167，
633题，依然是双指针题，这次的模板类似于快排的写法，快排就是找到两个左右侧大于和小于枢纽的进行交换，这道题则是找到两个元音开始比较，非常类似，i,j指针分别两端开始，指向中间，直到i<j不成立

#### C++ 代码
```
class Solution {
public:
    string reverseVowels(string s) {
        int l = 0,r=s.size()-1;
        while(l<r){
            while(s[l]!='a'&&s[l]!='e'&&s[l]!='i'&&s[l]!='o'&&s[l]!='u'&&s[l]!='A'&&s[l]!='E'&&s[l]!='I'&&s[l]!='O'&&s[l]!='U'&&l<=r)
                  l++;
            while(s[r]!='a'&&s[r]!='e'&&s[r]!='i'&&s[r]!='o'&&s[r]!='u'&&s[r]!='A'&&s[r]!='E'&&s[r]!='I'&&s[r]!='O'&&s[r]!='U'&&l<=r)
                  r--;
             if(l<r) swap(s[l],s[r]);
            l++,r--;
        }
        return s;
    }
};
```
###坑点
- 题目并没有告诉原因字母包括大小写，所以元音有10种而不是五种
- 再初始代码种，所有的字母分别比较，没有用一个数据存储下来，代码写起来很长，也容易出错，修改也不方便，
- 改进方法参考yxc的版本，将字母放于数组，并使用哈希表来判断
```
class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        unordered_set<char> S;//建立一个集合，用来判断当前元素是否在集合中，来判断是否元音
        for(auto c:vowels){
            S.insert(c);
        }
        int l = 0,r=s.size()-1;
        while(l<r){
            while(!S.count(s[l])&&l<=r)
                  l++;
            while(!S.count(s[r])&&l<=r)
                  r--;
            if(l<r) swap(s[l],s[r]);
            l++,r--;
        }
        return s;
    }
};
```