![QQ图片20191113022023.png](https://pic.leetcode-cn.com/b9fd3e638c06ec44c9889e80adea9b1fa0a21fc013a782663bf706a763a6d16e-QQ%E5%9B%BE%E7%89%8720191113022023.png)

以上是报错，烦请好心人帮我看看，谢谢！

class Solution {
public:
    Node* cloneGraph(Node* node) {
      if(node == NULL) 
		  return NULL;
      
      queue<pair<Node*, Node*> >que;   
	  Node* root = new Node();
	  vector<Node*> vec;
	  root->val = node->val;
	  root->neighbors = vec;
      que.push(make_pair(root, node));
      unordered_map<int, Node*> traversed;    //已经将其加入其邻接节点邻居的节点
      unordered_map<int, Node*> created;      //已经创建过的节点
      created.insert(make_pair(root->val, root));
      vector<int> cre;
      vector<int> tra;
      cre.push_back(root->val);
      while(que.size() != 0) {
        vector<Node*> temp;
        pair<Node*, Node*> current = que.front();
       
        que.pop();
        if(traversed.find(current.first->val) != traversed.end()) {
         
          continue;
        }
        traversed.insert(make_pair(current.first->val, current.first));
        tra.push_back(current.first->val);
        //遍历该节点的邻居，并将该节点加入其邻居的邻居节点数组
        for(int i = 0; i < (current.second->neighbors).size(); i++) {
          Node* tmpnode;
          vector<Node*> vec;
          auto tmp = created.find(current.second->neighbors[i]->val);
          if(tmp == created.end()) {
            vec.push_back(current.first);
            tmpnode = new Node(current.second->neighbors[i]->val, vec);
            created.insert(make_pair(tmpnode->val, tmpnode));
            cre.push_back(tmpnode->val);
          }
          else {
            tmpnode = tmp->second;
            tmpnode->neighbors.push_back(current.first);
            sort((tmpnode->neighbors).begin(), (tmpnode->neighbors).end(), cmp);
          }
          que.push(make_pair(tmpnode, current.second->neighbors[i]));
        }
      }

      //测试
      Node* test = root;
      cout << test -> val << " ";
      cout << test->neighbors[0]->val << " ";           
      cout << test->neighbors[1]->val << " " << endl; 

      test = root->neighbors[0];
      cout << test -> val << " ";
      cout << test->neighbors[0]->val << " ";           //1
      cout << test->neighbors[1]->val << " " << endl;  //3
      
      test = root-> neighbors[1];
      cout << test -> val << " ";
      cout << test->neighbors[0]->val << " ";           
      cout << test->neighbors[1]->val << " " << endl;  
      
      test = root->neighbors[0]->neighbors[1];
      cout << test -> val << " ";
      cout << test->neighbors[0]->val << " ";           
      cout << test->neighbors[1]->val << " "  << endl; 
      
      return root;
    }
};
