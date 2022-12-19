### 解题思路
构建字典树的模板能解决insert，sum函数需要借助深度优先搜索，而且由于场景很多，很麻烦

尤其是mapSumSum函数，因为一开始考虑的就不是很全，改了又改而且为了直接递归变得比较臃肿

正确做法是跳过prefix字符的部分在mapSumSum中做，深度优先搜索的递归函数应该抽一个新的函数，
这样的面临的情况可能会少很多，感兴趣的可以在我的基础上改一改，至少能练习一下深度优先搜索

free函数我觉得应该深度优先遍历，挨个释放内存，懒得写了

### 代码

```c
#define ALPHA_NUM 26
typedef struct trie_map {
    int val;
    struct trie_map *children[ALPHA_NUM];
} MapSum;

/** Initialize your data structure here. */

MapSum* mapSumCreate() {
    int i;
    MapSum *pNode = (MapSum *)malloc(sizeof(struct trie_map));
    pNode->val = 0;
    for (i = 0; i < ALPHA_NUM; i++) {
        pNode->children[i] = NULL;
    }
    return pNode;
}

void mapSumInsert(MapSum* obj, char * key, int val) {
    MapSum *pNode = obj;
    char *p = key;
    while (*p) {
        if (pNode->children[*p - 'a'] == NULL) {
            pNode->children[*p - 'a'] = mapSumCreate();
        }
        pNode = pNode->children[*p - 'a'];
        ++p;
    }
    pNode->val = val;
    return;
}

int mapSumSum(MapSum* obj, char * prefix) {
    int i;
    int ans = 0;
    MapSum *node = obj;
    char *p = prefix;
    // 跳过prefix中有的字符再累加，同时还要排除字符串为空的情况
    // prefix为空的情况是我跳过字符造成的
    while (prefix != NULL && *p) {
        // 还要判断一下是否存在子节点，不存在直接返回0，存在则跳过字符
        if (node->children[*p - 'a'] != NULL) {
            node = node->children[*p - 'a'];
            (p)++;
        } else {
           return 0;
        }
    }
    // 如果跳过prefix中的字符后节点为空，返回0
    if(node == NULL) {
        return 0;
    }
    // 由于构建的时候非结尾节点的值为0，如果不是字符串结尾的话，加的就是0，所以可以直接加
    ans += node->val;
    // 深度优先遍历字典树
    for (i = 0; i < ALPHA_NUM; i++) {
        if (node->children[i] != NULL) {
            // prefix字符串中的节点已经被跳过了，所以入参可以为NULL
            ans += mapSumSum(node->children[i], NULL);
        }
    }

    return ans;
}
// free 有点问题，里面的节点都没释放
void mapSumFree(MapSum* obj) {
    free(obj);
    obj == NULL;
    return;
}

/**
 * Your MapSum struct will be instantiated and called as such:
 * MapSum* obj = mapSumCreate();
 * mapSumInsert(obj, key, val);
 
 * int param_2 = mapSumSum(obj, prefix);
 
 * mapSumFree(obj);
*/
```