```
class Solution:
    def findAllConcatenatedWordsInADict(self, words):
        words.sort(key = lambda x: len(x))
        ans = []
        tire = {}
        for word in words:
            if len(word) == 0:
                continue
            if is_concatenated_word(tire, word):
                ans.append(word)
            else:
                trie_add(tire, word)
        return ans


def trie_add(tire, word):
    node = tire
    for char in word:
        node = node.setdefault(char, {})
    node['end'] = True

def is_concatenated_word(p_node, word):
    node = p_node
    if len(word) == 0:
        return True
    for i, char in enumerate(word):
        node = node.get(char, None)
        if node is None:
            return False
        if 'end' in node and is_concatenated_word(p_node, word[i+1:]):
            return True
    return False

```
