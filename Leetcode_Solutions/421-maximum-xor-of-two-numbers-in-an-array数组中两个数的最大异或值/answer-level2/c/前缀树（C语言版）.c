### 解题思路
此处撰写解题思路

### 代码

```c
struct trie{
    struct trie *one;
    struct trie *zeros;
};

int findMaximumXOR(int* nums, int numsSize){
    struct trie root,*p,*temp;
    int current,ans=0;
    root.one = NULL;
    root.zeros = NULL;
    temp = NULL;
    for (int i=0;i<numsSize;i++){
        p = &root;
        for (int j=30;j>=0;j--){
            if (!temp){
                temp = (struct trie*)malloc(sizeof(struct trie));
                temp->one = NULL;
                temp->zeros = NULL;
            }//C语言为了不浪费内存，判断是否要新建一个节点
            if ((nums[i]&(1<<j))){
                if (!p->one)
                    p->one = temp;
                p = p->one;
            }//如果数字num[i]在该位上是1,对该节点进行判断:有one节点则指针直接转移到该节点,没有则创建一个one节点，再转移到节点上
            else{
                if (!p->zeros)
                    p->zeros = temp;
                p = p->zeros;
            }//对于zeros节点同one节点
            temp = NULL;
        }
    }
    //用nums中的每一个数去进行最大异或运算(结果保存到current中),如果current>ans,那么替换
    for (int i=0;i<numsSize;i++){
        current = 0;
        p = &root;
        for (int j=30;j>=0;j--){
            if (p->one && p->zeros){
                if ((nums[i]&(1<<j))){
                    current += (1<<j);
                    p = p->zeros;
                }
                else{
                    current += (1<<j);
                    p = p->one;
                }
            }//如果节点既有one节点又有zeros节点，那么我们看nums[i]数在该位中是否有1，有的话我们选取该节点的zeros子节点，并且我们让current加上该位的值;没有的(该位是0)话我们选取该节点的one子节点,并且还要让current加上该位的值
            else{
                if (p->one){
                    if (!(nums[i]&(1<<j)))
                        current += (1<<j);
                    p = p->one;
                }
                else{
                    if (nums[i]&(1<<j))
                        current += (1<<j);
                    p = p->zeros;
                }//对于节点仅有一个子节点的情况，我们根据子节点的种类(one还是zeros)和nums[i]在该位是否为1来判断current是否要加上该位的值,只有当1->zeros,0->one时候才能够加
            }
        }
        if (current>ans)
            ans = current;
    }
    return ans;
}
```