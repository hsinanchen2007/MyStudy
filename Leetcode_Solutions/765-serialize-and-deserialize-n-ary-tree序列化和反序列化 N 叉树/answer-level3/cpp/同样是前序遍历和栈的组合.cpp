

```C++ []
class Codec {
public:

    string encode(Node* root)
    {
        if(!root)
            return "";
        
        string res = to_string(root->val);
        
        if(root->children.size() != 0)
        {
            string temp = "";
            for(auto ele : root->children)
            {
                temp += encode(ele) + " ";
            }
            temp.pop_back();
            string temp1 ="[" + temp + "]";
            res = res + temp1;
        }
    
        return  res ;
    }
    
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        
        if(!root)
            return "[]";
        
        string name =  "[" + encode(root) + "]";
        
        // cout << name << endl;
        return name;
    }
    
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.compare(std::string{"[]"}) == 0)
            return nullptr;
        
        stack<Node*> tag;
        
        
        Node* root = new Node(1);
        tag.push(root);
        
        Node* node = nullptr; // 记录,当遇到头结点时压入栈中
        
        for(int i = 1; i < data.length(); i ++)
        {
            if(data[i] == '[')
            {
                tag.push(node);
            }
            else if(data[i] >= '0' && data[i] <= '9')
            {
                string val = "";
                while(data[i] >= '0' && data[i] <= '9')
                {
                    val += data[i];
                    i ++;
                }
                
                int value = std::stoi(val);
                
                i --; // 还原,不然for循环时会出错
                node = new Node(value);
                tag.top()->children.push_back(node);
            }
            else if(data[i] == ' ')
            {
                continue;
            }
            else if(data[i] == ']')
            {
                tag.pop();
            }  
        }
        
        return root->children[0];
    }  
        
};
```
