

# 功能

查找一个字符串的最长回文子串的线性算法

# 算法原理与实现

1. 将长度为奇数和偶数的回文串一起处理

   Manacher 使用一种巧妙地办法，将长度为奇数的回文串和长度为偶数的回文串一起考虑。具体做法是，在原字符串的每个相邻字符中间插入一个分隔符，同时在首尾也要各添加一个分隔符。要求分隔符不在原字符串中出现。如下图所示，其中，原始字符串为 S，转换后的字符串为 T：

   ![](https://pic.leetcode-cn.com/d80b24a66d037190b40cce1864c10802742bb897b76d747a40eb0a41e5945633.jpg)

2. 使用额外空间存储必要信息 Len 数组

   辅助数组 Len 是算法的核心。

   Len[i] 表示以字符 T[i] 为中心的最长回文子串的最右端字符到字符 T[i] 的字符个数。

   比如，以 T[i] 为中心的最长回文子串是 T[l,r]，则 Len[i] = r - i + 1。

   对于上面的例子，可以得出如下的 Len 数组：

   ![](https://pic.leetcode-cn.com/7889b445470d2c1e82c35bf097136cb4d8c55dbb1bfc6a12fbe026bf7ef893ec.jpg)

   Len 数组的性质：Len[i] - 1 等于该回文子串在原字符 S 中的长度。

   证明如下：首先，在转换得到的字符串 T 中，所有的回文串的长度都为奇数。那么，对于以字符 T[i] 为中心的最长回文子串，其长度就是 2 × Len[i] -1。经过观察可知，T 中的所有回文子串，其中分隔符的数量一定比其他字符的数量多一。所以， 2 × Len[i] -1 的长度中，有 Len[i] 个分隔符，剩下 Len[i] - 1 个字符来自原字符串。综上所述，该回文串在原字符串中的长度为 Len[i] - 1。

3. Len 数组的计算
   
   从左向右依次计算 Len 数组。当计算 Len[i] 时，Len[0] ~ Len[i-1] 已经计算完毕。
   
   设 P 为之前计算中最长回文子串的右端点的最大值。并且，设取得这个最大值的位置为 Po。
   
   分为两种情况计算：
   
   1. i < P
   
      找到 i 相对于 Po 的对称位置，设为 j。再分为三种情况。
   
      * Len[j] < P - i + 1 如下图所示：
   
        ![](https://pic.leetcode-cn.com/d5340da6d800b5889a1e1991b3e80dbdb9043b2d591d7045927619ffc4344722.jpg)
   
        此时说明，以 j 为中心的回文串一定在以 Po 为中心的回文串的内部。j 和 i 关于位置 Po 对称，并且，由回文串的定义可知，一个回文串反过来还是一个回文串。所以，以 i 为中心的回文串的长度至少和以 j 为中心的回文串的长度一样长，即 Len[i] ≥ Len[j]。由对称性可知，Len[i] = Len[j]。
   
      * Len[j] > P - i + 1 如下图所示：
   
        ![](https://pic.leetcode-cn.com/209f06de99c230d08245f6e793eaf81a8bfc89182adcc9f7fb124dde6495f062.jpg)
   
        此时，Len[i] = P - i + 1
   
        证明如下：由图可知，Len[i] ≥ P - i + 1。
   
        假设 Len[i] > P - i + 1，则 Len[Po] > P - Po +1，即以 Po 为中心的回文子串是可以更长的，这与 Len[Po] 的原值不符，所以假设错误。
   
        综上所述，Len[i] = P - i + 1
   
      * Len[j] = P - i + 1 如下图所示：
   
        ![](https://pic.leetcode-cn.com/fd6789d52451a44c701dc670251a6f9bfd500cb8e5ebee4344d3a45330946d54.jpg)
   
        此时，以 i 为中心的回文串可能会延伸到 P 之外，对于大于 P 的部分，我们还未匹配。因此，要从 P + 1 开始一个一个的匹配，直到发生失配，得出 Len[i] 的值。
   
   2. i >= P 如下图所示：
      ![](https://pic.leetcode-cn.com/a0117736a4e3c964d1002b78e489d5b9d01a76973e207f920a5ee933a07ac4f3.jpg)
      ![](https://pic.leetcode-cn.com/b1953b03be4770f2ac0f38467ea755bf2196bf4e4ffed3ad7f4cbbb6b8c0b9a1.jpg)
      这两种情况下，对于中点为 i 的回文串还一点都没有匹配。因此，只能一个一个的匹配得出 Len[i] 的值。
   
4. 时间复杂度分析

   该算法只有在遇到没有匹配的位置时才进行匹配，已经匹配过的位置不再匹配。因此，对于字符串 T 中的每一个位置，只进行一次匹配，算法整体复杂度为 O(n)，其中 n 为字符串 T 的长度。由于 T 的长度实际上是原字符串 S 的长度的两倍，所以时间复杂度依旧是线性的。

5. 算法实现

   ```C++
   // 返回字符串 s 中的任意一个最长回文子串 
   string longestPalindrome(string s) {
        if(s.length()<=1) return s;
        // 初始化辅助字符串
        string T="#";
        for(int i=0;i<s.length();i++){
            T+=s.substr(i,1)+"#";
        }
        // 初始化辅助数组
        vector<int> Len(T.length());
        Len[0]=1;
        int aimIndex=0,Po=0,P=0; // aimIndex 存放最长回文子串的中心字符在 T 中的下标
        for(int i=1;i<T.length();i++){
            if(i<P){
                int j=Po-i+Po;
                int threshold=P-i+1;
                if(Len[j]<threshold){
                    Len[i]=Len[j];
                }else if(Len[j]>threshold){
                    Len[i]=P-i+1;
                }else if(Len[j]==threshold){
                    int left=i-P+i-1;
                    int right=P+1;
                    while(left>=0&&right<T.length()&&T[left]==T[right]){
                        right++;
                        left--;
                    }
                    Len[i]=right-i;
                }
            }else{
                int left=i-1;
                int right=i+1;
                while(left>=0&&right<T.length()&&T[left]==T[right]){
                    right++;
                    left--;
                }
                Len[i]=right-i;
            }
            aimIndex=Len[i]>=Len[aimIndex]?i:aimIndex;
            if(i+Len[i]-1>P){
                P=i+Len[i]-1;
                Po=i;
            }
        }
        // 从 T 中提取最长回文子串
        string ans="";
        for(int i=aimIndex-Len[aimIndex]+1;i<=aimIndex+Len[aimIndex]-1;i++){
            if(T[i]!='#'){
                ans+=T.substr(i,1);
            }
        }
        return ans;
    }
   ```

   

