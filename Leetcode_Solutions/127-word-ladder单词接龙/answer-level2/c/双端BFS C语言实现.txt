# 单词接龙

## 分析

单词接龙这道题可以看成是求图的连通性的题。为什么呢？可以参考题目的例子：

```c
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
```

我们可以根据这个来画图：

```mermaid
graph TD
hit --- hot
hot --- lot
dog --- dot
dog --- log
dot --- lot
log --- lot
log --- cog
dog --- cog
```

由图可知，我们可以根据每个单词间只能由一个字存在差异的条件画出一个连通图。而题目的意思就可以理解为由hit走到cog所需要的最小步数，已经步数对应经过的单词。

由图我们可以看出最小步数。

## 解法

我们知道，走图有两种走法，DFS\BFS。

DFS即深度优先搜索，俗称不撞南墙不回头，实现方式是用栈来保存选择，然后每次取栈顶元素，并且依据栈顶元素遍历，将符合条件的元素压栈，然后如此往复。

BFS即广度优先搜索，特征是层次遍历，利用队列来实现。每次取队列队首元素，遍历所有节点，将所有符合条件的元素入队。循环往复。

不管是DFS还是BFS，都需要一个状态标记来表示元素已经被选取，避免出现重复选择以及死循环。

从上面的分析，我们可以知道DFS是很适合去做连通性搜索测试，并且如果不需要找到最短路径的话，可以直接退出，不需要存储大量路径信息（C语言也可以用递归来做）；而BFS则是很适合去搜索==最短路径==，因为其会进行层次遍历，在任何一层发现了目标，那都是最短的路径上发现的。但是BFS会要求记录每一层的信息，会导致信息记录量大。（而且C语言没有队列，需要额外实现）

但是很明显，我们这道题就是需要用到BFS。也即根据beginWord来搜索所有与其相差仅为1个词语的单词，将其放入队列中，然后后循环搜索。不过要注意的是，存粹的BFS会超时，所以需要双端BFS，也就是从beginWord和endWord两端搜索。

## 双端BFS

依据名字，我们要从两端都搜索，也就需要两个队列来保存各自的搜索信息。我们记为begin_word_queue和end_word_queue，并且记为A和B。双端搜索的规则如下：

1. 每次选取A和B中最少元素的来进行出队操作。如果size相等，取A中元素。

2. 每次遍历到符合要求的元素，则进行入队操作，A搜索到的记为1， B搜索到的记为2。但是赋值方式为：

   ```c
   int selected_flag; //0 means A; 1 means B
   int flag = 0;
   flag |= selected_flag;
   ```

3. 当flag为3的时候代表A、B同时访问了一个节点，退出。

4. 记录访问层次的次数，返回此次数。层次次数初始值为1

为什么这么做呢？因为BFS是层次遍历，也就是金字塔型遍历，越往后，搜索到的节点越多，信息越庞大，导致搜索时间越长。==但是结束点又只有一个，所以数据量大就会超时==。

但是我们可以利用这个特点，在起始和结束的word之间都进行搜索，==这样可以充分利用信息，不再只有一个结束标志位了，只要任意一个搜索到的节点发现自己的flag变为了3，那么代表begin和word之间是连通的，此时搜索的层次就是最短路径==。

那么根据例子我们来看一下：

- begin_word:hit
- end_word:cog
- 初始化,begin_word入队A，end_word入队B，circle = 1

circle 2

```mermaid
 graph TB
 hit
 hit --- hot

```

- A size  = 1, data = hot
- B size = 1, data = cog
- select A

circle 3

```mermaid
graph TB
hot --- dot
hot --- lot
```

- A size = 2, data = dot, lot
- B size = 1, data = cog
- select B

circle 4

```mermaid
 graph TB
 cog --- dog
 cog --- log
```

- A size = 2, data = dot, lot
- B size = 2, data = dog, log

circle 5

```mermaid
graph TB
dot --finded--- dog
```

- circle = 5, dog flag = 3，finded

由此可知，双端BFS能够工作。不过要实现双端BFS，就需要先实现队列来存储。具体实现如下：

数据结构：

