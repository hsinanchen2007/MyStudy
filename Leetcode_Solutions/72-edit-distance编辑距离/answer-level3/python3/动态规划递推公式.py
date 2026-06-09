这道题目就是简单考察动态规划的递推公式的求解。

动态规划的存储数组假定为mdst，那么mdst[i][j]就可以表示word1[:i+1]和word2[:j+1]的最短编辑距离。

当word1[pos1]==word2[pos2]时，我们可以认为这个位置是可以不改变的，有mdst[pos1][pos2]=mdst[pos-1][pos2-1]

当word1[pos1]!=word2[pos2]时，这个时候我们需要考虑3种情况：
1、word1[pos1]是不需要的，word2[pos2]和word[:pos1]匹配，有mdst[pos1][pos2]=mdst[pos1-1][pos2]+1(加一是删除操作，删除word1[pos1]))
2、word1[pos1]是不需要的，但是这个位置需要和word2[pos2]匹配，有mdst[pos1][pos2]=mdst[pos1-1][pos2-1]+1(加一是替换操作，将word1[pos1]替换和word2[pos2]相同)
3、word1[pos1]是需要的，但不是和word2[pos2]配对，而是word2[:pos2]匹配，有mdst[pos1][pos2]=mdst[pos1][pos2-1]+1(加一是插入操作，插入和word2[pos2]匹配的字符)

显然，从子问题的求解路线来看，存储数组可以降成一个2*l(word1和word2之间较小值)的数组