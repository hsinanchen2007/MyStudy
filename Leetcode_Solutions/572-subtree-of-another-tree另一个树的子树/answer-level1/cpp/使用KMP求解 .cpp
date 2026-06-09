+ 执行用时 :24 ms, 在所有 C++ 提交中击败了97.89%的用户
+ 内存消耗 :33 MB, 在所有 C++ 提交中击败了5.21%的用户

最基本的方法是采用递归遍历。复杂度是O(N*M)。但是可以使用KMP方法，来求解。不过整个过程比较麻烦。

+ 将树序列化，我采用的是前序遍历。尝试过层次遍历，会发现做不到。
+ 建立KMP的NEXT表
+ 使用KMP算法

```cpp
class Solution { 
public:
bool isSubtree(TreeNode* s, TreeNode* t) { 
    if(s ==nullptr && t==nullptr) return true;
    if(s ==nullptr || t==nullptr) return false;

    // 节点的值都是int类型
    std::vector<int> s_ser;
    std::vector<int> t_ser;

    __serialization(s, s_ser);
    __serialization(t, t_ser);

    return  __KMP(s_ser, t_ser);
}
// 采用先序遍历
// 注意，在序列化时，占位符如果选择0之类的数字，容易和节点值混合，我尝试过为0，失败了

void __serialization(TreeNode* root, std::vector<int>& str) { 
    std::stack<TreeNode*> path_;
    str.push_back(root->val);

    while(true) { 
        while(root) { 
            path_.push(root->right);

            root = root->left;
            if(root) 
            {
                str.push_back(root->val);
            }
            else 
            {
                str.push_back(' '); // 会发生隐式转换为int
            }    
        }
        if(path_.empty()) break;
        root = path_.top(); path_.pop();
        if(root) 
        {
            str.push_back(root->val);
        }
        else 
        {
            str.push_back(' ');
        }    
    }
}

bool __KMP(std::vector<int>& s, std::vector<int>& t) { 
    int* next = __buildNext(t);
    int n = s.size(), m =t.size();
    int s_ids = 0, t_ids=0;

    while(s_ids < n && t_ids < m) { 
        if(t_ids < 0 || s[s_ids] == t[t_ids]) 
        {
            ++t_ids;
            ++s_ids;
        }
        else  
        { 
            t_ids = next[t_ids]; 
        }
    }

    delete[] next;
    
    return t_ids == m ? true : false;
}

int* __buildNext(std::vector<int>& t) {
    int len = t.size();
    int* next  = new int[len];  // 为了加速，这里可以有 __KMP算法传入，在栈上分配比堆上更快

    int pre = next[0] = -1; // 用来标记每个字符的信息
    int cur = 0;
    
    while(cur < len-1) 
    { 
        if(pre < 0 ||  t[pre] == t[cur]) {  // 匹配
            ++cur;
            ++pre;
            next[cur] = pre;
        }
        else {
            pre = next[pre];
        }
    }

    return next;
}
};


```