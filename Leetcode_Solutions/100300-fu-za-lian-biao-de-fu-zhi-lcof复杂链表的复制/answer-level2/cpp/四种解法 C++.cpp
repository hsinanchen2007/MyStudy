```
// 双O(n)迭代
class Solution {
public:
    Node* copyRandomList(Node* head) {
      unordered_map<Node*, Node*> visited;
      Node* pre = head;
      while(pre!=NULL){
          Node* node = new Node(pre->val);
          visited[pre] = node;
          pre = pre->next;
      }
      pre = head;
      while(pre!=NULL){
          visited[pre]->next = visited[pre->next];
          visited[pre]->random = visited[pre->random];
          pre = pre->next;
      }
      return visited[head];
    }
};
```

```
// O(N),O(1)迭代
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* pre = head;
        while(pre!=NULL){
            Node* copy = new Node(pre->val);
            copy->next = pre->next;
            pre->next = copy;
            pre = copy->next;
      }
        pre = head;
        while(pre!=NULL){
            if(pre->random!=NULL){
                 pre->next->random = pre->random->next;
            }
            pre = pre->next->next;
        }
        pre = head;
        Node* newhead = pre->next;
        Node* newpre = newhead;
        while(pre!=NULL){
            pre->next = pre->next->next;
            pre = pre->next;
            if(newpre->next!=NULL){
                newpre->next = newpre->next->next;
            }
            newpre = newpre->next;
        }
        return newhead;
    }
};
```

```
// dfs解法
class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        if(visited.find(head)!=visited.end()) return visited[head];
        Node* copy = new Node(head->val);
        visited[head]=copy;
        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);
        return copy;
    }
};
```

```
// bfs解法
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*, Node*> visited;
        queue<Node*> que;
        Node* pre = new Node(head->val);
        que.push(pre);
        visited[head] = pre;
        while(!que.empty()){
            Node* temp = que.front();
            que.pop();
            if((temp->next!=NULL) && (visited.find(temp->next)==visited.end())){
                visited[temp->next] = new Node(temp->next->val);
                que.push(temp->next);
            }
            if((temp->random!=NULL) && (visited.find(temp->random)==visited.end())){
                visited[temp->random] = new Node(temp->random->val);
                que.push(temp->random);
            }
            visited[temp]->next = visited[temp->next];
            visited[temp]->random = visited[temp->random];
        }
        return pre;
    }
};
```



