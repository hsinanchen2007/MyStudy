### 解题思路
此处撰写解题思路
前面一老哥的算法思想真的是神了.
想到用位运算的想法来实现开辟数组识别带来的空间消耗.
一开始我想的是使用暴力法n^2时间
后来我又想用哈希表来加速搜索,时间降低到了nlogn
再然后想到开辟数组来识别字符.时间降到了n,当然空间还是n
最后,看到老哥的代码,把空间降到了1,时间还是n
总的来说我的代码了
max和min是用来位运算存储字符用的,其他的可以自由发挥,
不用深究我的代码.
最主要的是算法思想.
### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        int min=0,max=0;
        for(int i=0;i<astr.length();i++)
        {
            if(astr[i]<='z'&&astr[i]>='a')
            {
                if(min&(1<<(astr[i]-'a'+1))) return false;
                else min+=1<<(astr[i]-'a'+1);
            }
            else
            {
                if(max&(1<<(astr[i]-'A'+1))) return false;
                else max+=1<<(astr[i]-'A'+1);
            }
        }
        return true;
    }
};
```