#define CHILD_COUNT 26

struct node {
    int times;
    struct node* childNode[CHILD_COUNT];//每个节点下面可能有26种字符作为子节点
};

struct node g_root;

struct node* insertNode(struct node* curNode,char c) {
    if ( curNode->childNode[c-'a'] == NULL) {
        //没有子节点，创建子节点
        curNode->childNode[c-'a'] = (struct node*)malloc(sizeof(struct node));
        memset(curNode->childNode[c - 'a'], 0, sizeof(struct node));
    } else {
        //如果已有子节点，说明和之前的单词中的字符是重复了，将该子节点被访问次数加1
        curNode->childNode[c-'a']->times++; 
    }
  
    //将当前节点重新置为当前节点的子节点，用于后面继续遍历单词的下个字符。
    curNode = curNode->childNode[c-'a'];
 
    return curNode;
}

void freeNode(struct node* curNode) {
    if (curNode == NULL) {
        return;
    }

    for(int i = 0; i < CHILD_COUNT; i++) {
        if( curNode->childNode[i] != NULL) {
            freeNode(curNode->childNode[i]);
        } 
    }

    if (curNode != &g_root) {
        free(curNode);
    }
}

int minimumLengthEncoding(char ** words, int wordsSize){
    int result = 0;
    memset(&g_root, 0, sizeof(struct node));

    struct node** head = (struct node**)malloc(sizeof(struct node*) * wordsSize);
    for (int k = 0; k < wordsSize; k++) {
        head[k] = NULL;
    }

    struct node* curNode = NULL;
    //1、构建这样的字典树，同时用head指针数组保存每个单词在这个树中的首字母节点。
    for (int i = 0; i < wordsSize; i++) {
        curNode = &g_root;
        int wordLen = strlen(words[i]);

        for (int j = wordLen -1; j >=0; j--) {
            curNode = insertNode(curNode,words[i][j]);
        }

        //这里要保存最后一个节点，也就是代表这个单词的第一个字母的node
        head[i] = curNode;
        
        //这里是处理有重复单词的情况，如果该单词首字母的节点没有子节点，说明他不是别人的子串，如果times大于0，说明与之前的字符串重复了。
        //那么需要将之前单词的首字母节点的times减一，然后将当前单词首字母节点head置为NULL,这样在下面第三步统计的时候，就会跳过统计该单词。
        if (head[i]->childNode[words[i][0] - 'a'] == NULL && head[i]->times > 0) {
            head[i]->times = head[i]->times - 1;
            head[i] = NULL;
        }
    }

    //2、根据所有的head节点,如果该head节点只被访问过一次，说明他不是别人的子串，需要计算到最终长度里面；如果大于0，说明是子串，不用计算长度。
    for (int j = 0; j < wordsSize; j++) {
        if (head[j] != NULL && head[j]->times == 0) {
            result += strlen(words[j]) + 1;
        }
    }

    //3、释放内存
    freeNode(&g_root);

    return result;
}