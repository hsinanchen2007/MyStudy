#define MAX_QUEUE_SIZE 1000

bool visited[MAX_QUEUE_SIZE] = {false};

typedef struct node {
char *word;
int level;
} Node;

typedef struct Que {
Node data[MAX_QUEUE_SIZE];
int head;
int tail;
} QueUe;

void InitQue(QueUe *que)
{
que->head = -1;
que->tail = 0;
memset(que->data, 0, sizeof(Node) * MAX_QUEUE_SIZE);
}
//入队的时候，当head == tail，说明队列满
void Inque(QueUe *que, char *word, int idx)
{
if (que->head == que->tail) { // 入队时先判断队列是否满
return ;
}

if (que->head == -1) { // 空队列时，将head置0
    que->head = 0;
}

que->data[que->tail].word = word;
que->data[que->tail].level = idx;
que->tail = (que->tail + 1) % MAX_QUEUE_SIZE;
}

Node *Outque(QueUe *que)
{
if (que->head == -1) { // 出队时先判断队列是否空
return NULL;
}

Node *temp = &(que->data[que->head]);
que->head = (que->head + 1) % MAX_QUEUE_SIZE;
if (que->head == que->tail) { // 出队的时候，如果head==tail，说明队列为空，此时将head置-1
    que->head = -1;
    que->tail = 0;
}

return temp;
}

int QueSize(QueUe *que)
{
if ((que->tail == 0) && (que->head == -1)) { // 队列为空
return 0;
}

return (que->tail + MAX_QUEUE_SIZE - que->head) % MAX_QUEUE_SIZE;
}

bool is_empty(QueUe *que) {
if ((que->tail == 0) && (que->head == -1)) { // 队列为空
return true;
}
return false;
}

QueUe g_que;

bool ifFindDifWord(char *srcWord, char *destWord, int wordLen)
{
int i;
bool ismatched = false;
for (i = 0; i < wordLen; i++) {
if (srcWord[i] != destWord[i]) {
if (ismatched) { // 如果两个单词中有两个字母不一样，则单词不满足只有一个字母不一样的要求，返回false
return false;
}
ismatched = true;
}
}

return ismatched;
}

int WordNeighborInQue(QueUe *que, Node * node, char * endWord, char ** wordList, int wordListSize, int wordLen)
{
int i;
bool ifDiffWord = false;
char *srcWord = node->word;
int srclevel = node->level;

for (i = 0; i < wordListSize; i++) {
if (strcmp(wordList[i], srcWord) == 0) {
continue;
} else {
if (visited[i] == true) {
continue;
}
        // 遍历字典，把srcword相邻的单词都加入到队列里
        ifDiffWord = ifFindDifWord(srcWord, wordList[i], wordLen);
        if (ifDiffWord == true) {
            if (strcmp(endWord, wordList[i]) == 0) {
                return srclevel + 1;
            }
            Inque(que, wordList[i], srclevel + 1);
            visited[i] = true;
        }
    }
}

return 0;// 表示node->word的邻居都不是目的单词
}

int GetLength(QueUe *que, char * beginWord, char * endWord, char ** wordList, int wordListSize, int beginWordIdx)
{
// 将visited【beginwordIdx】置1
if (beginWordIdx != -1) {
visited[beginWordIdx] = true;
}
int wordLen = strlen(beginWord);

int ret = 0;
//beginword加入队列里
Inque(que, beginWord, 1);

while(is_empty(que) != true) {
    Node *strTemp = Outque(que);
    ret = WordNeighborInQue(que, strTemp, endWord, wordList, wordListSize, wordLen);
    if (ret != 0) {
        return ret;
    }
}

return 0;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
if (wordList == NULL) {
return 0;
}

int i;
int ret;
for (i = 0; i < wordListSize; i++) {
    ret = strcmp(wordList[i], endWord);
    if (ret == 0) {
        break;
    }
}

if (i == wordListSize) { // 字典中不存在endword
    return 0;
}

int beginWordIdx = -1;
for (i = 0; i < wordListSize; i++) {
    ret = strcmp(wordList[i], beginWord);
    if (ret == 0) {
        break;
    }
}

if (i != wordListSize) { // 字典中存在beginword
    beginWordIdx = i;
}

InitQue(&g_que);
return GetLength(&g_que, beginWord, endWord, wordList, wordListSize, beginWordIdx);
}