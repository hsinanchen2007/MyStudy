1. 构建一个前缀树，只有两个节点，left right分别代表有0,1孩子节点，每一个num按二进制形式从高位到低位插入前缀树

2. 所有的数据插入前缀树之后，找到第一个分叉点p1,p2，作为深度优先遍历的起点，有四种路径可走，左右，右左，左左，右右，每种情况都是产生不同的结果，对每种情况计算的res进行比较，最大值即为所求
   
![前缀树.PNG](https://pic.leetcode-cn.com/d1010017a06d6aeec1e657aebf8bd51da3cfa49e978f5672b64f722133d91434-%E5%89%8D%E7%BC%80%E6%A0%91.PNG)

代码如下
```
struct TrieNode{
    TrieNode* left;
    TrieNode* right;
    TrieNode():left(NULL),right(NULL){}
};
class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root=new TrieNode();
        }
        void insert(vector<int> nums){
            for(int i=0;i<nums.size();i++){
                TrieNode* node=root;
                unsigned int p=0x80000000;//这里一定要用unsigned int才能做逻辑位移
                while(p){
                    if(p & nums[i]){
                        if(node->right==NULL)
                            node->right=new TrieNode();
                        node=node->right;
                    }else{
                        if(node->left==NULL)
                            node->left=new TrieNode();
                        node=node->left;
                    } 
                    p=p>>1;
                }
            }
        }
        int searchMax(){
            TrieNode* p=root;
            int res=0;
            while(!p->left || !p->right){
                if(p->left)
                    p=p->left;
                else if(p->right)
                    p=p->right;
                else 
                    break;
            }
            TrieNode* p1=p->left,*p2=p->right;
            if(p1 && p2){
                res=1;
                search(p1,p2,res);
                return res;
            }else
                return 0;
                
        }
    //p1 p2是某一树节点的左右子节点，res是目前遍历到left right这一树层是的最大值，求往下遍历res的最大值
        void search(TrieNode* p1,TrieNode* p2,int &res){
            //终止路径条件，到头了
            if(!p1->left && !p1->right && !p2->left && !p2->right)return ;
            //中间递归
            int r1=0,r2=0,r3=0;
            int temp=res;
            if(p1->left && p2->right){
                res=res<<1;res++;
                search(p1->left,p2->right,res);
                r1=res;
                res=temp;
            }
            if(p1->right && p2->left){
                res=res<<1;res++;
                search(p1->right,p2->left,res);
                r2=res;
                res=temp;
            }
            if(!((p1->left && p2->right) || (p1->right && p2->left))){
                if(p1->left && p2->left){
                    res=res<<1;
                    search(p1->left,p2->left,res);
                    r3=res;
                    res=temp;
                }
                if(p1->right && p2->right){
                    res=res<<1;
                    search(p1->right,p2->right,res);
                }
            }
            if(r1>res)res=r1;
            if(r2>res)res=r2;
            if(r3>res)res=r3;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if(nums.empty())return 0;
        Trie trie;
        trie.insert(nums);
        return trie.searchMax();
    }
};

```
![前缀树小.PNG](https://pic.leetcode-cn.com/2b8eb9cd30af2d65f30b9bb657417523b718d315c0e7efce0740014ac3f4b77f-%E5%89%8D%E7%BC%80%E6%A0%91%E5%B0%8F.PNG)
