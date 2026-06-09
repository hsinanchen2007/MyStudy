### 解题思路

![image.png](https://pic.leetcode-cn.com/0ba5de47b36beb0275cc4b29d8300c8de6cf68356228b19f64c6236054945e21-image.png)

### 代码

```cpp

class Codec {
public:
    void encodetree(Node *p,string *res){
        *res+=to_string(p->val);
        *res+=' ';
        if(!p->children.empty()){
        *res+='[';
       for(auto i:p->children){
           encodetree(i,  res);
        }
       *res+=']';
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(Node* root) {
       
        string res;
        res.clear();
        if(root==NULL) return res;
        encodetree(root,&res);
        return res;
    }


    void decodetree(Node *res,string *data,int *i){
        //count用来标记该层递归是否还有孩子。通过对称的'['与']'来判断。
        int count=1;
          string temp;
             //由于在上一层递归中已经读过‘[’,所以紧接着肯定是val，直接获取。
                while( *i<data->length()&&(*data)[*i]>='0'&&(*data)[*i]<='9'){
                    temp+=(*data)[*i];
                    (*i)++;
                }
                res->val=stoi(temp);
                (*i)++;
                //如果没有孩子直接返回上一层。
                if( *i>=data->length()||(*data)[*i]!='['){return;}
                (*i)++;

       while(count>0){     //找孩子

            if( *i<data->length()&&((*data)[*i]>='0'&&(*data)[*i]<='9')){
                res->children.push_back(new Node);
                //找到孩子向下递归
                decodetree(res->children.back(),data,i);
            }
            //找完孩子重置count结束本次递归。
            if( *i<data->length()&&(*data)[*i]==']'){
                count--;
                (*i)++;
            }
   
            if(*i<data->length()&&(*data)[*i]==' '){(*i)++;}
       }
       
    }
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
         Node* res;
         res=NULL;
         int i=0;
        if(data.length()==0) return res;
        res=new Node;
         decodetree(res,&data,&i);
         return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```