### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
		vector<Node*> v,vTemplate;
		Node *p = head;
		multimap<Node*, int> hash;
		int count = 0;
		while (p!=NULL) {
			Node *pp = new Node(p->val);
			v.push_back(pp);
			hash.insert(pair<Node*, int>(p,count));
			count++;
			p = p->next;
		}
		Node *pp = head,*ppp=v[0];
		for (int i = 0; i < v.size()-1;i++) {
			v[i]->next = v[i + 1];
			Node *temp= pp->random;
			multimap<Node*, int>::iterator it = hash.find(temp);
			if (it!=hash.end()) {
				v[i]->random = v[it->second];
			}
			else v[i]->random = NULL;
			pp = pp->next;

		}
		int n = v.size();
		Node *temp = pp->random;
		multimap<Node*, int>::iterator it = hash.find(temp);
		if (it != hash.end()) {
			v[n-1]->random = v[it->second];
		}
		else v[n -1]->random = NULL;
		//v[n - 1]->random = pp->random;
		return ppp;
	}
};

```