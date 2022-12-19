首先是长度，长度不符直接排除，然后统计不同的下标，存入数组，不同次数超过2就直接return 0，然后结束循环判断互换之后能否相等，后来发现系统说abab和abab也是可以的，我这样就不行了，我想想确实是，人家aa自己换或者bb自己换也行啊，然后加个数组，存放字母出现的频率，一旦为2，就变flag，后来循环结束后加个判断，原理上来说是最蠢的方法了。至于更深层次的方法，留个大神思考吧！
虽然我这个答案过题目没问题，但是有个漏洞，就是当一个字母不同的时候，array数组只有一个元素被赋值了，另外的一个是空，可能会出错，可以倒数第一个if语句前加一个d==2&&判断改进
```
/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */
class Solution {
 public:
  bool buddyStrings(string A, string B) {
    int a = A.size(), b = B.size();
    if (a != b) return 0;
    int d = 0;                   //不同的个数
    int array[2], al[26] = {0};  //array存不同的下标，al存26个字母统计个数，到2就不统计了
    bool flag = 1;
    for (int i = 0, t = 0; i < a; ++i) {
      if (flag && ++al[A[i] - 'a'] == 2) flag = 0;
      if (A[i] != B[i]) {
        if (++d > 2) return 0;
        array[t++] = i;
      }
    }
    if (!d && !flag) return 1;
    if (A[array[0]] == B[array[1]] && A[array[1]] == B[array[0]]) return 1;
    return 0;
  }
};
```