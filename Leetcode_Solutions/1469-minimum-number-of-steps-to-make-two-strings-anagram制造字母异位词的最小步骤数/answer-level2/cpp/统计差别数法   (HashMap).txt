解决：（统计差别数法）

思路：将t替换为s的异位词其实就是统计好s中的字符，t与其进行对比看看缺少哪些字符，数量是多少，s不需要管自己是否缺少t中的字符。只需让t去找与s中它缺少的字符量即可。



 @1: 创建两个hashmap分别统计s和t的字符个数   （关键字为char，值为value）
@2：遍历s，使用smap中的字符数量减去tmap中存在的smap相对应的字符数量并累加到 suppleLength（统计改动的字符数量），如果t中不存在该字符，会添加关键字字符并给与默认值0的pair，如果smap该字符数量小于tmap字符数量，累加到suppleLength的值将会是0，因为s不需要管t中比自己多出的那部分。

时间复杂度：O（2m+n）  m+n为
空间复杂度：O（m+n）

代码：
```
class Solution {
public:
   int minSteps(string s, string t) {
      int suppleLength=0;
      map<char,int> smap;
      map<char,int> tmap;
      for (auto  c: s ) {
         ++smap[c];
      }
      for (auto  c: t) {
         ++tmap[c];
      }

      auto beg=smap.begin();
      while(beg!=smap.end())
      {
         int errorValue=smap[beg->first]-tmap[beg->first];
         suppleLength+=(errorValue<0 ? 0 :errorValue);
         ++beg;
      }
      return suppleLength;
   }
};
```
