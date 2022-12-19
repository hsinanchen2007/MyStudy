### 解题思路
# 结果
好吧，也算是记录一下第一次100%击败，也不枉费写了一个晚上，下标改来改去的头都晕了= =还是得加强基本功啊
![image.png](https://pic.leetcode-cn.com/135bd57ebfcaf2c6a32a3526d7a0a0ddab051f64e433de09841c7f9b6cf168ab-image.png)
# 思路
还是先说一下解题思路吧，具体的办法是通过首尾两个指针，在string中确定出一个子串，然后对这个子串进行操作，也可以被称为滑动窗口吧。就是不断向后移动end指针，以不断增加子串的长度，找出所有连续的不重复子串组合，在移动过程中会遇到不同的情况。
同时利用一个maxLength暂存当前最长的子串长度，且每次移动指针时将当前子串(注意**当前子串**，和**当前最长子串**的区别)长度与maxLength进行比较，保持maxLength的正确性。

**情况如下：**(其实也就只有重复、不重复两种情况)
1. 可以增加，即不与子串中的字符相同。若end指针的下一位字符，与已经确定的子串中所有字符都不相同，就把下一位字符加入到这个确定的子串中。
![image.png](https://pic.leetcode-cn.com/227208de10b524772585fce3e7e7756894ddf244d25e7f6624cb2ae422428506-image.png)
以第一个输入为例，此时已经确定出子串ab，想要将c加入到子串中，所以依次比较a，b是否与c相同，可判断出都不相同，所以将c加入子串。end后移一位。
2. 不能增加，即子串中有相同字符。还是以第一个输入为例，此时想将end指针的后一位a加入子串中，所以从begin<i<end的区间不断比较子串中的字符，第一次就出现重复的情况。所以将begin，即子串的开头移动到i+1的位置，原因是[begin,end]区间内的所有字符已经确定是不重复的，即abc子串中没有重复字符。而需要做的只是不断向后移动指针，以找出所有连续的不重复子串组合，所以将与后续加入的end后一位的a加入到子串中，将第一个a移除。
![image.png](https://pic.leetcode-cn.com/2ecd49085167bfa3305510823dcc9015970c4090470316005bc62ff3dc83f939-image.png)
(好吧，第二种情况可能说起来很乱，再找一个明显的例子)
![image.png](https://pic.leetcode-cn.com/674546aabb1b728cc4bbb5e30fa4242f57f8004beb0003561e400ae9b92eb12b-image.png)
也是一个输入示例。此时想要将end后一位的u加入子串中，所以比较begin<=i<=end区间的内的所有字符，当i指向gub中的u时，发现u重复。所以为了保证end在不断向后移动的过程中能够找到剩余的连续不重复子串，需要将begin移动到i+1，即b的位置处。

其实总结一下，就是前部分已经找出的子串就不再继续保留，只保证还没处理到的部分，即end后续部分可以保持连续的不重复子串。而前面已经处理过的部分，由于maxLength的存在，已经记录下最长的子串长度，只需要继续寻找可能出现的子串即可。

# 代码结构
再分析一下代码结构，首先对于特殊情况直接输出结果，不进入逻辑运行体内占用运行时间(其实也是提交的时候踩到的坑)。所以对于长度0和1的字符串直接输出结果，不存在二义性。

对于strin的处理我采用的是转换为char数组的形式，因为还没有深入地了解c++的底层架构，可能也算是比较低级的办法了，大佬们要是有更好的处理办法也可以使程序更加优化。

采用一个变量记录当前最大的不重复子串长度，即maxLength，采用双指针begin、end的形式，构建出一个可以滑动的子串区间。bool变量表示在一次对比循环中是否出现了字符相等的情况。

在接下来的while循环就是整个函数的逻辑主体了，这部分完全按照解题思路进行。等到逻辑循环退出以后，返回全局最大不重复子串长度maxLength。

# 总结
时间复杂度方面，begin和end分别最大移动n次，而中间还有一个[begin,end]的遍历比较，所以为O(2n+n!)，所以执行的时间并没有很短。
内存部分多出来的额外处理数据就是1个bool标记，2个int位置指针，2个int长度变量，算是比较精简了吧。

当然我也深知自己愚钝，还是缺少练习的时间和学习的深度，与大牛们有着很大的差距。欢迎大家指正我的错误，以及提出宝贵的建议，一定虚心采纳。
最后还是大家一起加油吧。奥力给

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int length = s.length();

        if( length==0 )
            return 0;
        if( length==1 )
            return 1;

        char *arry = (char*)s.c_str();

        int maxLength = 0, begin = 0, end = 0;
        bool notEqualed = true;
        
        while( end < length ){

            for( int i=begin; i<end; i++ ){
                if( arry[i]==arry[end] ){
                    begin = i+1;
                    notEqualed = false;
                }
            }
            if( notEqualed )
                end++;

            if( (end-begin)>maxLength )
                maxLength = end-begin;

            notEqualed = true;//reset flag
        }

        return maxLength;
    }
};
```