```c
int words_len;
#define MAX_WORD_LIST_SIZE 10000
#define MARK_ARRAY_SIZE (MAX_WORD_LIST_SIZE * sizeof(unsigned char))
#define QUEUE_ARRAY_SIZE (MAX_WORD_LIST_SIZE * sizeof(int))
#define QUEUE_LIST_SIZE 2
unsigned char mark[MAX_WORD_LIST_SIZE];

struct data {
  char *word_queue;
  int index;
};

struct queue {
  struct data data[QUEUE_ARRAY_SIZE];
  int word_queue_head;
  int word_queue_tail;
} word_queue_list[QUEUE_LIST_SIZE];
```

对应的队列操作：

```c
void init_queue() {

  for (int i = 0; i < QUEUE_LIST_SIZE; ++i) {
    word_queue_list[i].word_queue_head = -1;
    word_queue_list[i].word_queue_tail = 0;
  }

  memset(mark, 0, sizeof(unsigned char));
}

void insert_into_queue(int queue_list_flag, char *word, int index) {
  struct queue *queue = &word_queue_list[queue_list_flag];
  struct data *data = NULL;

  if (queue->word_queue_head == queue->word_queue_tail)
    return;
  if (queue->word_queue_head == -1)
    ++queue->word_queue_head;

  queue->data[queue->word_queue_tail].word_queue = word;
  queue->data[queue->word_queue_tail].index = index;

  queue->word_queue_tail = (queue->word_queue_tail + 1) % QUEUE_ARRAY_SIZE;
}

struct data *remove_from_queue(int queue_list_flag) {
  struct queue *queue = &word_queue_list[queue_list_flag];
  struct data *data = NULL;

  if (queue->word_queue_head == -1)
    return data;

  data = &queue->data[queue->word_queue_head];
  queue->word_queue_head = (queue->word_queue_head + 1) % QUEUE_ARRAY_SIZE;

  if (queue->word_queue_head == queue->word_queue_tail) {
    queue->word_queue_head = -1;
    queue->word_queue_tail = 0;
  }

  return data;
}

int list_size(int list_flag) {
  struct queue *queue = &word_queue_list[list_flag];
  return queue->word_queue_tail == 0 ? 0 : (queue->word_queue_tail + QUEUE_ARRAY_SIZE - queue->word_queue_head) %
         QUEUE_ARRAY_SIZE;
}

bool is_empty(int list_flag) {
  struct queue *queue = &word_queue_list[list_flag];
  return queue->word_queue_head == -1;
}
```

用数组来模拟队列，最重要的就是首尾指针的计算。

- 对于首尾指针，增加的时候要记得对队列长度取余
- 出栈就是取首指针数据
- 入队就是赋值到尾指针并且尾指针加一
- 当队列中没有元素时，让首指针为-1，尾指针为0。并且通过首指针是不是-1来判断是否为空。
- 队列元素的计算就是尾指针减首指针
- 两个队列由结构体数组表示，0是begin_word队列，1是end_word队列

数据结构构造好后我们还需要一个求两个单词是否连通的函数，如下：

```c
bool is_can_change(const char *begin_word, const char *charge_word) {
  bool is_find_deference = false;

  for (int i = 0; i < words_len; ++i) {
    if (begin_word[i] != charge_word[i]) {
      if (is_find_deference)
        return false;
      else
        is_find_deference = true;
    }
  }

  return is_find_deference;
}
```

- 如果两个单词相等，我们也返回false(对应情况是begin_word在词典中)
- 单词间只能有一个差异， 如果存在多个则返回false

之后就好办了，不过在搜索之前要进行一些特殊处理：

1. 如果end_word不在词典中，直接返回0，所以在搜索前可以先直接搜索end_word在不在，不在就退出了
2. 初始化队列
3. begin_word和end_word分别入队
4. 搜索，以层次遍历
5. begin_word和end_word都在list将mark置好

