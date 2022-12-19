## DFS实现组合
&emsp;&emsp;读懂题意之后可以发现，实际上该题是计算words的（排列）组合子集，要求该组合中字符出现的次数小于等于letters中出现的次数，计算其相应的总分，取总分数最大值即为该题答案。

&emsp;&emsp;常规的实现排列组合的方式是使用DFS，或者说递归/回溯的方式。
1. 如果是实现组合的话，定义函数`dfs(int k)`，表示上一步刚使用了第`k`个元素。因为组合不需要考虑元素的顺序，函数实现应当从第`k+1`个元素开始，考虑是否将其加入到组合当中。递归的每一层即为一个组合。
2. 如果是实现排列的话，则定义函数`dfs(bool[] used)`，`used`数组代表迭代到当前层次时，哪些元素被使用了，哪些元素还未被使用。区别于组合的实现，排列的实现每次都是从第0个元素开始考虑是否将其加入排列。同样的，递归的每一层即为一个排列。
3. 排列和组合有一个共同点，那就是在将某个元素加入到排列/组合之前，需要先更新状态集，然后才能迭代下一个元素；同时，回溯的时候，需要将加入的元素移出，还原状态集。

&emsp;&emsp;其实，组合也可以尝试使用BFS来实现，只是需要将状态集压入队列，比如说这一题，需要将当前单词(word)的序号(index)，和当前的分数和(nSumScore)，以及当前剩余字母作为一个状态集压入队列。空间消耗太大，得不偿失。

```
class Solution {
public:
	int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
		vector<int> letterCount(26, 0);
		for (size_t i = 0; i < letters.size(); ++i)
			++letterCount[letters[i] - 'a'];

		int nMaxScore = 0;
		calcMaxScoreWords(words, letterCount, score, -1, 0, nMaxScore);
		return nMaxScore;
	}

	bool canFormWord(vector<int>& letters, string& word) {
		vector<int> letterCount(26, 0);
		for (size_t i = 0; i < word.size(); ++i)
			++letterCount[word[i] - 'a'];

		for (size_t i = 0; i < word.size(); ++i) {
			int idx = word[i] - 'a';
			if (letters[idx] < letterCount[idx])
				return false;
		}

		return true;
	}

	void calcMaxScoreWords(
		vector<string>& words,
		vector<int>& letters,
		vector<int>& score,
		int k,
		int nSumScore,
		int& nMaxScore)
	{
		for (int i = k + 1; i < words.size(); ++i) {
			string& word = words[i];
			if (canFormWord(letters, word)) {
				for (int j = 0; j < word.size(); ++j) {
					int idx = word[j] - 'a';
					nSumScore += score[idx];
					--letters[idx];
				}

				nMaxScore = max(nMaxScore, nSumScore);
				calcMaxScoreWords(words, letters, score, i, nSumScore, nMaxScore);

				// Restore
				for (int j = 0; j < word.size(); ++j) {
					int idx = word[j] - 'a';
					nSumScore -= score[idx];
					++letters[idx];
				}
			}
		}
	}
};
```
我果真不适合写题解，写文章啊！