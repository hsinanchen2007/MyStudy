```
/*
二叉查找树/二叉排序树/二叉搜索树，对于一个node，左子树均小于等于node，右子树均大于等于node，
中序遍历是排序好的的数据，对于二叉排序树有插入一个元素BST_insert和查找一个元素BST_search的操作
想法：将二叉排序树前序遍历存储到vector，再重新插入元素构造就可以得到和原来一模一样的树，
这里一定是前序遍历，因为中左右，还有插入元素算法的原理，才是先从root开始
本题思想：
编码：先画一个二叉搜索树，然后前序遍历形式，将整型数据转化为字符串并且用特殊符号连接。比如8#3#1#6#
解码：根据分隔符，将数字拆分出来，然后第一个数字作为root，在依次插入即可
补充整形转字符串：
对于12345，可以利用对10取余，可以逐个的将个位取出，然后添加到str中，直到该数字%10为0，最后str反转即可
补充字符串转数字：
对于123#456#，val=0，for循环i，val = val*10+str[i]-'0'，遇到#，打印val并且val清0
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void change_int_to_string(int val, std::string &str_val){
    std::string tmp;
    while(val){//val每次循环都/10，因此循环val
        tmp += val % 10 + '0';//在字符0上作偏移
        val = val / 10;
    }//遍历val，每次将val个位转换为字符，添加到tmp尾部
    for(int i = tmp.length() - 1; i >= 0; i--){
        str_val += tmp[i];
    }//逆序
    str_val += '#';//转换每个数后加一个#
}

void BST_preorder(TreeNode *node, std::string &data){
    if(!node){
        return;
    } //前序遍历递归跳出
    std::string str_val;
    change_int_to_string(node->val, str_val);
    data += str_val;//将每个节点转换为字符然后添加到data
    BST_preorder(node->left, data);
    BST_preorder(node->right, data);
}

void BST_insert(TreeNode *node, TreeNode *insert_node){//用来对于一个根，插入元素
	if (insert_node->val < node->val){//新元素小于根
		if (node->left){//如果有左子树，递归插入
			BST_insert(node->left, insert_node);
		}
		else{//无左子树，插在左边
			node->left = insert_node;
		}
	}
	else{//否则新元素大于等于根
		if (node->right){//如果有右子树，递归插入
			BST_insert(node->right, insert_node);
		}
		else{//否则插在右
			node->right = insert_node;
		}
	}
}

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string data;//解码到data
        BST_preorder(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0){
            return NULL;
        }//这是处理特殊情况，空树
        std::vector<TreeNode *> node_vec;
        int val = 0;//初始化node数组和val值
        for(int i = 0; i < data.length(); i++){//循环data提取所有节点值
            if(data[i] == '#'){//遇到#说明已经提取好了一个节点
                node_vec.push_back(new TreeNode(val));
                //这里不用delete，在类外delete析构即可，因为有root
                val = 0;//node数组push并且val清0用于下次提取
            }
            else{
                val = val * 10 + data[i] - '0';//否则当前继续计算当前数字值
            }
        }
        for(int i = 1; i < node_vec.size(); i++){
            //还原二叉排序树，这里注意从1开始因为用到BST_insert
            BST_insert(node_vec[0], node_vec[i]);
        }
        return node_vec[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```