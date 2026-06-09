```
class Solution
{
public:
    Node* cloneGraph(Node* node)
    {
        if (node == NULL) {
            return NULL;
        }
        vector<Node*> neighbors;
        Node *clone = new Node(node->val, neighbors);
        return cloneGraphBfs(node, clone);
    }

private:
    Node* cloneGraphBfs(Node* node, Node *clone)
    {
        if (node == NULL) {
            return NULL;
        }

        queue<Node*> valStack;
        valStack.push(node);
        valStack.push(clone);
        visited.insert({node, clone});
        while (!valStack.empty()) {
            buildNeighbors(valStack);
        }
        return clone;
    }

    void buildNeighbors(queue<Node *> &valStack)
    {
        Node *current = valStack.front();
        valStack.pop();
        Node *clone = valStack.front();
        valStack.pop();
        for (vector<Node*>::const_iterator iter = current->neighbors.begin();
                iter != current->neighbors.end();
                ++iter) {

            map<Node*, Node*>::const_iterator finder = visited.find(*iter);
            if (finder != visited.end()) {
                clone->neighbors.push_back(finder->second);
                continue;
            }

            vector<Node*> neighbors;
            Node *node = new Node((*iter)->val, neighbors);
            clone->neighbors.push_back(node);
            valStack.push(*iter);
            valStack.push(node);
            visited.insert({*iter, node});
        }
    }

private:
    map<Node*, Node*> visited;
};
```
