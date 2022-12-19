1.  用dp很容易得到结果，```dp[l][r]```代表从```(l-r)```的最大值，则
很容易用动态规划求出结果；
2. 仔细分析一下，我们用贪心算法即可，每次从开始首尾存在合适的分词，我们则直接进行分词，然后进入递归
3. 国际版的证明参考如下：
[证明参考](https://leetcode.com/problems/longest-chunked-palindrome-decomposition/discuss/350560/JavaC%2B%2BPython-Easy-Greedy-with-Prove)
4.  推理过程解释如下：
![image_1564892108.png](https://pic.leetcode-cn.com/9eb5844cb1e44623b5528d2a5d8c456956c4677903d2ceb59271ebad768b4875-image_1564892108.png)
如果字符串存在首尾长的匹配 字符串 B1 和 B2 ,同时 也存在短的匹配R1 和 R4,则：
```B1 = B2```
```R1 = R4```
我们已知：
```B1 = R1 + S + R2```
```B2 = R3 + S + R4```
因为```R1 = R4```并且```B1 = B2```,则可以推理出：
```R1 = R3```
```R2 = R4```
```R1 = R2 = R3 = R4```
如果按照较长的匹配```B1 B2```来分词，则此时分词数目最多为2，而按照较短的匹配来分词则此时的分词的数目则为6，因此我们应当按照最小的分词来匹配，即可得到最大分词数.

```C++ []
class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();        
        if(text.size() == 0){
            return 0;
        }
        for(int i = 1;i <= n/2; ++i){
           if(text.substr(0,i) == text.substr(n-i,i)){
               return 2 + longestDecomposition(text.substr(i,n-2*i));
           }
        }
        
        return 1;
    }
};
```
```java []
class Solution {
    public int longestDecomposition(String text) {
        int n = text.length();
        for(int i = 1;i <= n/2; ++i){
            if(text.substring(0,i).equals(text.substring(n-i,n))){
                return 2 + longestDecomposition(text.substring(i,n-i));
            }
        }
        return n == 0 ? 0:1;
    }
}
```


