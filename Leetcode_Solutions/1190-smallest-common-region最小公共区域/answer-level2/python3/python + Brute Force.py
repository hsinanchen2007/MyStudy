```python
class Solution:
    def findSmallestRegion(self, regions: List[List[str]], region1: str, region2: str) -> str:
        # find the nearest parent of two nodes
        #      A
        #     / \
        #    C   B
        #   /    /
        #  D    E
        # record D all parents
        # record E all parents
        # from D to find E
        def get_root(dic):
            for key, value in dic.items():
                if value == 1: return key

        # Time complexity: O(N)
        def traverse(node):
            nonlocal res
            ans = 0
            for child in region_dic[node]:
                ans += traverse(child)
            if node == region1 or node == region2:
                ans += 1
            if ans == 2:
                res = node
                return 0
            return ans

        region_dic = collections.defaultdict(list)
        node_dic = collections.defaultdict(int)
        res = ''
        # Time complexity: O(N)
        for region in regions:
            for i in range(len(region)):
                if i != 0:
                    region_dic[region[0]].append(region[i])
                node_dic[region[i]] += 1
        
        root = get_root(node_dic)
        traverse(root)
        return res

        


```