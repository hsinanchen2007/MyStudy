```python
class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        # root, successor
        # replece root with the shortest length
        # Trie Tree
        # if '#' in dic: replace

        def generate_trie_tree(trie, words):
            for word in words:
                dic = trie
                for w in word: dic = dic.setdefault(w, {})
                dic['#'] = word
        
        def get_shortest_root(trie, word):
            dic = trie
            for w in word:
                if '#' in dic:
                    return dic['#']
                elif w not in dic: break
                else: dic = dic[w]
            return word

        trie = {}
        generate_trie_tree(trie, dict)
        word_list = sentence.split(' ')
        for i in range(len(word_list)):
            word_list[i] = get_shortest_root(trie, word_list[i])
        return ' '.join(word_list)
```