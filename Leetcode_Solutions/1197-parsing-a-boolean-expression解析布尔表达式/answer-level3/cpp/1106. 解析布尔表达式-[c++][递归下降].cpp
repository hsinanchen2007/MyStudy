先解析成树，然后递归求解。

```
struct Node {
    Node(char type) : type(type) {}
    char type;
    vector<Node*> children;
};

class Solution {
public:
    bool parseBoolExpr(string expression) {
        int pos = 0;
        Node* root = parse(expression.c_str(), pos);
        return eval(root);
    }
    
    bool eval(Node* root) {
        if (!root) return false;
        if (root->type == 't') return true;
        if (root->type == 'f') return false;
        if (root->type == '&') {
            for (auto child : root->children) {
                if (!eval(child)) return false;
            }
            return true;
        }
        if (root->type == '|') {
            for (auto child : root->children) {
                if (eval(child)) return true;
            }
            return false;
        }
        if (root->type == '!') {
            for (auto child : root->children) {
                if (eval(child)) return false;
            }
            return true;
        }
        return false;
    }
    
    Node* parse(const char* expr, int& pos) {
        if (!expr[pos]) return nullptr;
        auto s = new Node(expr[pos]);
        if (expr[pos] == 't' || expr[pos] == 'f') {
            ++pos;
            return s; 
        }
        ++pos;
        while (expr[pos]) {
            if (expr[pos] == ')') {
                ++pos;
                break;
            }
            if (expr[pos] == '(' || expr[pos] == ',') {
                ++pos;
                continue;
            }   
            auto child = parse(expr, pos);
            if (child) s->children.push_back(child);
        }
        return s;
    }
};
```
