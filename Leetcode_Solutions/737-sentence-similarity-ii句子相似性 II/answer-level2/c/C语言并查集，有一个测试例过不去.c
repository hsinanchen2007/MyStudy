#define MAX_SIZE 21
#define MAX_LENGTH 2001

struct WORD {
    char word[MAX_SIZE];
    int index;
    UT_hash_handle hh;
};
struct WORD* table = NULL;

bool CheckParam(char ** words1, int words1Size, char ** words2, int words2Size)
{
    if (words1 == NULL || words2 == NULL || words1Size != words2Size) {
        return false;
    }

    return true;
}

bool CheckIsMatch(char ** words1, char ** words2, int wordsSize)
{
    for (int i = 0; i < wordsSize; i++) {
        if (strcmp(words1[i], words2[2]) != 0) {
            return false;
        }
    }

    return true;
}

int FindRoot(int point, int* parent)
{
    while (point != parent[point]) {
        parent[point] = parent[parent[point]];
        point = parent[point];
    }

    return point;
}

void UnionRoot(int point1, int point2, int* parent)
{
    int root1 = FindRoot(point1, parent);
    int root2 = FindRoot(point2, parent);

    if (root1 < root2) {
        parent[root2] = root1;
    } else {
        parent[root1] = root2;
    }

    return;
}

void AddPairsToHash(char *** pairs, int pairsSize, int* parent)
{
    struct WORD* pnode = NULL;
    int current = 0;
    int point1 = 0;
    int point2 = 0;

    for (int i = 0; i < pairsSize; i++) {
        HASH_FIND_STR(table, pairs[i][0], pnode);
        if (pnode == NULL) {
            pnode = (struct WORD*)malloc(sizeof(struct WORD));
            strcpy(pnode->word, pairs[i][0]);
            pnode->index = ++current;
            parent[current] = current;
            HASH_ADD_STR(table, word, pnode);
        }
        point1 = pnode->index;
        
        HASH_FIND_STR(table, pairs[i][1], pnode);
        if (pnode == NULL) {
            pnode = (struct WORD*)malloc(sizeof(struct WORD));
            strcpy(pnode->word, pairs[i][1]);
            pnode->index = ++current;
            parent[current] = current;
            HASH_ADD_STR(table, word, pnode);
        }
        point2 = pnode->index;  
        
        UnionRoot(point1, point2, parent);
    }
}

bool CheckIsSimilar(char ** words1, char ** words2, int wordsSize, int* parent)
{
    struct WORD* pnode1 = NULL;
    struct WORD* pnode2 = NULL;

    for (int i = 0; i < wordsSize; i++) {
        HASH_FIND_STR(table, words1[i], pnode1);
        HASH_FIND_STR(table, words2[i], pnode2);
        //printf("p1 %s p2 %s\n",words1[i], words2[i]);
        if (pnode1 == NULL && pnode2 == NULL) {
            if (strcmp(words1[i], words2[i]) != 0) {
                printf("both NULL\n");
                return false;
            }
            continue; 
        }

        if (pnode1 == NULL || pnode2 == NULL) {
            return false;
        }

        if (parent[pnode1->index] != parent[pnode2->index]) {
            printf("p1 %s p2 %s\n",words1[i], words2[i]);
            printf("p1 %d p2 %d\n",parent[pnode1->index], parent[pnode2->index]);
            return false;
        }
    }

    return true;
}

bool areSentencesSimilarTwo(char ** words1, int words1Size, char ** words2, int words2Size, char *** pairs, int pairsSize, int* pairsColSize){
    int parent[MAX_LENGTH] = {0};    

    bool ans = CheckParam(words1, words1Size, words2, words2Size);
    if (ans == false) {
        return false;
    }

    if (pairsSize == 0) {
        return CheckIsMatch(words1, words2, words1Size);
    }

    AddPairsToHash(pairs, pairsSize, parent);
    struct WORD* pnode = NULL;
    struct WORD* ptemp = NULL;
    HASH_ITER(hh, table, pnode, ptemp) {
        printf("%s, index %d\n",pnode->word, pnode->index);
    }

    ans = CheckIsSimilar(words1, words2, words1Size, parent);

    HASH_ITER(hh, table, pnode, ptemp) {
        HASH_DEL(table, pnode);
        free(pnode);
    }

    return ans;
}

有测试例过不去，检查不出来，比较郁闷。