执行用时 :36 ms, 在所有 C++ 提交中击败了93.17%的用户
内存消耗 :23.6 MB, 在所有 C++ 提交中击败了39.57%的用户

大概思路是建一个单词树用来找词，不用map。
时间复杂度大概是O(字符串长 * 一个单词长)

```
class Solution {
public:
    struct Node {
        int seq = 0; // 当前word使用次数
        int maxseq = 0; // 最大word数
        int cycle = 0; // 当前属于哪一次循环
        bool leaf = false; // 是否是叶子节点，到了叶子节点说明匹配到一个word
        Node* next[26]; // 下一个字母对应的node，范围a - z
    };

    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.size() == 0 || words.size() == 0) return {};

        // 建树
        Node* root = new Node();
        for (const string& word : words)
        {
            Node* cur = root;
            for (const char ch : word)
            {
                int index = ch - 'a';
                if (cur->next[index] == 0)
                {
                    cur->next[index] = new Node();
                }
                cur = cur->next[index];
            }
            ++cur->seq;
            ++cur->maxseq;
            cur->leaf = true;
        }

        // 主逻辑
        vector<int> res; // 返回值
        int wsize = words.size();
        int wlen = words[0].size();
        int ssize = s.size();

        // 假设输入为：
        // "abcdefghijk"
        // ["abc", "efg"]
        // 每次循环处理的对象就是
        // "abc cde fgh ijk"
        // "a bcc def ghi jk"
        // "ab ccd efg hij k"
        // 这样可以涵盖所有的情况
        for (int i = 0; i < wlen; ++i)
        {
            int spos = i, cpos = i, nextcpos = cpos + wlen;
            int mcount = 0; // 匹配到的word个数
            while (cpos < ssize)
            {
                Node* cur = root;
                while (cpos < ssize)
                {
                    int index = s[cpos++] - 'a';
                    cur = cur->next[index];
                    if (!cur) 
                    {
                        // 不是一个有效的word
                        cpos = nextcpos;
                        nextcpos += wlen;
                        break;
                    }
                    if (!cur->leaf) continue;
                    // 已经到了叶子节点
                    nextcpos += wlen;
                    ++mcount; // 完成一次匹配
                    if (cur->cycle < i)
                    {
                        // 每个最外层的for循环都需要把节点中的计数器清空
                        cur->seq = cur->maxseq;
                        cur->cycle = i;
                    }
                    // 计数器递减，说明已匹配到了一个word
                    // 如果小于0说明这个word在之前的匹配中已经全部用完
                    // 先暂时不管，让spos追上来
                    if (--cur->seq < 0) break;
                    // 这个判断一定要放在seq < 0之前
                    // 因为重复匹配的时候可能恰好等于了words个数
                    if (mcount == wsize) res.push_back(spos);
                    cur = root;
                }

                // spos追赶cpos
                cur = root;
                while (spos < cpos && spos < ssize)
                {
                    int index = s[spos++] - 'a';
                    cur = cur->next[index];
                    if (!cur)
                    {
                        cur = root;
                        continue;
                    }
                    if (!cur->leaf) continue;
                    // 追赶的过程中把之前匹配到的单词排除出去
                    --mcount;
                    if (++cur->seq == 0)
                    {
                        // 对应之前的seq < 0
                        // 说明把和最后一个词重复的词已经排除在外
                        if (mcount == wsize) res.push_back(spos);
                        break;
                    }
                    cur = root;
                }
            }
        }
        return res;
    }
};
```
