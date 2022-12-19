有的解法用了两个stack，分别记录node和index，这并不合适，因为违背了内存局部性原则，而且两个stack之间要人工保障一致性，容易引入bug。
还有的只用一个stack，但是需要把每个node的所有children一次性入栈，这样会比较浪费内存。还有的解法里不仅仅会浪费内存，而且是先前序遍历再做翻转，这样是多此一举。如果不考虑内存浪费的问题，至少可以在入栈时按children的逆序入栈，并且把parent保留在栈里（位置在children下面），这样在pop时输出val的顺序就是后序顺序了。

```
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector< int > result;
        if( ! root ){
            return result;
        }
        result.reserve( 16 );
        vector< Trace > trace_stack;
        trace_stack.reserve( 8 );
        trace_stack.emplace_back( root );
        while( ! trace_stack.empty() ){
            auto& trace= trace_stack.back();
            auto& children= trace.parent->children;
            if( trace.next_index < children.size() ){
                trace_stack.emplace_back( children[trace.next_index++] );
            }else{
                result.emplace_back( trace.parent->val );
                trace_stack.pop_back();
            }
        }
        return result;
    }
    
private:
    struct Trace
    {
        Node* parent;
        size_t next_index;
        
        inline Trace( Node* p )
        : parent( p ),
          next_index( 0 )
        {
        }
    };
    
};
```
