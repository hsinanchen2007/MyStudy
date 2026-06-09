```
class Solution:
    def areSentencesSimilarTwo(self, words1: List[str], words2: List[str], pairs: List[List[str]]) -> bool:
        """
           基于对应的关系将无向图构造出来, 形成一个个连通子图, 然后分别判断words1和words2中相对应的单词是否在同一个子图中
        """
        len_words1 = len(words1)
        len_words2 = len(words2)
        if len_words1 != len_words2:
            return False
        
        # 构造无向图
        from collections import defaultdict
        undirected_graph = defaultdict(list)
        for pair in pairs:
            undirected_graph[pair[0]].append(pair[1])
            undirected_graph[pair[1]].append(pair[0])
        
        # 定义一个字典, 记录每个单词对应的组号
        word_group_id = {}
        group_id = 0
        for word in words1:
            group_id += 1
            if word in word_group_id:
                continue

            queue = [word]

            while queue:
                curr_node = queue.pop(0)
                word_group_id[curr_node] = group_id

                next_nodes = undirected_graph.get(curr_node)
                if next_nodes is not None:
                    for node in next_nodes:
                        if node not in word_group_id:
                            queue.append(node)
        
        for word1, word2 in zip(words1, words2):

            if word1 not in word_group_id or word2 not in word_group_id:
                return False

            if word_group_id[word1] != word_group_id[word2]:
                return False  
        
        return True
```
