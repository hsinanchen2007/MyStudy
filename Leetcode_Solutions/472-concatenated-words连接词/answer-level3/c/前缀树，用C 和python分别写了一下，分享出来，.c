C语言实现

```

#define MAX_WORD_NUM 10000

typedef struct WordNode{
    char c;
    bool wordFlag;
    struct WordNode *neighborCharList;
    struct WordNode *childCharList;
}WordNodeStru;

int cmpWord(const void *word1,const void *word2)
{
    return strlen((*(char **)word1)) - strlen((*(char **)word2));
}

void initTree(WordNodeStru *treeHead) {
    memset(treeHead, 0, sizeof(WordNodeStru));
}
void freeTree(WordNodeStru *treeHead) {
    WordNodeStru *curNode = treeHead->childCharList;
    WordNodeStru *freeNode;
    while (curNode != NULL) {
        freeNode = curNode;
        curNode = curNode->neighborCharList;
        freeTree(freeNode);
        free(freeNode);
    }
}

bool isNeedWord(char *word, WordNodeStru *treeHead) {
    int i = 0;
    WordNodeStru *curNode = treeHead->childCharList;
    
    while (curNode != NULL) {
        if (curNode->c == word[i]) {
			if ((curNode->wordFlag == true) && 
				((i+1 == strlen(word)) || isNeedWord(word+i+1,treeHead))) {
                return true;
			}
			curNode = curNode->childCharList;
			i++;
        } else {
			curNode = curNode->neighborCharList;
		}
    }
    return false;
}
void addToWordTree(char *word, WordNodeStru *treeHead) {
    int i = 0;
    WordNodeStru *curNode = treeHead->childCharList;
    WordNodeStru *newNode;
    WordNodeStru *preNeighborNode = NULL;
    WordNodeStru *preParentNode = treeHead;
    int wordLen = strlen(word);
    
    while (curNode != NULL) {
        if (curNode->c == word[i]) {
            i++;
            preParentNode = curNode;
            preNeighborNode = NULL;
            curNode = curNode->childCharList;            
        } else {
            preNeighborNode = curNode;
            curNode = curNode->neighborCharList;
        }
    }
    while (i < wordLen) {
        newNode = (WordNodeStru *)malloc(sizeof(WordNodeStru));
        if (newNode == NULL) {
            return;
        }
        newNode->c = word[i];
        newNode->wordFlag = (i+1 == wordLen);
        newNode->neighborCharList = NULL;
        newNode->childCharList = NULL;
        if (preNeighborNode != NULL) {
            preNeighborNode->neighborCharList = newNode;
            preParentNode = newNode;
            preNeighborNode = NULL;
        }
        else {
            preParentNode->childCharList = newNode;
            preParentNode = newNode;
        }
        i++;
    }   
}

char ** findAllConcatenatedWordsInADict(char ** words, int wordsSize, int* returnSize){
    int i;
    char **result;
    WordNodeStru treeHead;
    
    //返回结果个数初始化
    (*returnSize) = 0;
    if (wordsSize == 0) {
        return NULL;
    }   
    
    //返回结果内存分配
    result = (char **)malloc(wordsSize * sizeof(char *));
    if (result == NULL) {
        return NULL;
    }
    
    qsort(words, wordsSize, sizeof(char *), cmpWord);
    
    initTree(&treeHead);
    
    for (i = 0; i < wordsSize; i++) {
		if (strlen(words[i]) == 0) {
            continue;
        }
		if (isNeedWord(words[i], &treeHead)) {
            //满足条件，加入返回结果
            result[(*returnSize)] = words[i];
            (*returnSize)++;
        }
        //插入字典树
        addToWordTree(words[i], &treeHead);
    }
    //释放内存
    freeTree(&treeHead);
    return result;
}

```
Python3实现

```

class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        def getInTreeList(word: str, tree):
            result = []
            for i, c in enumerate(word):
                for node in tree:
                    if (c == node[0]):
                        if (node[1] == 1):
                            result.append(i)
                        tree = node[2]
                        break
                else:
                    return result
            return result
        def isWordFullCond(word: str, tree):
            indexList = getInTreeList(word, tree)
            if (indexList) and (indexList[-1]+1 == len(word)):
                return True
            for index in indexList:
                if (isWordFullCond(word[index+1:],tree)):
                    return True
            return False
        def addWordToTree(word: str, tree):
            currIndex = 0
            for i, c in enumerate(word):
                for node in tree:
                    if (c == node[0]):
                        tree = node[2]
                        break
                else:
                    currIndex = i
                    break
            for c in word[currIndex:-1]:
                tree.append([c,0,[]])
                tree = tree[-1][2]
            tree.append([word[-1],1,[]])
            
        result = []
        tree = []
        words = sorted(words,key=lambda i:len(i))
        for word in words:
            if (len(word) == 0):
                continue
            if (isWordFullCond(word, tree)):
                result.append(word)
            addWordToTree(word, tree)        
        return result
```