后面的实现就是双端BFS的内容了，直接看代码吧。
```c
int words_len;
int MIN_PATH = 0x7fffffff;
#define MAX_WORD_LIST_SIZE 10000
#define MARK_ARRAY_SIZE (MAX_WORD_LIST_SIZE * sizeof(unsigned char))
#define QUEUE_ARRAY_SIZE (MAX_WORD_LIST_SIZE * sizeof(int))
#define QUEUE_LIST_SIZE 2
unsigned char mark[MAX_WORD_LIST_SIZE];

struct data {
  char *word_queue;
  int index;
};

struct queue {
  struct data data[QUEUE_ARRAY_SIZE];
  int word_queue_head;
  int word_queue_tail;
} word_queue_list[QUEUE_LIST_SIZE];

void init_queue() {

  for (int i = 0; i < QUEUE_LIST_SIZE; ++i) {
    word_queue_list[i].word_queue_head = -1;
    word_queue_list[i].word_queue_tail = 0;
  }

  memset(mark, 0, sizeof(unsigned char));
}

void insert_into_queue(int queue_list_flag, char *word, int index) {
  struct queue *queue = &word_queue_list[queue_list_flag];
  struct data *data = NULL;

  if (queue->word_queue_head == queue->word_queue_tail)
    return;
  if (queue->word_queue_head == -1)
    ++queue->word_queue_head;

  queue->data[queue->word_queue_tail].word_queue = word;
  queue->data[queue->word_queue_tail].index = index;

  queue->word_queue_tail = (queue->word_queue_tail + 1) % QUEUE_ARRAY_SIZE;
}

struct data *remove_from_queue(int queue_list_flag) {
  struct queue *queue = &word_queue_list[queue_list_flag];
  struct data *data = NULL;

  if (queue->word_queue_head == -1)
    return data;

  data = &queue->data[queue->word_queue_head];
  queue->word_queue_head = (queue->word_queue_head + 1) % QUEUE_ARRAY_SIZE;

  if (queue->word_queue_head == queue->word_queue_tail) {
    queue->word_queue_head = -1;
    queue->word_queue_tail = 0;
  }

  return data;
}

int list_size(int list_flag) {
  struct queue *queue = &word_queue_list[list_flag];
  return queue->word_queue_tail == 0 ? 0 : (queue->word_queue_tail + QUEUE_ARRAY_SIZE - queue->word_queue_head) %
         QUEUE_ARRAY_SIZE;
}

bool is_empty(int list_flag) {
  struct queue *queue = &word_queue_list[list_flag];
  return queue->word_queue_head == -1;
}

bool is_can_change(const char *begin_word, const char *charge_word) {
  bool is_find_deference = false;

  for (int i = 0; i < words_len; ++i) {
    if (begin_word[i] != charge_word[i]) {
      if (is_find_deference)
        return false;
      else
        is_find_deference = true;
    }
  }

  return is_find_deference;
}

int open_search(char *beginWord, char *endWord, char **wordList,
                 int wordListSize, int begin_word_index,  int end_word_index) {

  int step = 1;
  struct data *temp;
  char *word_temp;
  int temp_index;
  int selected_index;
  int selected_flag;
  int begin_queue_size;
  int end_queue_size;
  int search_size;

  init_queue();
  insert_into_queue(0, beginWord, begin_word_index);
  insert_into_queue(1, endWord, end_word_index);
  if (begin_word_index >= 0)
    mark[begin_word_index] = 1;
  mark[end_word_index] = 2;

  for (; !is_empty(0) && !is_empty(1); ++step) {

    begin_queue_size = list_size(0);
    end_queue_size = list_size(1);

    if (begin_queue_size <= end_queue_size) {
      search_size = begin_queue_size;
      selected_index = 0;
    } else {
      search_size = end_queue_size;
      selected_index = 1;
    }

    selected_flag = 1 << selected_index;

    for (int j = 0; j < search_size; ++j) {
      temp = remove_from_queue(selected_index);
      word_temp = temp->word_queue;
      temp_index = temp->index;

      if (temp_index >= 0 && mark[temp_index] == 3)
        return step;

      for (int i = 0; i < wordListSize; ++i) {
        if (mark[i] != selected_flag && is_can_change(word_temp, wordList[i])) {
          if ((mark[i] | selected_flag) == 3) {
            //finded
            return ++step;
          }
          insert_into_queue(selected_index, wordList[i], i);
          mark[i] |= selected_flag;
        }
      }
    }
  }

  return 0;
}

int ladderLength(char *beginWord, char *endWord, char **wordList,
                 int wordListSize) {
  init_queue(wordListSize);
  bool is_in_list = false;
  words_len = strlen(beginWord);
  memset(mark, false, MARK_ARRAY_SIZE);
  MIN_PATH = 0x7fffffff;
  int end_word_index;
  int begin_word_index = -1;

  for (int i = 0; i < wordListSize; ++i) {
    if (strcmp(beginWord, wordList[i]) == 0)
      begin_word_index = i;
    if (strcmp(endWord, wordList[i]) == 0) {
      is_in_list = true;
      end_word_index = i;
      break;
    }
  }

  if (!is_in_list)
    return 0;

  return open_search(beginWord, endWord, wordList, wordListSize, begin_word_index, end_word_index);
}
```