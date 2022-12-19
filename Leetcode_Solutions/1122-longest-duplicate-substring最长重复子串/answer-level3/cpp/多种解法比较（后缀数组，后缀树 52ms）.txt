首先赞一下官方题解，如果有长度为 K 的重复子串，则必有长度为 1,2,..,K 的重复子串，因此可以用二分查找。
用哈希编码可以将查找长度为 K 的子串的时间复杂度降低到 O(N), 则总共的时间复杂度为 O(NlogN).

如果不看官方题解，这道题确实比较难，而传统的方法有后缀数组，后缀树，后缀向量机等。
（如果用纯暴力法，则当字符串长度 > 30000 左右时会超时，时间复杂度 O(N^2)).

# 1) 后缀数组：
网上的资料比较多，关键需要理解的部分：
1’ 如何在每步进行**基数排序**。假设现在知道一组数字序列(X)的高位数和低位数，如何进行排序？
  以自己的理解（可能有更优的方案）：
  1) 首先设一个数组A存放各个高位数出现的次数，然后再加起来，得到在每个高位数之前总共有多少数。
  2) 然后设一个数组B存放低位数的次数，也加起来。
  3) 设第三个数组C，存放原序列 X **按照低位**从小到大的顺序排列 的数组. 数组 C 可以借助数组 B 得出。
  4) 然后遍历数组 C. C[i] 的高位决定了该数字的排名**至少**是多少，而由于C是按低位从小到达排列，故在高位相同时，**先到的数排名 <= 后到的数排名。**
  5) 时间复杂度: 得出数组 A、B、C 和遍历数组 C 的复杂度都是 O(N), 故总的复杂度是 O(N).


2’ 为什么有公式 **H[k] >= H[k - 1] - 1**?
  1) 首先分析定义（H[i] = height[rank[i]]）。设输入的数组为 S, S[i:] 为S从i开始的子串，LCP(x,y) 为 x,y 的最长公共前缀，则 H[i] = height[rank[i]] = LCP(S[sa[rank[i]]:], S[sa[rank[i] - 1):]]) = LCP(S[i:], S[sa[rank[i] - 1):]])。
  2) 从上面很容易看出 **H[k]** 实际上是 **第 k 个后缀** 与 **排名在它之前的后缀** 的 最长公共子串。
  3) 容易验证，当 k > 0 且 rank[k] > 0 (这里所有的排序和起始点都从 0 开始) 时，如果有后缀与排名在前的后缀的公共前缀长度为 K, 这个后缀的后缀，与排名在前的后缀的公共前缀长度至少为 K - 1。
  4) 原因: 以 "mississippi" 为例，其后缀 “**issi**ssippi” 与排名在前的后缀 "**issi**ppi" 有公共子串 "issi"。 则在后缀“**ssi**ssippi” 之前必定有 “**ssi**ppi”，因为去掉首字母“i”并不会影响两个字符串的相对排名次序；假设有其他字符串插入到 "ssissippi" 和 "ssippi" 的之间，则其也必有公共前缀"ssi"。其他情况类似，故可证明.

