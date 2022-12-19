题意很简单，如果字符串s1和字符串s2存在包含关系，那么长度较短的字符串可以被长度较长的那个来表示，
相当于后缀表示，如果s1与s2存在这样的后缀匹配关系，那么显然在反转s1,s2之后，他们应该也存在前缀完全匹配

而前缀匹配有一个很关键的标志：**字典序相邻**
其次，明确求的目标：对于一个字符串，我们只关心是否存在另一个能与之反转前缀匹配，而不在乎有几个，是哪一个

**进一步讨论，可以发现如下几个性质：**
##### 1: 如果s2包含s1,那么在反转排序之后，s1的索引一定在s2前面 
##### 2: 如果只存在一个s2包含s1,那么s1与s2一定相邻
     这两个性质很容易理解，等同于字典序
##### 3: 如果存在多个字符串s2,s3……包含s1
    我们还是只需要关心在反转排序之后与s1相邻的字符串
    因为我们想求的是是否存在字符串包含s1，而不在乎是具体哪一个，因此如果与s1相邻的那个都
    不能匹配，那么后面的更不可能，而如果存在多个，那么相邻的那个也一定是
##### 4: 如果匹配成功，那么顺延一位，否则加上当前字符串的长度再加一（井号），只需要进行一重循环
##### 5: 假设字符串的平均长度为M,字符串个数为N,那么时间复杂度为O(NM),几乎不需要申请额外的空间

最终的评测结果如下
![image.png](https://pic.leetcode-cn.com/3e35c4bbc7aa4cc9eb0dec06fd26d680a9ed1af5c89b60e3566ee7d775025e18-image.png)
时间表现不算优秀，但是代码简短易懂（除去注释仅21行）

最后附上c++代码
```cpp
class Solution {
public:
    //匹配函数
    bool Match(string s1,string s2){
        /*可能会疑惑如果s1.length > s2.length  
         *会不会访问s2[i]的时候越界
         * 其实不会
         * 因为如果s2前缀匹配s1，那么其长度一定≥s1
         * 而如果不匹配，那么一定会在访问越界之前结束
         * 所以用哪个字符串的长度其实是无所谓的
         */
        for(int i = 0;i < s1.length();i++)
            if(s1[i] != s2[i]) return false;
        return true;
    }
    int minimumLengthEncoding(vector<string>& words) {
        const int n = words.size();
        if(n == 0) return 0;
        if(n == 1) return words[0].length()+1;
        //反转并排序
        for(int i = 0;i < n;i++) reverse(words[i].begin(),words[i].end());
        sort(words.begin(),words.end());
        
        //最后一个字符串一定不会被包含，因此预先加上
        int ans = words[n-1].length()+1;
        for(int i = 0;i < n-1;i++){
            if(!Match(words[i],words[i+1]))
                ans += words[i].length()+1;
        }
        return ans;
    }
};
```
