### 1. 前序

在看这道题的时候，我就想到了前段时间面试时，面试官问我的一个问题，应该面试常问的问题吧：**十亿个杂乱无章的数中找出前1000个最小的数**

1. 我当时先给出的回答是**分块处理**，例如一亿数据为一组，找出一组中的前1000个最小的数，然后再在10*1000个数据中找出前1000个最小的数。
2. 面试官问怎么找出一亿数据中的Top1000？我先回答说排序，用快排。
3. 面试官说复杂度有些高呀，可以优化么？我想了一下，只需要找出前1000个数，并不要求有序，排序肯定是不必要的，但总不能遍历1000次数组找每次的最小值吧。虽然不合理，但是避免冷场，我还是说出来了。
4. 面试官说，也算是一种方法，还可以优化么。我首先想到的是，设置1000大小的窗口，当每次来一个数的时候，判断它和窗口的上边界的大小再去插入，但是有一个问题就是这个数据如何插入。因为输出结果并不要求有序，所以需要一种数据结构**可以每次插入之后自动调整出最大值**
5. 呐，这不就是**最大堆**的性质么，然后我就哇啦哇啦的说了一堆，下面再介绍，也不知道面试官是否满意它也没说话。

**如果我的回答有哪里不对，记得指出呦~~**

### 2. 堆排序

本题需要用到最大堆，先来回忆一下：

+ **堆（Heap）** 是一个可以被看成近似**完全二叉树的数组**。树上的每一个结点对应数组的一个元素。除了最底层外，该树是完全充满的，而且是从左到右填充。
+ 最大堆的每一个节点（除了根结点）的值不大于其父节点。
+ **建堆：** 把一个乱序的数组变成堆结构的数组，时间复杂度为 O(n)。
+ **Push：** 把一个数值放进已经是堆结构的数组中，并保持堆结构，时间复杂度为 O(logn)。
+ **Pop：** 从最大堆中取出最大值或从最小堆中取出最小值，并将剩余的数组保持堆结构，时间复杂度为 O(logn)。


**建堆：**

首先我们要知道，堆是一个可以被看成近似完全二叉树的数组，所以我们可以根据父节点的索引知道子节点的索引；相反也可以从子节点得出父节点的索引
```cpp
left_index = parent_index * 2 + 1;
right_index = parent_index * 2 + 2;

parent_index = (left_index - 1) / 2;
parent_index = (right_index - 1) / 2;
```

然后我们要做的就是对这棵树进行**调整**：从最后一个非叶子节点开始到根节点，每个节点都依次做**下沉**操作

**下沉：**
+ 从当前父节点的左右孩子节点中选出较大的那一个；如果较大节点的值小于父节点，则跳出，否则将它的值赋值给父节点
+ 接着将父节点索引定位到上一步中选出的那个较大节点的位置
+ 不断下沉，直到当前节点不再有左节点（也就意味着没有右节点，即为叶子节点）

![初始](https://pic.leetcode-cn.com/8928131f272b1a9f95fa9abe144a5ffe975417d1aacde07cfe63868a424bfb07)

例如这一颗树：
+ 下沉的顺序为：12 -> 3 -> 2 -> 6
+ 先对12节点下沉；它的左右节点中较大的是18（不存在右节点），大于12；则将12这个节点的值赋值为18；原先的18节点没有左右节点，说明循环到底了，将12赋值给原先18这个节点。该节点下沉结束。

![1.](https://pic.leetcode-cn.com/e26ec965929ce11d38877e7393b02f3f56d74b5743cd2d5277927b1324f03059)

+ 接下来3节点，很容易看到3应该和8交换，下沉结束

![2.](https://pic.leetcode-cn.com/0546f8a80a60b0978289a12fb517edcbf9536284b356505db957d684562439fd)

+ 接下来2节点，18是较大节点，2和18交换；现在的2只有12节点，和12交换，下沉结束

![3.](https://pic.leetcode-cn.com/eb5ed66a821230f55bd61f219cb1cd25278453b1c4708449b4ad7ef9265fc5f1)

+ 最后是6根节点，6先和18交换；再和12交换；6的唯一子节点2小于6，结束

![4.](https://pic.leetcode-cn.com/efe4cd7707d061cc3ad4d2306dec825a46c102d0100b1ebb334fb146befcd38d)

### 3. 解题思路

对于这道题来书，只涉及到**建堆**和**Push**两个操作
+ 首先对arr数组的前k个数建堆
+ 然后从k开始对剩下的数组进行遍历，每个元素都和堆顶元素进行比较；
+ 如果当前元素比堆顶元素大，则不处理（我们是最大堆）；如果比当前元素小则将堆顶元素置换为当前元素，并调整堆


### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k == 0) return vector<int>();
        vector<int> max_heap_vec(arr.begin(), arr.begin()+k);
        buildMaxHeap(max_heap_vec);
        for(int i = k; i<arr.size(); ++i){
            // 出现比堆顶元素小的值, 置换堆顶元素, 并调整堆
            if(arr[i] < max_heap_vec[0]){
                emplacePeek(max_heap_vec, arr[i]);
            }
        }
        return max_heap_vec;
    }
private:
    void buildMaxHeap(vector<int>& v){
        // 所有非叶子节点从后往前依次下沉
        for(int i = (v.size()-2) / 2; i>=0; --i){
            downAdjust(v, i);
        }
    }

    void downAdjust(vector<int>& v, int index){
        int parent = v[index];
        // 左孩子节点索引
        int child_index = 2*index + 1;
        while(child_index < v.size()){
            // 判断是否存在右孩子, 并选出较大的节点
            if(child_index + 1 < v.size() && v[child_index+1] > v[child_index]){
                child_index += 1;
            }
            // 判断父节点和子节点的大小关系
            if(parent >= v[child_index]) break;
            // 较大节点上浮
            v[index] = v[child_index];
            index = child_index;
            child_index = 2*index + 1;
        }
        // 避免重复交换的无用工作
        v[index] = parent;
    }

    void emplacePeek(vector<int>& v, int val){
        v[0] = val;
        downAdjust(v, 0);
    }
};
```