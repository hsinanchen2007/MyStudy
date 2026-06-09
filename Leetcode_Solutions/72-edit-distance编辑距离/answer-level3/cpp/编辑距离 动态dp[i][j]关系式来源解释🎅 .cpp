// # 对于word2 = "ros" 变成word1 = "horse"
// ### 🎅觉得其他的讲的🎅没明白，于是自己编一个，如有出错希望指出 👊
// ## ps：**🎅是应届**想要找工作，希望哪位**带恶🕵️‍♀️**帮帮🎅 
// #### 看到联系🎅 wx wrj23333 邮箱 lenterwong975@gmail.com **🎅虽然从不🙏人，但🎅给你倒立磕头了** 🎅🤸‍♀️

// #### **ps: dp[i][j] 就是以word1[i] 与 word2[j] 转换的最小数。 本文中的word2[j-1]可能是word2的前0~j-1的字符串也可能是第word2的第j个字符，🎅采用加密童话，请自行解码**
// # 第一个话题：
// ### **首先！ 如果存在插入或替换后又删除同一个字符（2次），那他就不是最小的操作数，因为可以不插入（0 次）或者直接删除（1次）同样结果 ）还有其他情况,替换后又被替换——可以直接被替换为结果，等等;**
// # 对于最小操作数、word2原有/后添加的任意一个字符不能被操作两次，因为两次操作可以被一次操作替代

// # 其次对于变化的这个过程，所有的一次操作顺序（在最小操作数）是不是可以任意的。
// 2. ![w2.png](https://pic.leetcode-cn.com/253e29845a461b4bbe6e06e1e868ab9c3d9690d11a0a9d9597a98f82a9e7a28e-w2.png)

// ![加.PNG](https://pic.leetcode-cn.com/d90925386d6d8cbd6c4f5b73e39aca0537e8f269992d02a100e092bb19ce7ce6-%E5%8A%A0.PNG)
// # 比如最后的e可以在最后添加，也可在之前任意时刻添加，最后存在就不影响结果；
//  ![44a8cab9c6d156ce688ebcb0d935ada7.jpg](https://pic.leetcode-cn.com/3993185bbc7c4a80a03dfa0650ee26495d887ab51a9a1b06ef07fc5d80189d92-44a8cab9c6d156ce688ebcb0d935ada7.jpg)
// # 那么只要保证某个字符在整个过程被执行操作，结果不变（没有次序关系，上面说的）；因此我们可以把某一个步骤提到或！看作 ！最后或其他位置——达到我们的逻辑式；这样我们就可以把word2弄出word[i]的来源的操作看作最后。(抽象概念)
// # 谈下一话题 ： 正文
// # word1末尾这个带哥是怎么来滴
// ![96299430b928246f819d2e0bb92a5510.jpeg](https://pic.leetcode-cn.com/77881dfea6d6346dd139312ffbaaf69c0e49a82a855576e559344daa905fc65e-96299430b928246f819d2e0bb92a5510.jpeg)
// # 他word1[i]只有可能由以下几种情况
// # 1： 他是 word2原本字符替换或跳过来滴。
// # 2： 他是无中生有（ 插入 ）而来滴。
// # 要不然是原先存在的，要不然是被替换或者插入而来

// # 对于以上两种情况下
// ![es.PNG](https://pic.leetcode-cn.com/c5aeb4a73eae3e8028f8e322741079f27dd626061a333fc9cde0dad4de23dac9-es.PNG)
// # 在上面两种情况下，word1[i]，跟对面w2[j]有无瓜葛？！！！关键部分！！！

// # 一. word1[i]若跟word2无关(不是word2的原字符)情况下:
// ![2.PNG](https://pic.leetcode-cn.com/1f1ef9f1bd2b852cfdc0acb814755668fc4ca3884f7f7939cfc48beacf7b0f32-2.PNG)
// # 除去插入操作其余操作可以将word2->word1[0~i-1]; 即为dp[i-1][j];

// # 二、若word1[i]与word2有关（是原字符）下：
// # **1、若word1[i]是word[j]原字符替换，跳过则**
// ![3.PNG](https://pic.leetcode-cn.com/645b47122ff9c9b4439eba0ca74e2b1a3ebb34e25c76178088944386b227add0-3.PNG)
// # 除去替换/跳过操作其余操作可以将word2[0-j-1]->word1[0~i-1] : 即为dp[i-1][j-1]; 
// # **2.若word1[i]是word2[0~j-1]中的原字符**
// ![4.PNG](https://pic.leetcode-cn.com/1bcc40c82b43e785e902985a4f6a54738001d5ad7fa6ef256c0863dc584559d7-4.PNG)
// # 除去删除word2[j]的操作其余操作可以将word2[0~j-1]->word1 : 既为dp[i][j-1];
// # 以上只是dp[i][j]的可能值，在可能值中最小的及为最小值
// ```
代码块 
class Solution {
public:
    int min ( int a, int b, int c ){
        if ( a < b ){
            return c < a ? c : a;
        }else{
            return c < b ? c : b;
        }
    }
    int minDistance(string word1, string word2) {
        if ( word1.size() == 0 && word2.size() == 0 ) return 0;
        vector<vector<int>> DP( word1.size() + 1, vector<int> ( word2.size() + 1, 0 ) );
        for( int i = 0; i < word1.size() + 1 ; i++ ) DP[i][0] = i;
        for( int j = 0; j < word2.size() + 1 ; j++ ) DP[0][j] = j; 
        for( int i = 1; i < word1.size() + 1; i++ ){
            for( int j = 1; j < word2.size() + 1; j++ ){
                DP[i][j] = min ( DP[i-1][j], DP[i][j - 1], DP[i-1][j - 1] - 1 + ( word1[i-1] == word2[j - 1] ? 0 : 1 ) ) + 1; 
            }
        }
        return DP[word1.size()][word2.size()];
    }
};