# 代码：
```c
class Solution {
public:
    string longestDupSubstring(string S) {
        // 需要放一个比任何字母都小的值在后面，否则若以最小字母'aaa'等结尾，会被认为相同
		S.push_back('a' - 1);

		int *sa = new int[S.size()];
		int *rank = new int[S.size()];
		int *count = new int[max((size_t)28, S.size() + 1)];
		int *rcount = new int[S.size() + 1];
		int *idxsort = new int[S.size()];
		int *lastvalue = new int[S.size()];

		memset(count, 0, max((size_t)28, S.size() + 1) * sizeof(int));

		// 首先对首字母进行排序
		for (char c : S)
			count[c - 'a' + 2]++;

		for (int i = 1; i < max((size_t)28, S.size() + 1); ++i)
		{
			count[i] += count[i - 1];
		}

		for (int i = 0; i < S.size(); ++i)
		{
			rank[i] = count[S[i] - 'a' + 1];
		}

#define NEXT_VALUE(i,k) (((i) + (k)) < S.size() ? rank[(i) + (k)] : 0)

		// 然后利用倍增法扩展
		for (int k = 1; k < S.size(); k *= 2)
		{
			// 更新 count 和 rcount(劣后数值的count) 数组
			memset(count, 0, (S.size() + 1) * sizeof(int));
			memset(rcount, 0, (S.size() + 1) * sizeof(int));
			for (int i = 0; i < S.size(); ++i)
			{
				count[rank[i] + 1]++;
				rcount[NEXT_VALUE(i, k) + 1]++;
			}

			for (int i = 1; i < S.size(); ++i)
			{
				count[i] += count[i - 1];
				rcount[i] += rcount[i - 1];
			}

			// 然后根据劣后数值排序
			for (int i = 0; i < S.size(); ++i)
			{
				idxsort[rcount[NEXT_VALUE(i,k)]++] = i;
			}

			// 然后, 求出新的 rank 值
			for (int m = 0; m < S.size(); ++m)
			{
				lastvalue[m] = -1;
				rcount[m] = count[m];
			}

			int*& newrank = sa;

			for (int m = 0; m < S.size(); ++m)
			{
				int i = idxsort[m];
				if (NEXT_VALUE(i, k) != lastvalue[rank[i]])
				{
					if (lastvalue[rank[i]] != -1)
						count[rank[i]] = rcount[rank[i]];
					lastvalue[rank[i]] = NEXT_VALUE(i, k);
				}
				newrank[i] = count[rank[i]];
				++rcount[rank[i]];
			}

			for (int i = 0; i < S.size(); ++i)
			{
				rank[i] = newrank[i];
			}
		}

		// 最后，求出sa数组
		for (int i = 0; i < S.size(); ++i)
		{
			sa[rank[i]] = i;
		}

		// 要求最长重复，需要求出 H 数组（H[i] = suffix(i) 与排名在前的 suffix 的最长公共部分)
		// 根据定义，H[i] = lcp(S[i:], S[sa(rank(i) - 1):]) (rank(i) >= 1)
		// H[i] 有性质：当 i > 0 且 suffix(i) 的排名不在第一位时，H[i] >= H[i - 1] - 1.
		// 原因是：若某个后缀有长度为 k 的公共部分，则它的后缀串至少必有长度为 k - 1 的公共部分。
		int lastH = 0, maxH = 0, maxi = 0;
		for (int i = 0; i < S.size(); ++i)
		{
			if (rank[i] == 0) lastH = 0;
			else
			{
				int k = max(0, lastH - 1);
				while (S[i + k] == S[sa[rank[i] - 1] + k]) ++k;
				if (k > maxH)
				{
					maxH = k;
					maxi = i;
				}
				lastH = k;
			}
		}

        return S.substr(maxi,maxH);
    }
};
```
执行效率：
![image.png](https://pic.leetcode-cn.com/e0ef9e94279f9f358b9fa790b0840e3ad9bfcbbbdc58b156548c6ed6c98b0d50-image.png)


# 2）后缀树：
后缀树相当于“终极大招”，可以在线性时间 O(N) 内解决该问题，但是编程更为复杂。
学习后缀树推荐看  http://stackoverflow.com/questions/9452701/ukkonens-suffix-tree-algorithm-in-plain-english。
要把上面链接里的所有的答案都看一遍再尝试实现。

# 代码:
```c
class Solution {
public:
class Edge;
	class Node
	{
	public:
		Edge *e;
		int l;
		Node* suffix;
	};

	class Edge
	{
	public:
		int s, l;
		Edge *ne;
		Node *n;
	};

	Node *nodepool;
	Edge *edgepool;
	int nodepoolIdx, edgepoolIdx;

	Node* getNewNode()
	{
		nodepool[nodepoolIdx].e = NULL;
		nodepool[nodepoolIdx].suffix = NULL;
		return &nodepool[nodepoolIdx++];
	}

	Edge* getNewEdge()
	{
		edgepool[edgepoolIdx].n = NULL;
		edgepool[edgepoolIdx].ne = NULL;
		return &edgepool[edgepoolIdx++];
	}

    string longestDupSubstring(string S) {
        S.push_back('$');
		nodepoolIdx = edgepoolIdx = 0;
		nodepool = new Node[S.size()];
		edgepool = new Edge[2 * S.size()];

		Node rootbase;
		rootbase.e = NULL;
		rootbase.suffix = &rootbase;
		rootbase.l = 0;

		Node *root = &rootbase;

		Node* currNode = root;
		Node* prevNode = NULL;
		char* currEdgeChar = 0;
		Edge* currEdge = NULL;
		int offset = 0;
		int remainder = 0;

        int maxDupLen = 0;
        int maxIndex = 0;

		for (int i = 0; i < S.size(); ++i)
		{
			++remainder;
			prevNode = NULL;

			if (!currEdge)
			{
				// 确定当前边（等价于确定首字母）
				currEdgeChar = &S[i];

				// 根据首字母找到边
				for (currEdge = currNode->e; 
					currEdge != NULL && S[currEdge->s] != *currEdgeChar; 
					currEdge = currEdge->ne
				);

				// 初始偏移量 = 0
				offset = 0;
			}
			if (currEdge && S[i] == S[currEdge->s + offset])
			{
				if (offset == currEdge->l - 1)
				{
					// 行进到下一个点
					currNode = currEdge->n;
					currEdge = NULL;
				}
				else
					++offset;
			}
			else // 字母不匹配的情况：1) 当前边 + offset != 当前字母; 
				 // 2) 当前节点没有 首字母 == 当前字母 的边。
			{
				prevNode = NULL;
				Node *inSertedNode = NULL;
				for(;;)
				{
					// split 阶段
					if (currEdge == NULL)
					{
						// 无需建立新的节点，只需建立新的边
						Edge *edge = getNewEdge();
						edge->s = i;
						edge->l = S.size() - edge->s;
						edge->ne = currNode->e;
						currNode->e = edge;

						// 只要建立一个新的分支，就需要维护后缀链表
						if (prevNode != NULL)
						{
							prevNode->suffix = currNode;
						}
						prevNode = currNode;
					}
					else
					{
						// 两个节点之间插入一个新的节点，并添加新的边
						Node* newNode = getNewNode();
						Edge* edge1 = getNewEdge();
						Edge* edge2 = getNewEdge();
						edge1->s = currEdge->s + offset;
						edge1->l = currEdge->l - offset;
						edge1->n = currEdge->n;
						currEdge->l = offset; // s + offset 不属于当前字符串
						edge2->s = i;
						edge2->l = S.size() - edge2->s;
						edge1->ne = edge2;
						newNode->e = edge1;
						currEdge->n = newNode;
						newNode->l = currNode->l + offset;

                        if(newNode->l > maxDupLen)
                        {
                            maxIndex = i - 1;
                            maxDupLen = newNode->l;
                        }

						// 维护后缀链表：建立（上个节点）指向其后缀（当前节点）的指针
						if (prevNode != NULL)
						{
							prevNode->suffix = newNode;
						}
						prevNode = newNode;
					}

					if (currNode == root)
					{
						// 如果当前节点为根节点，则需要将生长点前移。
						if (offset == 0)
							currEdge = NULL;
						else
							--offset;
					}
					
					// 处理完成一个后缀
					--remainder;
					if (remainder == 0)
						break;

					// 顺着后缀链表更新当前点
					currNode = currNode->suffix;

					// 如果是在root节点上操作，则需要比较的首字母 = 当前后缀的首字母。
					if (currNode == root)
						currEdgeChar = &S[i - remainder + 1];
					
					// 根据首字母找到下一个边
					for (currEdge = currNode->e; 
						currEdge != NULL && S[currEdge->s] != *currEdgeChar;
						currEdge = currEdge->ne
					);

					// 考虑 offset > 长度 的情况，沿着树向下搜索，
					// 找到 “最接近” 当前字符串的点 (在论文中称为 canonize 阶段）
					while (currEdge && offset >= currEdge->l)
					{

						offset -= currEdge->l;
						currEdgeChar += currEdge->l;
						currNode = currEdge->n;
						for (currEdge = currNode->e; 
							currEdge != NULL && S[currEdge->s] != *currEdgeChar; 
							currEdge = currEdge->ne
						);
					}

					// 测试当前后缀是否已经包含，则后移生长点，且后面的后缀都不考虑
					if (currEdge && S[i] == S[currEdge->s + offset])
					{
						// 此时建立最后一个后缀链接
						if (prevNode != NULL)
							prevNode->suffix = currNode;

						// 已经包含，则后移生长点，并跳到下一步
						if (offset == currEdge->l - 1)
						{
							// 行进到下一个点
							currNode = currEdge->n;
							currEdge = NULL;
						}
						else
							++offset;

						break;
					}
				}
			}	
		}

        return S.substr(maxIndex - maxDupLen + 1, maxDupLen);
    }
};
```
执行效率：
![image.png](https://pic.leetcode-cn.com/5f8dec4aadd8856b8e31852fcf506408f10f883ba7eaaffc6612164fbb4d7588-image.png)

# 3) 暴力法：
相当于一个字符串在另一个字符串上滑动，如果有上下相等的字符串则记录长度，取最长。容易证明，“最长重复子串”一定会在路上“相遇”。
时间复杂度 O(N^2).
暴力法对新手友好，也能满足一般需求，但是不能满足“变态”的需求。（如长度 > 30000 的字符串）。

# 代码：
```c
class Solution {
public:
    string longestDupSubstring(string S) {
        int maxl = 0, maxi = 0;
        for(int i = 1; i < S.size(); ++i)
        {
            int l = 0, j;
            for(j = 0; j < S.size() - i; ++j)
            {
                if(S[j] == S[j + i]) ++l;
                else
                {
                    if(l > maxl)
                        maxl = l, maxi = j - 1;
                    l = 0;
                }
            }
            if(l > maxl)
                maxl = l,maxi = j - 1;
        }
        return S.substr(maxi - maxl + 1, maxl);
    }
};
```

执行效率：
卡在了一个长度 = 100,000 的字符串上。（文本大小约 100 KB）

