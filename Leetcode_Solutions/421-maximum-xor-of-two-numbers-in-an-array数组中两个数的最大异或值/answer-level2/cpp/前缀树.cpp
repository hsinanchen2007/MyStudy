### 解题思路
利用前缀树进行操作，遍历两次数组，第一次遍历数组建树，第二次遍历数组，每一个元素做一次遍历，从高位开始往后搜索（贪心），注意前缀树实现方法和位运算操作。

### 代码

```cpp
class Solution {
public:
	struct node {
		node* pNextNode[2];
		node() {
			pNextNode[0] = NULL;
			pNextNode[1] = NULL;
		}
		node* GetNextNode(int index) {
			if (pNextNode[index] == NULL) {
				pNextNode[index] = new node();
			}
			return pNextNode[index];
		}
	};
	int GetMaxNum(node* pHeader, int num)
	{
		int results = 0;
		node* currentNode = pHeader;
		for (int i = 31; i >= 0; i--) {
			if (((num >> i) & 1) == 1) {
				if (currentNode->pNextNode[0] != NULL) {
					results += (1 << i);
					currentNode = currentNode->pNextNode[0];
				} else {
					currentNode = currentNode->pNextNode[1];
				}
			} else {
				if (currentNode->pNextNode[1] != NULL) {
					results += (1 << i);
					currentNode = currentNode->pNextNode[1];
				} else {
					currentNode = currentNode->pNextNode[0];
				}
			}
		}
		return results;
	}
    int findMaximumXOR(vector<int>& nums) {
        node* pHeader = new node();
		for (auto num : nums) {
			node* currentNode = pHeader;
			for (int i = 31; i >= 0; i--) {
				currentNode = currentNode->GetNextNode((num >> i) & 1);
			}
		}
		int maxResults = 0;
		for (auto num : nums) {
			maxResults = max(maxResults, GetMaxNum(pHeader, num));
		}
		return maxResults;
    }
};
```